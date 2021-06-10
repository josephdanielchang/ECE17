//
//  main.cpp
//  assignment2
//
//  Created by vikash gilja on 4/10/20.
//

#include "Game.hpp"

//----------------------------------------------

int main(int argc, const char * argv[]) {

    Game theGame("Bob", "Alice");

    theGame.PrintScoreboard();
    for (int i = 0; i < 10; i++)
    {
        theGame.PlayRound();
        theGame.PrintScoreboard();
    }

    return 0;
}
