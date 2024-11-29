#include "stdafx.h"
#include <iostream>


//using namespace sf;

int main()
{
	//Init srand
	std::srand(time(nullptr));

	//init rest
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Blackjack in C++", sf::Style::Titlebar | sf::Style::Close, settings);
	
	//Text
	sf::Font consolasFont;
	consolasFont.loadFromFile("assets/fonts/Consolas.ttf");
	
	sf::Text startText("words on a screen", consolasFont, 32);
	startText.setFillColor(sf::Color(255, 0, 0));
	startText.setOutlineThickness(2.f);
	startText.setOutlineColor(sf::Color(0, 0, 0));
	startText.setOrigin(sf::Vector2f(sf::Vector2i(startText.getLocalBounds().getSize() / 2.f + startText.getLocalBounds().getPosition())));
	startText.setPosition(sf::Vector2f(sf::Vector2i(window.getView().getSize() / 2.f)));

	int XIndex = 0;
	int YIndex = 0;
	bool moving = false;
	sf::Texture cardTexture;
	sf::Sprite cardSprite;
	if (cardTexture.loadFromFile("assets/textures/cards/CardsClubs.png"))
	{
		cardSprite.setTexture(cardTexture);
		int XIndex = 0;
		int YIndex = 0;
		// 0, 0 -> Ace

		cardSprite.setTextureRect(sf::IntRect(XIndex * 88, YIndex * 124, 88, 124));
		cardSprite.scale(1, 1);
		cardSprite.setOrigin(sf::Vector2f(cardSprite.getLocalBounds().getSize() / 2.f));
		cardSprite.setPosition(100, 100);
	}


	//main loop

	while (window.isOpen())
	{
		//UPDATE
		sf::Vector2i mousePixelPosition = sf::Mouse::getPosition(window);
		sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(mousePixelPosition);
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Keyboard::Escape)
				window.close();
			else if (event.type == sf::Event::MouseButtonPressed)
			{	
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (startText.getGlobalBounds().contains(mouseWorldPosition)) {
						std::cout << "start \n";
					}
					if (cardSprite.getGlobalBounds().contains(mouseWorldPosition)) {
						if (moving == true)
							moving = false;
						else if (moving == false)
							moving = true;
					}
				}
			}
		}
		if (moving == true)
		{
			cardSprite.setPosition(mouseWorldPosition);
		}

		// ^ UPDATE

		//DRAW
		window.clear(sf::Color(21, 61, 39));
		window.draw(startText);
		window.draw(cardSprite);
		window.display();

	}


	//End of application
	return 0;
}