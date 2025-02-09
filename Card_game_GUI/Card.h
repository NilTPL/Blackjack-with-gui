#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    Card(std::string rank, std::string suit, sf::Texture texture);
    std::string getRank() const;
    std::string getSuit() const;
    std::string toString() const;
    virtual ~Card();
private:
    std::string rank;
    std::string suit;
    //int textureIndexX;
    //int textureIndexY;
public:
    sf::Sprite sprite;
};

#endif // CARD_H