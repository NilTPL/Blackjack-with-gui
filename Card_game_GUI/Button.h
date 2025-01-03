#pragma once

class Button 
{
public:
	Button();
	Button(std::string text, const sf::Font& font)
		: buttonLabel(font){
		buttonLabel.setString(text);
		buttonLabel.setFillColor(sf::Color(0, 0, 0));
		buttonLabel.setCharacterSize(32);
	}
	~Button();

	//Variables

	//Functions
	void setFont(sf::Font& font)
	{
		buttonLabel.setFont(font);
	}

	void setBgColor(sf::Color color)
	{
		button.setFillColor(color);
	}

	void setTextColor(sf::Color color)
	{
		buttonLabel.setFillColor(color);
	}

	void setButtonSize()
	{
		button.setSize(sf::Vector2f(sf::Vector2i(buttonLabel.getGlobalBounds().getSize() * 1.2f)));
	}

	void setPosition(sf::Vector2f pos)
	{
		button.setPosition(pos);
		
		buttonLabel.setOrigin(sf::Vector2f(sf::Vector2i(buttonLabel.getLocalBounds().getSize() / 2.f + buttonLabel.getLocalBounds().getPosition())));
		buttonLabel.setPosition(sf::Vector2f(sf::Vector2i(pos + button.getLocalBounds().getSize() / 2.f)));

		/*
		startText.setOrigin(sf::Vector2f(sf::Vector2i(startText.getLocalBounds().getSize() / 2.f + startText.getLocalBounds().getPosition())));
		startText.setPosition(sf::Vector2f(sf::Vector2i(window.getView().getSize() / 2.f)));
		*/
	}

	void drawTo(sf::RenderWindow& window)
	{
		window.draw(button);
		window.draw(buttonLabel);
	}

	bool isMouseOver(sf::RenderWindow& window) {
		sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
		if (button.getGlobalBounds().contains(mouseWorldPosition))
		{
			return true;
		}
		else return false;
	}

	sf::RectangleShape button;
	sf::Text buttonLabel;
private:
};
