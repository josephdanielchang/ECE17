//
//  MadlibUserWordProvider.hpp
//  Assignment3
//
//  Created by rick gessner on 4/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef MadlibUserWordProvider_hpp
#define MadlibUserWordProvider_hpp

#include <cstdio>
#include "MadlibWordProvider.hpp"

// Subclass of MadlibWordProvider
class MadlibUserWordProvider : public MadlibWordProvider {
public:
    // OCF
    MadlibUserWordProvider();                                                                     // Default constructor
    MadlibUserWordProvider(const MadlibUserWordProvider &aMadlibUserWordProvider);                // Copy Constructor
    MadlibUserWordProvider& operator=(const MadlibUserWordProvider &aMadlibUserWordProvider);     // Assignment Operator
    ~MadlibUserWordProvider() override;                                                           // Destructor

    // Methods
    virtual std::string getSubstituteWord(WordType aType); // ask user for word and return word
};

#endif /* MadlibUserWordProvider_hpp */
