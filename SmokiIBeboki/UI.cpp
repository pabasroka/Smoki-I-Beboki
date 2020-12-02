#include "UI.h"

void UI::initTextures()
{
	//Load textures from file
	if (!this->texture.loadFromFile("Textures/rpgSprites.png"))
		std::cout << "Could not load rpgSprites.png file \n";
}

void UI::initSprites()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Set the properties
	this->spriteSrc = sf::IntRect(0, 0, 16, 16);
	this->sprite.setTextureRect(spriteSrc);
	this->sprite.setScale(10.f, 10.f);
}

UI::UI()
{
	this->initTextures();
	this->initSprites();
}

UI::~UI()
{
}

void UI::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
