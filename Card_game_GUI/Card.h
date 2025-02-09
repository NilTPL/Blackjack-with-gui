#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(std::string rank, std::string suit, sf::Texture& texture, int rankValue, int suitValue);
    std::string getRank() const;
    std::string getSuit() const;
    std::string toString() const;
    virtual ~Card();
private:
    std::string rank;
    int rankValue;
    std::string suit;
    int suitValue;
    int texturePosX;
    int texturePosY;
public:
    sf::Sprite sprite;
};

#endif // CARD_H