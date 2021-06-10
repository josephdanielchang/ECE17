//
//  Deck.cpp
//  assignment2
//

#include "Deck.hpp"
#include <cstdlib> // rand

Deck::Deck() {
    int counter = 0;
    cardsLeft = 52;
    for (int j = Card::SuitEnum::SPADE; j <= Card::SuitEnum::CLUB; j++) {
        for (int i = Card::FaceEnum::ACE; i <= Card::FaceEnum::KING; i++) {
            deck[counter] = Card((Card::FaceEnum) i, (Card::SuitEnum) j, false);
            counter++;
        }
    }
}

// Copy Constructor
Deck::Deck(const Deck &aDeck) {}

// Assignment Operator
Deck &Deck::operator=(const Deck &aDeck) {}

// Destructor
Deck::~Deck() = default;

//Methods
void Deck::Shuffle() {
    Card temp;
    int randomIndex = 0;

    for (int i=0; i<cardsLeft; i++) {     // swap every index with random index
        randomIndex = rand() % cardsLeft;
        temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

bool Deck::Pop(Card &a_card) {
    if (!IsEmpty()) {
        a_card = deck[cardsLeft-1];
        cardsLeft--;                    // discard last card
        return true;
    } else return false;
}

bool Deck::Push(const Card &a_card) {
    if (cardsLeft < 52 && cardsLeft >= 0 && !IsCardInDeck(a_card)) {
        deck[cardsLeft] = a_card;
        cardsLeft++;
        return true;
    } else return false;
}

bool Deck::IsEmpty() {
    return (cardsLeft == 0);
}

size_t Deck::NumCards() {
    return cardsLeft;
}

bool Deck::IsCardInDeck(const Card &a_card) {
    bool duplicate = false;
    for (int i=0; i<cardsLeft; i++) {
        // std::cout << "IsCardInDeck:"  << cardsLeft << std::endl;
        if (deck[i].DoesCardMatch(a_card))
            duplicate = true;
    }
    return duplicate;
}

void Deck::PrintDeck() {
    for (int i=0; i<cardsLeft; i++) {
        if (i < cardsLeft-1)
            std::cout << deck[i].CardString() << " ";
        else
            std::cout << deck[i].CardString() << std::endl;
    }
}
