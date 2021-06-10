//
//  MadLibsController.hpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef MadLibsController_hpp
#define MadLibsController_hpp

#include <cstdio>
#include <iostream>
#include <vector>
#include "MadlibWordProvider.hpp"

class MadLibsController {
public:
    // OCF
    MadLibsController();                                                           // Default constructor
    MadLibsController(const MadLibsController &aMadLibsController);                // Copy Constructor
    MadLibsController& operator=(const MadLibsController &aMadLibsController);     // Assignment Operator
    ~MadLibsController();                                                          // Destructor

    // Methods
    bool  runStory(const char *aFilename, MadlibWordProvider &aProvider, std::ostream &anOutput); // iterate and find all capitalized words
    bool  readFile(const char *aFilename);                  // read madlib template file
    void  getSubstitutes(MadlibWordProvider &aProvider);    // get substitute words of given type for each capitalized word
    void  showFinishedStory(std::ostream &anOutput);        // print final story with substituted words
    std::vector<std::string> getWords();                    // return protected member words

protected:
    // Data Members
    std::vector<std::string> words;     // words collected from user or auto word generator
    std::vector<std::string> allWords;  // all words from file
    std::vector<std::string> capWords;  // all caps words from file
    std::vector<std::string> noPunct;   // all caps words without punctuation from file
    std::vector<int> capIndex;          // word index of all caps words in file
    std::string wordTypes[11] = {"noun", "pluralnoun", "name", "verb", "adjective",
                                 "adverb", "number", "color", "fruit", "animal", "place"};
};

#endif /* MadLibsController_hpp */
