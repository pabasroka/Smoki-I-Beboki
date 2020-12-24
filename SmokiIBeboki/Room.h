#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
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
	float enemyDmg{};
	float enemyHp{};

	//Player
	float playerDmg{};
	float playerArmor{};
	float critChance{};
	float escapeChance{};
	float combatHealth{};
	float totalDamageTaken{};

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
	void setRoomType(int type);

	//Functions
	void combat(Player& player);

	sf::Text displayText();
	
	void action(int roomType, Player& player);
	void escape(int roomType, Player& player);
};

