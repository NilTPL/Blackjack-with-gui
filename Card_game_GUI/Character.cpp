#include "stdafx.h"
#include "Hand.h"
#include "character.h"


Character::Character(std::string name, sf::Vector2f handpos) : hand(handpos), name(name) {
}

Hand& Character::Hand()
{
	return hand;
}

Character::~Character()
{
}
