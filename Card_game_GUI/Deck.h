#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <random>

class Deck {
public:
    Deck(std::string texturePath);
    int getNumCards() const;
    void populate();
    Card drawCard();
    Card currentCard();
    void addCard(Card card);
    void shuffle();
    virtual ~Deck();
    int getCardValues();
    sf::Texture texture;
private:
    std::vector<Card> deck;
    unsigned int seed;
    std::default_random_engine e;
    int totalValue = 0;
};

#endif // DECK_H