#pragma once

class Card
{
public:
	//Variables
	enum Suits
	{
		HEARTS = 3,
		DIAMONDS,
		CLUBS,
		SPADES
	};
	enum Ranks
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING,
	};
	sf::Texture cardTexture;
	sf::Sprite cardSprite;
	int XIndex = 0;
	int YIndex = 0;
	bool moving = false;
	//Variables


	//Functions
	Card(Ranks RANK, Suits SUIT);
	virtual ~Card();

	Ranks GetRank();
	Suits GetSuit();

	virtual int GetFaceValue();
	void Print();

	//Functions
private:
	Ranks Rank;
	Suits Suit;
};