#include "stdafx.h"
#include "card.h"

Card::Card(std::string rank, std::string suit, sf::Texture texture) : rank(rank), suit(suit), sprite(texture) {}

std::string Card::getRank() const {
    return rank;
}

std::string Card::getSuit() const {
    return suit;
}

std::string Card::toString() const {
    return suit + " " + rank;
}

Card::~Card() {

}