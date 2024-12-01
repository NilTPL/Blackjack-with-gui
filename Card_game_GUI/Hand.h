#pragma once

#include <deque>
#include "Card.h"
#include "Deck.h"

class Hand
{
public:
	Hand(Deck& deck);
	~Hand();

	std::deque<Card>& GetHand();
	void Print();
	void Grab(Deck& deck);
	int Values();
	std::deque<Card> hand;
private:
};
