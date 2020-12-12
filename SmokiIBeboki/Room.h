#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<iostream>

class Room
{
private:
	enum class RoomType { Empty = 0, Treasure, Enemy, Trap, Back, Mystery };

	sf::Font font;
	sf::Text text;

	sf::Texture gameTextures;
	sf::IntRect roomSpriteSrc;
	sf::Sprite roomSprite;

	int roomType;
	RoomType type;

	int unitSize;

	int randNumber;

	void initVariables();
	void randomGenerator();

public:
	Room();
	virtual ~Room();

	//Getters
	const int getRoomType(int type) const;
	const sf::Sprite getSprite() const;

	//Setters
	void setPosition(sf::Vector2f pos);

	sf::Text displayText();
	
	void update(Player& player);
};

