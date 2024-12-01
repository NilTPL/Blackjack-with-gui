#include "stdafx.h"
#include "Deck.h"
#include <algorithm>
#include <iostream>

Deck::Deck()
	: deckDeque()
{
	for (Card::Ranks r = Card::ACE; r <= Card::KING; r = static_cast<Card::Ranks>(static_cast<int>(r) + 1))
	{
		for (Card::Suits s = Card::HEARTS; s <= Card::SPADES; s = static_cast<Card::Suits>(static_cast<int>(s) + 1))
		{
			deckDeque.emplace_front(r, s);
		}
	}
	int cardsTakenOut = 0;
}

Deck::~Deck()
{
	deckDeque.clear();
}

std::deque<Card>& Deck::GetDeck() 
{ 
	return deckDeque; 
}

void Deck::Print()
{
	for (Card card : deckDeque)
	{
		card.Print();
		std::cout << " ";
	}
}

void Deck::Shuffle()
{
	std::random_shuffle(deckDeque.begin(), deckDeque.end());
}

Card Deck::TopCard()
{
	return deckDeque.front();
}

void Deck::PopCard()
{
	deckDeque.push_back(deckDeque.front());
	deckDeque.pop_front();
}
