﻿#include "stdafx.h"
#include "Hand.h"
#include "Deck.h"
#include "Button.h"
#include <iostream>

//using namespace sf;

int main()
{
	//Init srand
	std::srand(time(NULL));

	//Init irl objects (Deck, Hand)
	Deck gameDeck;
	Hand playerHand(gameDeck);
	Hand dealerHand(gameDeck);
	gameDeck.Shuffle();
	dealerHand.Grab(gameDeck);


	sf::RectangleShape boxContainingButtons(sf::Vector2f(266, 200));
	boxContainingButtons.setOrigin(boxContainingButtons.getLocalBounds().size + boxContainingButtons.getPosition());
	boxContainingButtons.setPosition({ 800, 600 });
	boxContainingButtons.setFillColor(sf::Color(30, 30, 30));

	sf::Font consolasFont("assets/fonts/Consolas.ttf");

	Button hitButton("Hit", consolasFont);
	hitButton.setButtonSize();
	hitButton.setPosition(sf::Vector2f(800 - 266, 600 - 200));
	Button standButton("Stand", consolasFont);
	standButton.setButtonSize();
	standButton.setPosition(sf::Vector2f(800 - standButton.button.getLocalBounds().size.x, 600 - 200));

	//init rest
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Blackjack in C++", sf::Style::Titlebar | sf::Style::Close, sf::State::Windowed, settings);
	


	//main loop


	while (window.isOpen())
	{
		//UPDATE
		sf::Vector2i mousePixelPosition = sf::Mouse::getPosition(window);
		sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(mousePixelPosition);


		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
			else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
			{
				if (mouseButtonPressed->button == sf::Mouse::Button::Left)
				{
					std::cout << "mouse1 was pressed at position: " << mouseButtonPressed->position.x << " " << mouseButtonPressed->position.y << std::endl;
					if (hitButton.isMouseOver(window))
					{
						playerHand.Grab(gameDeck);
						dealerHand.Grab(gameDeck);
						for (int i = 0; i < playerHand.GetHand().size(); i++)
						{
							playerHand.GetHand().at(i).cardSprite.setPosition({ 10, 600 - 144 });
							playerHand.GetHand().at(i).cardSprite.setPosition(sf::Vector2f(playerHand.GetHand().at(i).cardSprite.getPosition() + sf::Vector2f(playerHand.GetHand().at(i).cardSprite.getGlobalBounds().size.x * i / 4, 0)));
						}
					}
				}
			}
		}


		for (int i = 0; i < dealerHand.GetHand().size(); i++)
		{
			dealerHand.GetHand().at(i).cardSprite.setPosition({ 10, 10 });
			dealerHand.GetHand().at(i).cardSprite.setPosition(sf::Vector2f(dealerHand.GetHand().at(i).cardSprite.getPosition() + sf::Vector2f(dealerHand.GetHand().at(i).cardSprite.getGlobalBounds().size.x * i / 4, 0)));
		}
		
		

		// ^ UPDATE

		//DRAW
		window.clear(sf::Color(21, 61, 39));
		
		
		//window.draw(startText);
		//window.draw(cardSprite);
		window.draw(boxContainingButtons);
		hitButton.drawTo(window);
		standButton.drawTo(window);
		for (Card card : playerHand.GetHand())
		{
			window.draw(card.cardSprite);
		}
		for (Card card : dealerHand.GetHand())
		{
			window.draw(card.cardSprite);
		}
		window.display();

	}


	//End of application
	return 0;
}