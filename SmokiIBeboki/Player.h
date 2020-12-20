#pragma once
#include<iostream>

class Player
{
private:
	//Properties / number
	float dmg; //1
	float armor; //2
	float luck; //3
	float hp; //4
	int hpMax; //5
	int skillPoints; //6
	int keys; //7
	int coins; //8
	int lvl; //9
	int exp; //10
	int expMax; //11
	int doorCounter; //12


	void initVariables();
public:
	Player();
	virtual ~Player();

	//Getters
	const int getProperties(int type) const;
	void setHP(int value);

	//Setters
	void setProperties(int type, int value = 0);

	//Functions
	void levelUp();
	const bool isDead() const;

	void update();
};

