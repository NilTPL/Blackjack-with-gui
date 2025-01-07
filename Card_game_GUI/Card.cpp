#include "stdafx.h"
#include "Card.h"
#include <iostream>

Card::Card(Ranks RANK, Suits SUIT)
    : Rank(RANK),
    cardTexture("assets/textures/cards.png"),
    cardSprite(cardTexture),
    Suit(SUIT)
{
    int XIndex = 0;
    int YIndex = 0;
    XIndex = (GetRank() - 1);

    cardSprite.setTextureRect(sf::IntRect({ XIndex * 88, YIndex * 124 }, { 88, 124 }));
    cardSprite.scale({ 1, 1 });
    cardSprite.setPosition({ 0, 0 });
}

Card::~Card()
{
    //a
}

Card::Ranks Card::GetRank()
{
    return Rank;
}

Card::Suits Card::GetSuit()
{
    return Suit;
}

int Card::GetFaceValue()
{
    if (Rank <= TEN && Rank >= TWO)
        return static_cast<int>(Rank);

    if (Rank >= JACK && Rank < ACE)
        return 10;

    else return 11;
}

void Card::Print()
{
    if (Rank <= TEN && Rank >= TWO)
        std::cout << Rank;
    else if (Rank == JACK)
        std::cout << "J";
    else if (Rank == QUEEN)
        std::cout << "Q";
    else if (Rank == KING)
        std::cout << "K";
    else 
        std::cout << "A";
    if (Suit == HEARTS)
        std::cout << static_cast<char>(3);
    else if (Suit == DIAMONDS)
        std::cout << static_cast<char>(4);
    else if (Suit == CLUBS)
        std::cout << static_cast<char>(5);
    else if (Suit == SPADES)
        std::cout << static_cast<char>(6);
}

/*
    if (cardTexture.loadFromFile("assets/textures/cards/CardsClubs.png"))
    {
        cardSprite.setTexture(cardTexture);
        int XIndex = 0;
        int YIndex = 0;
        // 0, 0 -> Ace

        cardSprite.setTextureRect(sf::IntRect(XIndex * 88, YIndex * 124, 88, 124));
        cardSprite.scale(1, 1);
        cardSprite.setOrigin(sf::Vector2f(cardSprite.getLocalBounds().getSize() / 2.f));
        cardSprite.setPosition(100, 100);
    }
*/

/*
if (cardSprite.getGlobalBounds().contains(mouseWorldPosition)) {
                        if (moving == true)
                            moving = false;
                        else if (moving == false)
                            moving = true;
                    }
*/

/*
if (moving == true)
        {
            cardSprite.setPosition(mouseWorldPosition);
        }*/