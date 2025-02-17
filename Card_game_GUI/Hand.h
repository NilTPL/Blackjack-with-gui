#ifndef HAND_H
#define HAND_H

#include "Card.h"
#include "Deck.h"
#include <vector>

class Hand {
public:
    Hand();
    Hand(sf::Vector2f handpos);

    void grabCard(Deck& deck);
    std::vector<Card>& getHand();
    sf::Vector2f pos;
    virtual ~Hand();
private:
    std::vector<Card> hand;
};

#endif // HAND_H