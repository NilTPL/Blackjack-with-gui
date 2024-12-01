#include "stdafx.h"
#include "Hand.h"
#include <iostream>
#include "Deck.h"

Hand::Hand(Deck& deck)
	: hand()
{
	std::deque<Card> usingDeck = deck.GetDeck();
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

void Hand::Grab(Deck& deck)
{
	deck.cardsTakenOut++;
	if (deck.cardsTakenOut == 52)
	{
		deck.Shuffle();
		deck.cardsTakenOut = 0;
	}
	if (!deck.GetDeck().empty()) {
		hand.emplace_front(deck.TopCard());
		deck.PopCard();
	}
	if (deck.GetDeck().empty())
	{
		std::cout << "deck empty";
	}
}
void drawTo(sf::RenderWindow& window, Hand& hand)
{
	for (Card& card : hand.GetHand())
	{
		window.draw(card.cardSprite);
	}
}