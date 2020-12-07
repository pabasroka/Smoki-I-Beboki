#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"

class UI
{
private:
	Player* player;

	int unitSize;
	int arrowTimerMax;
	int arrowTimer;
	int test;
	float expIncrease;

	sf::Font font;

	//Example sprites
	sf::Texture texture; //some example texture in the future it will be seperate variables
	sf::Sprite sprite;
	sf::IntRect spriteSrc; 

	//Dynamic sprites
	sf::Texture gameTextures;
	sf::Sprite gameView;
	sf::IntRect gameViewSrc;

	//Static sprites
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
	sf::Text shieldTxt;

	sf::Sprite heart;
	sf::IntRect heartSrc;
	sf::Text heartTxt;

	sf::Sprite fist;
	sf::IntRect fistSrc;
	sf::Text fistTxt;

	sf::Sprite clover;
	sf::IntRect cloverSrc;
	sf::Text cloverTxt;

	sf::Sprite coin;
	sf::IntRect coinSrc;
	sf::Text coinTxt;

	sf::Sprite key;
	sf::IntRect keySrc;
	sf::Text keyTxt;

	sf::RectangleShape expBarBg;
	sf::RectangleShape expBar;
	sf::Text lvlTxt;

	sf::Sprite skillPoints;
	sf::IntRect skillPointsSrc;
	sf::Text skillPointsTxt;

	sf::Sprite door;
	sf::IntRect doorSrc;
	sf::Text doorTxt;

	sf::RectangleShape hpBarBg;
	sf::RectangleShape hpBar;

	void initVariables();
	void initTextures();
	void initSprites();
	void initText();
public:
	//Constructor and Destructor
	UI();
	virtual ~UI();

	//Functions
	void input();
	bool isDead();

	// I only have render function because it is a static interface
	// dynamic sprites, interface, etc will be in Player class
	void update();
	void updateText();
	
	void renderGV(sf::RenderTarget& target); // I use & to get simple access to Game.cpp
	void renderGUI(sf::RenderTarget& target); 
	void renderText(sf::RenderTarget& target);
	void render(sf::RenderTarget& target);
};

