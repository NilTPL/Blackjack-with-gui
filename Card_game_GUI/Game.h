#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Deck.h"
#include "Character.h"
#include "Button.h"
#include <vector>

class Game {
public:
    Game();
    std::vector<Character> players;
    sf::RenderWindow window;

    std::string texturePath = "assets/textures/cards/cards.png";
    Deck deck;

    sf::RectangleShape boxContainingButtons;
    sf::Font consolasFont;
    Button hitButton;
    Button standButton;

    ~Game();
private:
};

#endif // GAME_H