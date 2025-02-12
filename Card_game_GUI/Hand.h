#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>

class Hand {
public:
    Hand();

    void grabCard(Deck& deck);
    std::vector<Card>& getHand();
    sf::Vector2f pos;
    virtual ~Hand();
private:
    std::vector<Card> hand;
};

#endif // DECK_H