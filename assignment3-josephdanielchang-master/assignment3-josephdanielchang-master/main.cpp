//
//  main.cpp
//  ECE17 Assignment3
//
//  Created by rick gessner on 8/15/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include <iostream>
#include "MadLibsController.hpp"
#include "MadlibUserWordProvider.hpp"
#include "MadlibAutoWordProvider.hpp"

std::ostream& getOutput() {
  return std::cout;  // can change this for debugging, but change it back for testing
}

// This is where we do basic madlibs (with user input)
// Complete the following code, and handle memory too!
void testUserMadlibs(const char *aPath, std::ostream &anOutput) {
    MadlibWordProvider *theProvider = new MadlibUserWordProvider;   // make user provider on heap
    MadLibsController *theController = new MadLibsController;       // make controller on heap
    theController->runStory(aPath, *theProvider, anOutput);
    delete theProvider;
    delete theController;
}

// This is where we do auto-madlibs (chatbot answers via objects)
// Complete the following code, and handle memory too!
void testAutoMadlibs(const char *aPath, std::ostream &anOutput) {
    MadlibWordProvider *theProvider = new MadlibAutoWordProvider;   // make AUTO provider on heap
    MadLibsController *theController = new MadLibsController;       // make controller on heap
    theController->runStory(aPath, *theProvider, anOutput);
    delete theProvider;
    delete theController;
}

//------------------------------------------------------------------

const char* getPath() {
  return "madlibs1.txt"; // full path to madlibs1.txt
}

int main(int argc, const char * argv[]) {
    //std::srand((unsigned int)std::time(nullptr));//random # seed
    testUserMadlibs(getPath(), getOutput());
    testAutoMadlibs(getPath(), getOutput());
  
    return 0;
}
