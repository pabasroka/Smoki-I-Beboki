#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class UI
{
private:
	sf::Texture texture; //some example texture in the future it will be seperate variables
	sf::Sprite sprite;
	sf::IntRect spriteSrc;

	void initTextures();
	void initSprites();
public:
	//Constructor and Destructor
	UI();
	virtual ~UI();

	// I only have render function because it is a static interface
	// dynamic sprites, interface, etc will be in Player class
	void render(sf::RenderTarget& target); // I use & to get simple access to Game.cpp
};

