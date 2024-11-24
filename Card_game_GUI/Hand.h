#pragma once

#include <deque>
#include "Card.h"

class Hand
{
public:
	Hand();
	~Hand();

	std::deque<Card>& GetHand();
	void Print();
	void Grab(std::deque<Card>& deck);
	int Values();
private:
	std::deque<Card> hand;
};
