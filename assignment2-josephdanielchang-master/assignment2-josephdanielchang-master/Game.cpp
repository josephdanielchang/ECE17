//
//  Game.cpp
//  assignment2
//
//  Created by rick gessner on 10/6/19.
//  Copyright © 2019 rick gessner. All rights reserved.
//

#include "Game.hpp"

// Default Constructor
Game::Game(const char * player1_name, const char * player2_name, bool shuffle_deck){
    player1.SetName(player1_name);
    player2.SetName(player2_name);
    gameDeck = Deck();
    roundNumber = 0;
    if (shuffle_deck)
        gameDeck.Shuffle();
};

// Copy Constructor
Game::Game(const Game &Game) {}

// Assignment Operator
Game &Game::operator=(const Game &Game) {}

// Destructor
Game::~Game() = default;

// Methods
bool Game::PlayRound() {
    bool roundPlayed = false;
    Card card;
    if (roundNumber >= 0 && !gameDeck.IsEmpty()) {
        gameDeck.Pop(card);                         // Pop card 1 from top of face-down deck
        player1.hand.Add(card);                         // Add card 1 to player 1 hand
        player1.UpdateScore((int) card.GetFace());      // Update player 1 score

        gameDeck.Pop(card);                         // Pop card 2 from top of face-down deck
        player2.hand.Add(card);                         // Add card 2 to player 2 hand
        player2.UpdateScore((int) card.GetFace());      // Update player 2 score

        roundNumber++;                                  // Update round count
        roundPlayed = true;
    }
    return roundPlayed;
}

void Game::PrintScoreboard() {
    std::cout << "Round #" << roundNumber << ": " << player1.GetName() << ": " << player1.GetScore() << ", " << player2.GetName() << ": " << player2.GetScore() << std::endl;
}
