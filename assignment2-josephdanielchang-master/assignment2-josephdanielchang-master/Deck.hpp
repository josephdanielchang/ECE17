//
//  Deck.hpp
//  assignment2
//
//  Created by rick gessner on 10/6/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include "Card.hpp"

// Tracks 52 Card objects
class Deck {
public:
    // Data Members
    Card deck[52];            // add collection of Card objects so the hand can hold up to all 52 cards in the deck, cards in hand are ordered
    int cardsLeft;            // tracks how many cards left in deck

    // OCF
    Deck();                                 // Default Constructor - populates deck data structure with 52 cards with
                                            // order A, 2, 3, ... , 10, J, Q, K and Spade, Diamond, Heart, Club
    Deck(const Deck &aDeck);                // Copy Constructor
    Deck& operator=(const Deck &aDeck);     // Assignment Operator
    ~Deck();                                // Destructor

    // Methods
    void Shuffle();                         // Randomize Card objects in Deck object
    bool Pop(Card &a_card);                 // Removes first top Card from Deck into a_card, true if successful,
    bool Push(const Card &a_card);          // Adds Card object to first top of Deck, true if successful, false if duplicate
    bool IsEmpty();                         // returns true if deck contains 0 Card objects
    size_t NumCards();                      // returns number of cards currently in deck
    bool IsCardInDeck(const Card &a_card);  // returns true if a_card in deck
    void PrintDeck();                       // prints abbreviated version of cards (helpful method in Card class)
};


#endif /* Deck_hpp */
