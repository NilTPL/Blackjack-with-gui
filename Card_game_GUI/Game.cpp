#include "stdafx.h"
#include "Game.h"

Game::Game() :
window(sf::VideoMode({ 800, 600 }), "Blackjack in C++", sf::Style::Titlebar | sf::Style::Close, sf::State::Windowed),
deck(texturePath),
boxContainingButtons(sf::Vector2f(266, 200)),
consolasFont("assets/fonts/Consolas.ttf"),
hitButton("Hit", consolasFont),
standButton("Stand", consolasFont)
{
	Character player("player", { 20, 600-164 });
	Character dealer("dealer", { 10, 10 });
	players.push_back(player);
	players.push_back(dealer);


	//Init irl objects (Deck, etc.)
	deck.populate();
	deck.shuffle();

	player.hand.pos = sf::Vector2f(10.f, 20.f);
	dealer.hand.pos = sf::Vector2f(10.f, 300.f);


	
	boxContainingButtons.setOrigin(boxContainingButtons.getLocalBounds().size + boxContainingButtons.getPosition());
	boxContainingButtons.setPosition({ 800, 600 });
	boxContainingButtons.setFillColor(sf::Color(30, 30, 30));

	hitButton.setButtonSize();
	hitButton.setPosition(sf::Vector2f(800 - 266, 600 - 200));
	standButton.setButtonSize();
	standButton.setPosition(sf::Vector2f(800 - standButton.button.getLocalBounds().size.x, 600 - 200));



}

Game::~Game()
{
}
