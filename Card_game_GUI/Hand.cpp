#include "stdafx.h"
#include "Card.h"
#include "Deck.h"
#include "Hand.h"

Hand::Hand() : pos(0, 0)
{
}

void Hand::grabCard(Deck& deck)
{
	hand.emplace_back(deck.drawCard());
}

std::vector<Card>& Hand::getHand()
{
	return hand;
}





Hand::~Hand()
{
}
