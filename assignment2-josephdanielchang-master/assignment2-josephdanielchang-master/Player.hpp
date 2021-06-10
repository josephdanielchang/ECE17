//
//  Player.hpp
//  assignment2
//

#ifndef Player_hpp
#define Player_hpp

#include "Card.hpp"
#include "Hand.hpp"

// Tracks each player of the game including Card objects held in the Hand, current score, and points
class Player {
public:
    // Data Members
    Hand hand;

    // OCF
    Player() {                                      // Default Constructor
        name = "No Name";
        score = 0;
    };

    explicit Player(const char *name) {             // Default Constructor
        this-> name = name;
        score = 0;
    };

    Player(const Player &Player);                   // Copy Constructor
    Player &operator=(const Player &Player);        // Assignment Operator
    ~Player();                                      // Destructor

    // Methods
    std::string GetName();                          // Get player name
    void SetName(const char* name);                 // Set player name
    void UpdateScore(int score_change);             // Add score_change to current score
    int GetScore();                                 // retrieve current score

private:
    // Data Members
    std::string name;
    int score{};
};


#endif /* Player_hpp */
