#include "stdafx.h"
#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
	: deck()
{
	for (Card::Ranks r = Card::TWO; r <= Card::ACE; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1))
	{
		for (Card::Suits s = Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s) + 1))
		{
			deck.emplace_front(r, s);
		}
	}
}

Deck::~Deck()
{
	deck.clear();
}

std::deque<Card>& Deck::GetDeck() 
{ 
	return deck; 
}

void Deck::Print()
{
	for (Card card : deck)
	{
		card.Print();
		std::cout << " ";
	}
}

void Deck::Shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::TopCard()
{
	return deck.front();
}

void Deck::PopCard()
{
	deck.push_back(deck.front());
	deck.pop_front();
}
