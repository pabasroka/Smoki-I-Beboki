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
	this->randNumber = rand() % 100;
	if (this->randNumber >= 0 && this->randNumber <= 15)
	{
		this->roomType = static_cast<int>(RoomType::Empty);
		this->roomSpriteSrc = sf::IntRect(15 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (this->randNumber > 15 && this->randNumber <= 30)
	{
		this->roomType = static_cast<int>(RoomType::Treasure);
		this->roomSpriteSrc = sf::IntRect(25 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);		
	}
	else if (this->randNumber > 30 && this->randNumber <= 70)
	{
		this->roomType = static_cast<int>(RoomType::Enemy);
		this->roomSpriteSrc = sf::IntRect(35 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (this->randNumber > 70 && this->randNumber <= 85)
	{
		this->roomType = static_cast<int>(RoomType::Trap);
		this->roomSpriteSrc = sf::IntRect(45 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (this->randNumber > 85 && this->randNumber <= 90)
	{
		this->roomType = static_cast<int>(RoomType::Back);
		this->roomSpriteSrc = sf::IntRect(55 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (this->randNumber > 90 && this->randNumber <= 95)
	{
		this->roomType = static_cast<int>(RoomType::Mystery);
		this->roomSpriteSrc = sf::IntRect(65 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (this->randNumber > 95 && this->randNumber <= 100)
	{
		this->roomType = static_cast<int>(RoomType::Healing);
		this->roomSpriteSrc = sf::IntRect(75 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}

	std::cout << "Wylosowany numer: " << this->randNumber << " \n";
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

void Room::setRoomType(int type)
{
	this->roomType = type;
}

void Room::combat(Player& player)
{
	//Init enemy stats
	this->enemyDmg = player.getProperties(9) * 35;
	this->enemyHp = player.getProperties(9) + 10;

	//Init player stats
	this->playerDmg = player.getProperties(1);
	this->playerArmor = 0.7 + (player.getProperties(2) * 0.1);
	this->critChance = (player.getProperties(3) * 25) / (player.getProperties(9) * 2) + 25;
	this->escapeChance = (player.getProperties(3) * 25) / (player.getProperties(9) * 2) + 40;
	this->combatHealth = player.getProperties(4) * this->playerArmor;

	std::cout << "\n dmg: " << this->playerDmg << std::endl;
	std::cout << "combat health: " << this->combatHealth << std::endl;

	while (this->enemyHp > 0)
	{
		if (this->combatHealth <= 0)
			player.setProperties(4, -100);

		if (this->randNumber >= 20 && this->randNumber <= 40)
		{
			// crit damage
			std::cout << "\n CRIT \n";
			this->enemyHp -= this->playerDmg + player.getProperties(9);
		}
		else if (this->randNumber > 50)
		{
			std::cout << "\n CRIT \n";
			this->enemyHp -= this->playerDmg + player.getProperties(9);
		}
		else
		{
			this->enemyHp -= this->playerDmg;
		}

		this->combatHealth -= this->enemyDmg;
		this->totalDamageTaken += this->enemyDmg;

		std::cout << "enemy hp: " << this->enemyHp << std::endl;
		std::cout << "hp: " << this->combatHealth << std::endl;
	}
	std::cout << "total damage taken: " << this->totalDamageTaken << std::endl;

	player.setProperties(4, -(this->totalDamageTaken/this->playerArmor));

	player.setProperties(10, rand() % 50 + 45); //exp 
	player.setProperties(8, rand() % 5 + 1); //coins 
}

void Room::action(int roomType, Player& player)
{
	// 1-dmg 2-armor 3-luck 4-hp 5-hpMax 6-SP 7-keys 8-coins 9-lvl 10-exp 11-expMax 12-doorCounter
	switch (this->roomType)
	{
	case 0: //empty
		player.setProperties(12, 1);
		break;
	case 1: //trasure
		player.setProperties(12, 1);
		player.setProperties(8, (rand() % 14 + 7));
		break;
	case 2: //enemy
		this->combat(player);
		player.setProperties(12, 1); // counter++
		player.setProperties(7, 1); // key++

		break;
	case 3: //trap
		player.setProperties(12, 1);
		player.setProperties(4, -(rand() % 65 + 45));
		player.setProperties(10, 10);
		break;
	case 4: //back
		//this->sBack.play();
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

void Room::escape(int roomType, Player& player)
{
	// 1-dmg 2-armor 3-luck 4-hp 5-hpMax 6-SP 7-keys 8-coins 9-lvl 10-exp 11-expMax 12-doorCounter
	switch (this->roomType)
	{
	case 0: //empty
		player.setProperties(12, 1);
		break;
	case 1: //trasure
		player.setProperties(12, 1);
		break;
	case 2: //enemy
		player.setProperties(12, 1); // counter++
		std::cout << "escape \n";
		//chance to avoid enemy
		this->escapeChance = (player.getProperties(3) * 0.2 / player.getProperties(9)) * 100 + 10;
		this->randNumber = rand() % static_cast<int>(this->escapeChance);
		if (this->randNumber >= 0 && this->randNumber <= 20)
		{
			//bonus damage taken as punishment for unlucky escape
			std::cout << "\n niepowodzenie \n";
			this->combat(player);
			player.setProperties(7, 1);
			player.setProperties(4, -50); 
		}
		else if (this->randNumber > 40 && this->randNumber <= 50)
		{
			std::cout << "\n niepowodzenie \n";
			this->combat(player);
			player.setProperties(7, 1);
			player.setProperties(4, -50);
		}

		break;
	case 3: //trap
		player.setProperties(12, 1);

		//chance to avoid trap
		this->escapeChance = (player.getProperties(3) * 0.2 / player.getProperties(9)) * 100 + 10;
		this->randNumber = rand() % static_cast<int>(this->escapeChance);
		if (this->randNumber >= 0 && this->randNumber <= 20)
		{
			//bonus damage taken as punishment for unlucky escape
			std::cout << "\n niepowodzenie \n";
			player.setProperties(4, -(rand() % 100 + 75));
		}
		else if (this->randNumber > 40 && this->randNumber <= 50)
		{
			std::cout << "\n niepowodzenie \n";
			player.setProperties(4, -(rand() % 100 + 75));
		}

		break;
	case 4: //back
		player.setProperties(12, -1);
		break;
	case 5: //rand
		player.setProperties(12, 1);
		break;
	case 6: //heal
		player.setProperties(12, 1);
		break;
	default:
		std::cout << "There are no rooms of this type \n";
		break;
	}
}
