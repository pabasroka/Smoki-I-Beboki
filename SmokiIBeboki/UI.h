#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class UI
{
private:
	int unitSize;
	int arrowTimerMax;
	int arrowTimer;

	//Example sprites
	sf::Texture texture; //some example texture in the future it will be seperate variables
	sf::Sprite sprite;
	sf::IntRect spriteSrc; 

	//Dynamic sprites
	sf::Texture gameTextures;
	sf::Sprite gameView;
	sf::IntRect gameViewSrc;

	//Static spirtes
	sf::Sprite gui;
	sf::IntRect guiSrc;

	sf::Sprite arrowR;
	sf::IntRect arrowsSrc;

	sf::Sprite arrowL;
	sf::IntRect arrowLSrc;

	sf::Sprite arrowRAction;
	sf::IntRect arrowRActionSrc;

	sf::Sprite arrowLAction;
	sf::IntRect arrowLActionSrc;

	sf::Sprite upgrade;
	sf::IntRect upgradeSrc;

	sf::Sprite sword;
	sf::IntRect swordSrc;

	sf::Sprite shield;
	sf::IntRect shieldSrc;

	sf::Sprite heart;
	sf::IntRect heartSrc;

	sf::Sprite fist;
	sf::IntRect fistSrc;

	sf::Sprite clover;
	sf::IntRect cloverSrc;

	sf::Sprite coin;
	sf::IntRect coinSrc;

	sf::Sprite key;
	sf::IntRect keySrc;

	sf::RectangleShape expBar;
	sf::Font font;
	sf::Text lvl;

	void initVariables();
	void initTextures();
	void initSprites();
public:
	//Constructor and Destructor
	UI();
	virtual ~UI();

	//Functions
	void input();

	// I only have render function because it is a static interface
	// dynamic sprites, interface, etc will be in Player class
	void update();
	void renderGV(sf::RenderTarget& target); // I use & to get simple access to Game.cpp
	void renderGUI(sf::RenderTarget& target); 
};

