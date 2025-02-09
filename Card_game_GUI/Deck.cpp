#include "stdafx.h"
#include "deck.h"
#include <chrono>
#include <algorithm>

// Seed randomness for later shuffle using system time
Deck::Deck(std::string texturePath) : seed(std::chrono::system_clock::now().time_since_epoch().count()), e(seed), texture(texturePath) {

}

/*
    Fill the deck with the default 52-card deck,
    shorten the deck from the low side (positive value)
    or from the high side (negative value),
*/
void Deck::populate() {
    std::vector<std::string> ranks = {
      "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
    };
    std::vector<std::string> suits = {
        "Diamonds", "Hearts", "Clubs", "Spades"
    };

    // Populate deck
    for (int i = 0; i <= ranks.size(); i++) {
        for (int j = 0; j <= suits.size(); j++) {
            deck.emplace_back(ranks.at(i), suits.at(j), texture, i, j);
        }
    }
}

// Take card from the back of the vector
Card Deck::drawCard() {
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// Add card to the back of the vector
void Deck::addCard(Card card) {
    deck.push_back(card);
}

int Deck::getNumCards() const {
    return deck.size();
}

void Deck::shuffle() {
    std::shuffle(deck.begin(), deck.end(), e);
}

Deck::~Deck() {

}