#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"Room.h"

class UI
{
private:
	Player* player;

	int unitSize;
	int arrowTimerMax;
	int arrowTimer;
	int inputTimer;
	int inputTimerMax;
	int test;
	float expIncrease;

	sf::Font font;

	//Dynamic sprites
	sf::Texture gameTextures;
	sf::Sprite gameView;
	sf::IntRect gameViewSrc;

	//Static sprites
	sf::Sprite gui;
	sf::IntRect guiSrc;


	//ARROWS
	sf::Sprite arrowR;
	sf::IntRect arrowsSrc;

	sf::Sprite arrowL;
	sf::IntRect arrowLSrc;

	sf::Sprite arrowRAction;
	sf::IntRect arrowRActionSrc;

	sf::Sprite arrowLAction;
	sf::IntRect arrowLActionSrc;

	sf::Sprite arrowU;
	sf::IntRect arrowUSrc;

	sf::Sprite arrowD;
	sf::IntRect arrowDSrc;

	sf::Sprite arrowUAction;
	sf::IntRect arrowUActionSrc;

	sf::Sprite arrowDAction;
	sf::IntRect arrowDActionSrc;

	//USER INTERFACE
	sf::Sprite upgrade;
	sf::IntRect upgradeSrc;

	sf::Sprite sword;
	sf::IntRect swordSrc;

	sf::Sprite shield;
	sf::IntRect shieldSrc;
	sf::Text shieldTxt;
	sf::Sprite upgradeShield;
	sf::IntRect upgradeShieldSrc;

	sf::Sprite heart;
	sf::IntRect heartSrc;
	sf::Text heartTxt;

	sf::Sprite fist;
	sf::IntRect fistSrc;
	sf::Text fistTxt;
	sf::Sprite upgradeFist;
	sf::IntRect upgradeFistSrc;

	sf::Sprite clover;
	sf::IntRect cloverSrc;
	sf::Text cloverTxt;
	sf::Sprite upgradeClover;
	sf::IntRect upgradeCloverSrc;

	sf::Sprite coin;
	sf::IntRect coinSrc;
	sf::Text coinTxt;

	sf::Sprite key;
	sf::IntRect keySrc;
	sf::Text keyTxt;
	sf::Sprite upgradeKey;
	sf::IntRect upgradeKeySrc;

	sf::RectangleShape expBar;
	sf::Text lvlTxt;

	sf::Sprite skillPoints;
	sf::IntRect skillPointsSrc;
	sf::Text skillPointsTxt;
	sf::Sprite upgradeSkillPoints;
	sf::IntRect upgradeSkillPointsSrc;

	sf::Sprite door;
	sf::IntRect doorSrc;
	sf::Text doorTxt;

	sf::RectangleShape hpBarBg;
	sf::RectangleShape hpBar;
	sf::Text hpTxt;
	sf::Sprite upgradeHp;
	sf::IntRect upgradeHpSrc;

	sf::Sprite upgradeCost;
	sf::IntRect upgradeCostSrc;
	sf::Sprite upgradeCost2;


	/*======	ROOM	====*/
	Room* roomA;
	Room* roomB;
	Room* selectedRoomR;
	int selectedRoom;
	
	sf::Sprite insideObject;
	sf::IntRect insideObjectSrc;

	int randomizeEnemy;
	int randomizeTrap;

	bool isInsideRoom;

	void initVariables();
	void initTextures();
	void initSprites();
	void initText();

	//Rooms functions
	void initRooms();
	void deleteRooms();
public:
	//Constructor and Destructor
	UI();
	virtual ~UI();

	//Functions
	void input();
	bool isDead();

	//Getters
	const int& getRoomCounter() const;

	// I only have render function because it is a static interface
	// dynamic sprites, interface, etc will be in Player class
	void update();
	void updateText();
	void updateInsideRoom(int roomType);

	void renderGV(sf::RenderTarget& target); // I use & to get simple access to Game.cpp
	void renderGUI(sf::RenderTarget& target); 
	void renderText(sf::RenderTarget& target);

	void renderRoom(sf::RenderTarget& target);

	void randomEnemy(); //inside updateInsideRoom fun in case2: 
	void randomTrap(); //inside --||-- in case 3:

	void render(sf::RenderTarget& target);
};

