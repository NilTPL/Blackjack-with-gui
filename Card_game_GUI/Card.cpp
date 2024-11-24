#include "stdafx.h"
#include "Card.h"
#include <iostream>

Card::Card(Ranks RANK, Suits SUIT)
    : Rank(RANK),
    Suit(SUIT)
{
    //a
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
    if (Rank <= TEN)
        return static_cast<int>(Rank);

    if (Rank >= JACK && Rank < ACE)
        return 10;

    else return 11;
}

void Card::Print()
{
    if (Rank <= TEN)
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
