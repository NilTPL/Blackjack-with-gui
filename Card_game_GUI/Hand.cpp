#include "stdafx.h"
#include "Hand.h"
#include <iostream>
#include "Deck.h"

Hand::Hand()
	: hand()
{
	std::deque<Card*> deck = deck;
}

Hand::~Hand()
{
	hand.clear();
}


int Hand::Values()
{
	int values = 0;
	for (Card card : hand)
	{
		values += card.GetFaceValue();
	}
	return values;
}

std::deque<Card>& Hand::GetHand()
{
	return hand;
}
void Hand::Print()
{
	for (Card card : hand)
	{
		std::cout << " ";
		card.Print();
	}
}

void Hand::Grab(std::deque<Card>& deck)
{
	hand.emplace_front(deck.front());
	
}

