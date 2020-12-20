#include "Room.h"

void Room::initVariables()
{
	if (!this->gameTextures.loadFromFile("Textures/rpgSprites2.png"))
		std::cout << "Could not load rpgSprites2.png file \n";

	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		std::cout << "Could not load font \n";

	this->roomSprite.setTexture(this->gameTextures);

	this->unitSize = 16;

	this->text.setString("");
	this->text.setFont(font);
	this->text.setCharacterSize(50);
	this->text.setFillColor(sf::Color::White);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(3.f);
	this->text.setPosition(180, 20);
}

void Room::randomGenerator()
{
	randNumber = rand() % 100;
	if (randNumber >= 0 && randNumber <= 15)
	{
		this->roomType = static_cast<int>(RoomType::Empty);
		this->roomSpriteSrc = sf::IntRect(15 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 15 && randNumber <= 30)
	{
		this->roomType = static_cast<int>(RoomType::Treasure);
		this->roomSpriteSrc = sf::IntRect(25 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);		
	}
	else if (randNumber > 30 && randNumber <= 70)
	{
		this->roomType = static_cast<int>(RoomType::Enemy);
		this->roomSpriteSrc = sf::IntRect(35 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 70 && randNumber <= 85)
	{
		this->roomType = static_cast<int>(RoomType::Trap);
		this->roomSpriteSrc = sf::IntRect(45 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 85 && randNumber <= 90)
	{
		this->roomType = static_cast<int>(RoomType::Back);
		this->roomSpriteSrc = sf::IntRect(55 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 90 && randNumber <= 95)
	{
		this->roomType = static_cast<int>(RoomType::Mystery);
		this->roomSpriteSrc = sf::IntRect(65 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 95 && randNumber <= 100)
	{
		this->roomType = static_cast<int>(RoomType::Healing);
		this->roomSpriteSrc = sf::IntRect(75 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}

	std::cout << "Wylosowany numer: " << randNumber << " \n";
	this->roomSprite.setTextureRect(this->roomSpriteSrc);
}

Room::Room()
{
	this->initVariables();
	this->randomGenerator();
}

Room::~Room()
{
}

const int Room::getRoomType() const
{
	return this->roomType;
}

const sf::Sprite Room::getSprite() const
{
	return this->roomSprite;
}

void Room::setPosition(sf::Vector2f pos)
{
	this->roomSprite.setPosition(sf::Vector2f(pos.x, pos.y));
}

void Room::combat(Player& player)
{
	// ======= TO DO ========
	//Init enemy stats
	this->enemyDmg = player.getProperties(9) * 15;
	this->enemyHp = player.getProperties(9) + 10;

	//Init player stats
	this->playerDmg = player.getProperties(1);
	this->playerArmor = 1 + (player.getProperties(2) * 0.1);
	this->critChance = (player.getProperties(3) * 25) / (player.getProperties(9) * 2) + 25;
	this->escapeChance = (player.getProperties(3) * 25) / (player.getProperties(9) * 2) + 40;
	this->combatHealth = player.getProperties(4) * this->playerArmor;

	std::cout << "\n dmg: " << this->playerDmg << std::endl;
	std::cout << "combat health: " << this->combatHealth << std::endl;

	while (this->enemyHp > 0)
	{
		if (this->combatHealth <= 0)
			player.setProperties(4, -100);

		this->combatHealth -= this->enemyDmg;
		this->enemyHp -= this->playerDmg;
		this->totalDamageTaken += this->enemyDmg;

		std::cout << "enemy hp: " << this->enemyHp << std::endl;
		std::cout << "hp: " << this->combatHealth << std::endl;
	}
	std::cout << "total damage taken: " << this->totalDamageTaken << std::endl;

	//this->combatHealth -= this->totalDamageTaken;
	
	//player.setProperties(4, -player.getProperties(4));
	player.setProperties(4, -this->totalDamageTaken);

	//player.setHP(this->combatHealth);

	//this->coinsDrop = player.getProperties(9) + 5;

	player.setProperties(10, rand() % 50 + 45); //exp 
	player.setProperties(8, rand() % 5 + 1); //coins 
}

sf::Text Room::displayText()
{
	switch (this->roomType)
	{
	case 0:
		this->text.setString("");
		return this->text;
		break;
	case 1:
		this->text.setString("");
		return this->text;
		break;
	case 2:
		this->text.setString("");
		return this->text;
		break;
	case 3:
		this->text.setString("");
		return this->text;
		break;
	case 4:
		this->text.setString("");
		return this->text;
		break;
	case 5:
		this->text.setString("");
		return this->text;
	case 6:
		this->text.setString("");
		return this->text;
		break;
	}
}


void Room::update(int roomType, Player& player)
{
	// 1-dmg 2-armor 3-luck 4-hp 5-hpMax 6-SP 7-keys 8-coins 9-lvl 10-exp 11-expMax 12-doorCounter
	switch (this->roomType)
	{
	case 0: //empty
		player.setProperties(12, 1);
		break;
	case 1: //trasure
		player.setProperties(12, 1);
		player.setProperties(8, rand() % 14 + 7);
		break;
	case 2: //enemy
		this->combat(player);

		player.setProperties(12, 1); // counter++
		player.setProperties(7, 1); // key++

		/*player.setProperties(4, -100);
		player.setProperties(10, 20);
		*/
		break;
	case 3: //trap
		player.setProperties(12, 1);
		player.setProperties(4, -50);
		player.setProperties(10, 10);
		break;
	case 4: //back
		player.setProperties(12, -1);
		break;
	case 5: //rand
		player.setProperties(12, 1);
		break;
	case 6: //heal
		player.setProperties(12, 1);
		if (player.getProperties(4) < player.getProperties(5))
			player.setProperties(4, 200 - player.getProperties(9) * 2);

		if (player.getProperties(4) >= player.getProperties(5))
		{
			player.setProperties(4, -player.getProperties(4));
			player.setProperties(4, player.getProperties(5));
		}
		break;
	default:
		std::cout << "There are no rooms of this type \n";
		break;
	}
}
