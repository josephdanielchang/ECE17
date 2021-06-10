//
//  MadlibAutoWordProvider.cpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include "MadlibAutoWordProvider.hpp"

// Default Constructor
MadlibAutoWordProvider::MadlibAutoWordProvider() : MadlibWordProvider() {
    readJSON("words.json");
}
// Copy Constructor
MadlibAutoWordProvider::MadlibAutoWordProvider(const MadlibAutoWordProvider &aMadlibAutoWordProvider) {}
// Assignment Operator
MadlibAutoWordProvider &MadlibAutoWordProvider::operator=(const MadlibAutoWordProvider &aMadlibAutoWordProvider) {}
// Destructor
MadlibAutoWordProvider::~MadlibAutoWordProvider() = default;

// Methods
std::string MadlibAutoWordProvider::getSubstituteWord(WordType aType) {
    int size = word_list.size();
    int randomIndex;
    std::string type = getLabelForType(aType);
    std::string generatedWord;

    // Find generated word with same category
    if (type == "pluralnoun") {                 // special case of plural nouns
        do {
            randomIndex = (rand() % size) - 1;
        } while (word_list[randomIndex].pos != "noun");
        generatedWord = word_list[randomIndex].word + "s";
    }
    else {                                      // regular word types
        do {
            randomIndex = (rand() % size) - 1;
        } while (word_list[randomIndex].pos != type && word_list[randomIndex].category != type);
        generatedWord = word_list[randomIndex].word;
    }
    return generatedWord;
}

bool MadlibAutoWordProvider::readJSON(const char *jsonPath) {
    std::ifstream f;
    f.open(jsonPath);
    
    if(!f.is_open()) {
        std::cout << "Error opening JSON file!" << std::endl;
        return false;
    }
    
    std::string line, word, first_split;
    while (!f.eof()) {
        WORD curr_line;
        while (line.length() <= 4) {
            std::getline(f, line);
            if(f.eof()){
                break;
            }
        }
        if (line.find("\"WORD\"") != std::string::npos) {
            first_split = line.substr(line.find(":"), line.find("\","));
            word = first_split.substr(first_split.find("\"")+1, first_split.find("\",")-3);
            curr_line.word = word;
            std::getline(f, line);
        }
        if(line.find("\"POS\"") != std::string::npos){
            first_split = line.substr(line.find(":"), line.find(","));
            word = first_split.substr(first_split.find("\"")+1, first_split.find("\",")-3);
            curr_line.pos = word;
            std::getline(f, line);
        }
        if(line.find("\"CATEGORY\"") != std::string::npos){
            first_split = line.substr(line.find(":"), line.find(","));
            if(first_split.compare(": \"\"") != 0) {
                word = first_split.substr(first_split.find("\"")+1, first_split.find_last_of("\"")-3);
                curr_line.category = word;
            }
            std::getline(f, line);
        }
        word_list.push_back(curr_line);
    }
    return true;
}
