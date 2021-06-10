//
//  MadlibUserWordProvider.cpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include "MadlibUserWordProvider.hpp"
#include <iostream>

// Default Constructor
MadlibUserWordProvider::MadlibUserWordProvider() : MadlibWordProvider() {}
// Copy Constructor
MadlibUserWordProvider::MadlibUserWordProvider(const MadlibUserWordProvider &aMadlibUserWordProvider) {}
// Assignment Operator
MadlibUserWordProvider &MadlibUserWordProvider::operator=(const MadlibUserWordProvider &aMadlibUserWordProvider) {}
// Destructor
MadlibUserWordProvider::~MadlibUserWordProvider() = default;

// Methods
std::string MadlibUserWordProvider::getSubstituteWord(WordType aType) {
    std::string userWord;
    std::cout << "Please enter a/an " << getLabelForType(aType)  << ":\n";
    std::cin >> userWord;
    if (userWord != "\n")
        return userWord;
    else
        return std::string("Where is my word?\n");
}
