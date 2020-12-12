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
	else if (randNumber > 30 && randNumber <= 60)
	{
		this->roomType = static_cast<int>(RoomType::Enemy);
		this->roomSpriteSrc = sf::IntRect(35 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 60 && randNumber <= 75)
	{
		this->roomType = static_cast<int>(RoomType::Trap);
		this->roomSpriteSrc = sf::IntRect(45 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 75 && randNumber <= 90)
	{
		this->roomType = static_cast<int>(RoomType::Back);
		this->roomSpriteSrc = sf::IntRect(55 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
	}
	else if (randNumber > 90 && randNumber <= 100)
	{
		this->roomType = static_cast<int>(RoomType::Mystery);
		this->roomSpriteSrc = sf::IntRect(65 * this->unitSize, 0, 9 * this->unitSize, 16 * this->unitSize);
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

const int Room::getRoomType(int type) const
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

sf::Text Room::displayText()
{
	switch (this->roomType)
	{
	case 0:
		this->text.setString("Licznik pokoi -1");
		return this->text;
		break;
	case 1:
		this->text.setString("2");
		return this->text;
		break;
	case 2:
		this->text.setString("3");
		return this->text;
		break;
	case 3:
		this->text.setString("4");
		return this->text;
		break;
	case 4:
		this->text.setString("5");
		return this->text;
		break;
	case 5:
		this->text.setString("6");
		return this->text;
		break;
	}
}

void Room::update(Player& player)
{
	switch (this->roomType)
	{
	case 0:
		player.setProperties(12, -1);
		break;
	case 1:
		player.setProperties(12, -1);
		break;
	case 2:
		player.setProperties(12, -1);
		break;
	case 3:
		player.setProperties(12, -1);
		break;
	case 4:
		player.setProperties(12, -1);
		break;
	case 5:
		player.setProperties(12, -1);
		break;
	default:
		std::cout << "There are no rooms of this type \n";
		break;
	}
}
