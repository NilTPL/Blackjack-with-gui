#include "stdafx.h"
#include "Deck.h"
#include "Hand.h"
#include "character.h"
#include "Button.h"
#include <iostream>

#include <Windows.h>
#include <stdio.h>

//using namespace sf;

std::string texturePath = "assets/textures/cards/cards.png";

int main()
{

	//Init irl objects (Deck, etc.)
	Deck deck(texturePath);
	deck.populate();
	deck.shuffle();

	Character player;


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
					if (hitButton.isMouseOver(window))
					{
						system("cls");
						std::cout << "Hitting has bestowed upon you:  " << deck.currentCard().toString() << std::endl;
						player.hand.grabCard(deck);
						std::cout << "------- \n";
						std::cout << "Your hand is now: ";
						for (Card& card : player.hand.getHand())
						{
							std::cout << card.toString() << ", ";
						}
					}
					else if (standButton.isMouseOver(window))
					{
						std::cout << "Stand..." << std::endl;
					}
					else { std::cout << "mouse1 was pressed at position: " << mouseButtonPressed->position.x << " " << mouseButtonPressed->position.y << std::endl; }
				}
			}
		}
		
		


		// ^ UPDATE

		//DRAW
		window.clear(sf::Color(21, 61, 39));
		
		window.draw(boxContainingButtons);
		hitButton.drawTo(window);
		standButton.drawTo(window);
		for (int i = 0; i < player.hand.getHand().size(); i++)
		{
			Card& card = player.hand.getHand().at(i);
			card.sprite.setPosition({(card.sprite.getLocalBounds().size.x / 2 * i ), 20.f});
			window.draw(card.sprite);
		}

		window.display();

	}


	//End of application
	return 0;
}