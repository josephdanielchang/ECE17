//
//  MadlibAutoWordProvider.hpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef MadlibAutoWordProvider_hpp
#define MadlibAutoWordProvider_hpp

#include "MadlibWordProvider.hpp"

// Subclass of MadlibWordProvider
class MadlibAutoWordProvider : public MadlibWordProvider {
public:
    // OCF
    MadlibAutoWordProvider();                                                                     // Default constructor
    MadlibAutoWordProvider(const MadlibAutoWordProvider &aMadlibAutoWordProvider);                // Copy Constructor
    MadlibAutoWordProvider& operator=(const MadlibAutoWordProvider &aMadlibAutoWordProvider);     // Assignment Operator
    ~MadlibAutoWordProvider() override;                                                           // Destructor

    // Methods
    std::string getSubstituteWord(WordType aType) override; // return generated word for a word type
    bool readJSON(const char *jsonPath);                    // fills word_list with struct starter words from json file

protected:
    // Data Members
    struct WORD{
        std::string word;
        std::string pos;
        std::string category;
    };
    std::vector<WORD> word_list;
};



#endif /* MadlibAutoWordProvider_hpp */
