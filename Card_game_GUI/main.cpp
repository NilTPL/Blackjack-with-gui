#include "stdafx.h"
#include "Deck.h"
#include "Hand.h"
#include "character.h"
#include "Button.h"
#include <iostream>
#include "Game.h"
#include <Windows.h>
#include <stdio.h>

//using namespace sf;


int main()
{
	Game game;

	
	//main loop


	while (game.window.isOpen())
	{
		//UPDATE
		sf::Vector2i mousePixelPosition = sf::Mouse::getPosition(game.window);
		sf::Vector2f mouseWorldPosition = game.window.mapPixelToCoords(mousePixelPosition);


		while (const std::optional event = game.window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				game.window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					game.window.close();
			}
			else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
			{
				if (mouseButtonPressed->button == sf::Mouse::Button::Left)
				{
					if (game.hitButton.isMouseOver(game.window))
					{
						system("cls");
						std::cout << "Hitting has bestowed upon you:  " << game.deck.currentCard().toString() << std::endl;
						game.player.hand.grabCard(game.deck);
						std::cout << "------- \n";
						std::cout << "Your hand is now: \n ";
						for (Card& card : game.player.hand.getHand())
						{
							std::cout << card.toString() << ", ";
						}
					}
					else if (game.standButton.isMouseOver(game.window))
					{
						std::cout << "Stand..." << std::endl;
					}
					else { std::cout << "mouse1 was pressed at position: " << mouseButtonPressed->position.x << " " << mouseButtonPressed->position.y << std::endl; }
				}
			}
		}
		
		


		// ^ UPDATE

		//DRAW
		game.window.clear(sf::Color(21, 61, 39));
		
		game.window.draw(game.boxContainingButtons);
		game.hitButton.drawTo(game.window);
		game.standButton.drawTo(game.window);

		for (int i = 0; i < game.player.hand.getHand().size(); i++)
		{
			Card& card = game.player.hand.getHand().at(i);
			card.sprite.setPosition(game.player.hand.pos + sf::Vector2f{(card.sprite.getLocalBounds().size.x / 2 * i), 20.f });
			game.window.draw(card.sprite);
		}

		game.window.display();

	}


	//End of application
	return 0;
}