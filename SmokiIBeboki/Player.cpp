#include "Player.h"

void Player::initVariables()
{
	this->dmg = 1;
	this->armor = 1;
	this->hpMax = 1000;
	this->hp = this->hpMax;
	this->luck = 1;
	this->skillPoints = 10; //10
	this->keys = 0; //0
	this->coins = 10; //10
	this->lvl = 1;
	this->expMax = 100; //every level increased by 10
	this->exp = 0;
	this->doorCounter = 0;
}

Player::Player()
{
	this->initVariables();
}

Player::~Player()
{
}

const int Player::getProperties(int type) const
{
	switch (type)
	{
	case 1:
		//return Player::dmg;
		return this->dmg;
		break;
	case 2:
		return this->armor;
		break;
	case 3:
		return this->luck;
		break;
	case 4:
		return this->hp;
		break;
	case 5:
		return this->hpMax;
		break;
	case 6:
		return this->skillPoints;
		break;
	case 7:
		return this->keys;
		break;
	case 8:
		return this->coins;
		break;
	case 9:
		return this->lvl;
		break;
	case 10:
		return this->exp;
		break;
	case 11:
		return this->expMax;
		break;
	case 12:
		return this->doorCounter;
		break;
	default:
		return 0;
		break;
	}
}

void Player::setHP(int value)
{
	this->hp = value;
}

void Player::setProperties(int type, int value)
{
	switch (type)
	{
	case 1:
		this->dmg += value;
		break;
	case 2:
		this->armor += value;
		break;
	case 3:
		this->luck += value;
		break;
	case 4:
		this->hp += value;
		break;
	case 5:
		this->hpMax += value;
		break;
	case 6:
		this->skillPoints += value;
		break;
	case 7:
		this->keys += value;
		break;
	case 8:
		this->coins += value;
		break;
	case 9:
		this->lvl += value;
		break;
	case 10:
		this->exp += value;
		break;
	case 11:
		this->expMax += value;
		break;
	case 12:
		this->doorCounter += value;
		break;
	default:
		std::cout << "Something went wrong \n";
		break;
	}
}

void Player::levelUp()
{
	if (this->exp >= this->expMax)
	{
		this->exp = 0;
		this->lvl++;
		this->skillPoints += 3;
		this->expMax += 10;
	}
}

const bool Player::isDead() const
{
	if (this->hp <= 0)
	{
		return true;
	}
	return false;
}

void Player::update()
{
	this->levelUp();
}
