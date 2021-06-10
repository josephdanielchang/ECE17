//
//  MadlibWordProvider.hpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef MadlibWordProvider_hpp
#define MadlibWordProvider_hpp

#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

// Enum determining types of words we can interact with
enum class WordType {invalid, noun, pluralnoun, name, verb, adjective,
                     adverb, number, color, fruit, animal, place};

// Hash map pairing WordTypes with strings
static std::map<WordType, std::string> gLabels = {
  std::make_pair(WordType::noun, "noun"),
  std::make_pair(WordType::pluralnoun, "pluralnoun"),
  std::make_pair(WordType::name, "name"),
  std::make_pair(WordType::verb, "verb"),
  std::make_pair(WordType::adjective, "adjective"),
  std::make_pair(WordType::adverb, "adverb"),
  std::make_pair(WordType::number, "number"),
  std::make_pair(WordType::color, "color"),
  std::make_pair(WordType::fruit, "fruit"),
  std::make_pair(WordType::animal, "animal"),
  std::make_pair(WordType::place, "place")
};

class MadlibWordProvider {
public:
    // OCF
    MadlibWordProvider() = default;               // Default constructor
    virtual ~MadlibWordProvider() = default;      // Destructor

    // Methods
    virtual std::string getSubstituteWord(WordType aType)=0; // get word of particular type (noun, verb, etc.)

    static WordType getTypeForLabel(std::string &aWord) {                     // convert string to WordType
        std::transform(aWord.begin(), aWord.end(), aWord.begin(), ::tolower); // convert caps to lowercase
        for(auto thePair : gLabels) {
            if(thePair.second==aWord) {
                return thePair.first;
            }
        }
        return WordType::invalid;
    }

    static std::string getLabelForType(WordType aType) {    // pass in a WordType and return representative label
        return gLabels[aType];
    }
};

#endif /* MadlibWordProvider_hpp */
