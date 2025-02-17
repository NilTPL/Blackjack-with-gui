#ifndef CHARACTER_H
#define CHARACTER_H

#include "Hand.h"
#include <string>

class Character
{
public:
	Character(std::string name, sf::Vector2f handpos);
	Hand hand;
	Hand& Hand();
	std::string name;

	~Character();
private:
};

#endif // CHARACTER_H