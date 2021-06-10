//
//  Game.hpp
//  assignment2
//

#ifndef Game_hpp
#define Game_hpp

#include "Card.hpp"
#include "Player.hpp"
#include "Hand.hpp"
#include "Deck.hpp"

// Contains one Deck object and two Player objects
// Initialize deck and player names, call method each round so each player
// gets card from top of deck (player 1 then 2), scores updated
class Game {
public:
    // Data Members
    Deck gameDeck; 
    Player player1, player2;
    int roundNumber;

    // OCF
    explicit Game(const char * player1_name="Player 1", const char * player2_name="Player 2", bool shuffle_deck = false);      // Default Constructor
    Game(const Game &Game);                                                                                                    // Copy Constructor
    Game &operator=(const Game &Game);                                                                                         // Assignment Operator
    ~Game();                                                                                                                   // Destructor

    // Methods
    bool PlayRound();                        // play a round for each player, return false if round cannot be completed
    void PrintScoreboard();                  // prints how many rounds have been played and player scores listed by name
};


#endif /* Game_hpp */
