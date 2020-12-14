#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include<iostream>

class Room
{
private:
	enum class RoomType { Empty = 0, Treasure, Enemy, Trap, Back, Mystery, Healing };

	sf::Font font;
	sf::Text text;

	sf::Texture gameTextures;
	sf::IntRect roomSpriteSrc;
	sf::Sprite roomSprite;

	int roomType;
	RoomType type;

	int unitSize;

	int randNumber;


	//ENEMIES
	float enemyDmg;
	float enemyHp;

	//Player
	float playerDmg;
	float playerArmor;
	float playerHpArmor;

	void initVariables();
	void randomGenerator();

public:
	Room();
	virtual ~Room();

	//Getters
	const int getRoomType() const;
	const sf::Sprite getSprite() const;

	//Setters
	void setPosition(sf::Vector2f pos);

	//Functions
	void combat(Player& player);

	sf::Text displayText();
	
	void update(int roomType, Player& player);
};

