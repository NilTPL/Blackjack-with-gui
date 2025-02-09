#include "stdafx.h"
#include "deck.h"
#include <chrono>
#include <algorithm>

// Seed randomness for later shuffle using system time
Deck::Deck() : seed(std::chrono::system_clock::now().time_since_epoch().count()), e(seed), texture("assets/textures/cards/Back-TopDown-single.png") {

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
    std::string suits[] = {
        "Diamonds", "Hearts", "Clubs", "Spades"
    };

    // Populate deck
    for (const auto& rank : ranks) {
        for (const auto& suit : suits) {
            deck.emplace_back(rank, suit);
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