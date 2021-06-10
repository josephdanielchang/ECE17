//
//  Player.cpp
//  assignment2
//
//

#include "Player.hpp"

// Copy Constructor
Player::Player(const Player &Player) {}

// Assignment Operator
Player &Player::operator=(const Player &Player) {}

// Destructor
Player::~Player() = default;

// Methods
std::string Player::GetName() {
    return name;
}

void Player::SetName(const char *name) {
    this-> name = name;
}

void Player::UpdateScore(int score_change) {
    score += score_change;
}

int Player::GetScore() {
    return score;
}
