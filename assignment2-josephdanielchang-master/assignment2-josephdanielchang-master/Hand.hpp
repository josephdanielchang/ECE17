//
//  Hand.hpp
//  assignment2
//


#ifndef Hand_hpp
#define Hand_hpp

#include "Card.hpp"

// Container of some Card objects assigned to a given Player
class Hand {
public:
    // Data Members
    Card hand[52];            // add collection of Card objects so the hand can hold up to all 52 cards in the deck, cards in hand are ordered
    int cardsLeft;            // tracks how many cards left in deck

    // OCF
    Hand();                                         // Default Constructor
    Hand(const Hand &aHand);                        // Copy Constructor
    Hand &operator=(const Hand &Hand);              // Assignment Operator
    ~Hand();                                        // Destructor

    // Methods
    bool Add(const Card &a_card);                   // used to add card to hand, true is successful, false if duplicate
    bool Discard(const Card &a_card);               // used to drop card from hand, true is a_card is in hand
    size_t NumCards();                              // returns number of Card objects hand contains
    bool GetCard(Card &a_card, size_t card_num);    // retrieves card at card_num 0-51 and copies into a_card
    bool IsCardInHand(const Card &a_card);          // returns true if a_card in Hand
    void PrintHand();                               // prints abbreviated version of cards (helpful method in Card class)
};


#endif /* Hand_hpp */
