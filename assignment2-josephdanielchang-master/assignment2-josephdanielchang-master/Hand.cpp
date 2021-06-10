//
//  Hand.cpp
//  assignment2
//

#include "Hand.hpp"

// Default Constructor
Hand::Hand() {
    cardsLeft = 0;
}

// Copy Constructor
Hand::Hand(const Hand &aHand) = default;

// Assignment Operator
Hand &Hand::operator=(const Hand &Hand) {}

// Destructor
Hand::~Hand() = default;

// Methods
bool Hand::Add(const Card &a_card) {
    if (cardsLeft < 52 && cardsLeft >=0 && !IsCardInHand(a_card)) {
        hand[cardsLeft] = a_card;
        cardsLeft++;
        return true;
    } else return false;
}

bool Hand::Discard(const Card &a_card) {
    bool duplicate = false;
    if (cardsLeft != 0) {
        for (int i=0; i<cardsLeft; i++) {
            if (hand[i].DoesCardMatch(a_card)) {
                duplicate = true;
                for (int j=i; j<cardsLeft-1; j++)   // -1 because can't replace last card
                    hand[j] = hand[j+1];
                cardsLeft--;                        // discard last card
                break;
            }
        }
    }
    return duplicate;
}

size_t Hand::NumCards() {
    return cardsLeft;
}

bool Hand::GetCard(Card &a_card, size_t card_num) {
    if (card_num > NumCards())
        return false;
    else {
        a_card = hand[card_num];
        return true;
    }
}
bool Hand::IsCardInHand(const Card &a_card) {
    bool duplicate= false;
    for (int i=0; i<cardsLeft; i++) {
        if (hand[i].DoesCardMatch(a_card))
            duplicate = true;
    }
    return duplicate;
}

void Hand::PrintHand() {
    for (int i=0; i<cardsLeft; i++) {
        if (i < cardsLeft-1)
            std::cout << hand[i].CardString() << " ";
        else
            std::cout << hand[i].CardString() << std::endl;
    }
}
