//
//  MadLibsController.cpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include "MadLibsController.hpp"
#include "MadlibAutoWordProvider.hpp"
#include "MadlibUserWordProvider.hpp"
#include <fstream>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string.h>

// Default Constructor
MadLibsController::MadLibsController() = default;
// Copy Constructor
MadLibsController::MadLibsController(const MadLibsController &aMadLibsController) {}
// Assignment Operator
MadLibsController &MadLibsController::operator=(const MadLibsController &aMadLibsController) {}
// Destructor
MadLibsController::~MadLibsController() = default;

// Methods
void MadLibsController::getSubstitutes(MadlibWordProvider &aProvider) {
    // Get substitute words from provider (user or auto word generator)
    for(std::string i : noPunct) {
        WordType type = MadlibWordProvider::getTypeForLabel(i);
        std::string output = aProvider.getSubstituteWord(type);
        words.push_back(output);
    }
}

std::vector<std::string> MadLibsController::getWords() {
    return words;
}

bool isPunct(char aChar) {
  static std::string punct(".;?!:,'-");          // newlines are not removed
  return std::string::npos != punct.find(aChar);    // npos is last char in string
}

void MadLibsController::showFinishedStory(std::ostream &anOutput) {\
    anOutput << "Your madlib is:" << std::endl;
    int subIndex = 0;
    int foundIndex;

    for (int i = 0; i < allWords.size(); i++) {
        if (allWords[i] == capWords[subIndex]) {              // there is all caps word
            foundIndex = allWords[i].find(noPunct[subIndex]);
            allWords[i].replace(foundIndex, foundIndex+strlen(noPunct[subIndex].c_str()), words[subIndex]);
            subIndex++;
        }
        std::cout << allWords[i] << " ";
    }
}

bool MadLibsController::readFile(const char *aPath) {

    // Read file
    int line = 0;                                       // tracks current line
    std::ifstream file(aPath);
    if (file.is_open()) {
        std::string aLine;
        while (std::getline(file, aLine)) {       // stream lines of file
            std::istringstream theInput(aLine.c_str());    // stream words of line
            std::string aWord;
            while (!theInput.eof()) {                   // not end of line
                theInput >> aWord;                      // read word from stream
                allWords.push_back(aWord);              // add string to vector
                line++;
                theInput >> std::ws;
            }
            allWords.push_back("\n");
        }
        file.close();
    }
    else {
        std::cout << "Unable to open file to read" << std::endl;
        return false;
    }

    // Extract all caps words
    bool allUpper;
    int wordIndex = 0;
    for (const std::string& i : allWords) {
        if (i != "--" && !i.empty()) {
            allUpper = true;
            for (char c : i) {                  // check if every char is uppercase
                if (isupper(c) || isPunct(c))
                    continue;
                else
                    allUpper = false;
                break;
            }
            if (allUpper && i.size() > 1) {     // make sure it's not A or I
                capWords.push_back(i);
                capIndex.push_back(wordIndex);
            }
            wordIndex++;
        }
    }

    // Remove punctuations
    noPunct = capWords;
    char charIndex;
    bool recheck;                   // true if check word again for more punctuation
    bool punctGone;                 // true if no punctuation left
    for (std::string& i : noPunct) {
        recheck = true;
        while (recheck) {
            punctGone = true;
            charIndex = 0;
            for (char c : i) {
                if (isPunct(c)) {
                    i.erase(charIndex, 1);
                    punctGone = false;
                }
                charIndex++;
            }
            if (punctGone) {
                recheck = false;
            }
        }
    }
    return true;
}

bool MadLibsController::runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput) {
    if(readFile(aFilename)) {
        getSubstitutes(aProvider);       //get replacement for each CAPITALIZED word (substitutes)
        std::cout << "\n";
        showFinishedStory(anOutput);
        return true;
    }
    return false;
}