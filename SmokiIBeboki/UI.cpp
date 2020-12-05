#include "UI.h"

void UI::initVariables()
{
	this->unitSize = 16;
	this->arrowTimerMax = 35;
	this->arrowTimer = arrowTimerMax;
}

void UI::initTextures()
{
	//Load textures from file
	if (!this->texture.loadFromFile("Textures/rpgSprites.png"))
		std::cout << "Could not load rpgSprites.png file \n";

	if (!this->gameTextures.loadFromFile("Textures/rpgSprites2.png"))
		std::cout << "Could not load rpgSprites2.png file \n";
	
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		std::cout << "Could not load font \n";
}

void UI::initSprites()
{
	/*=================		MAIN VIEW	===================*/
	//Set LVL font and properties
	this->lvl.setFont(font);
	this->lvl.setCharacterSize(60);
	this->lvl.setFillColor(sf::Color::White);
	this->lvl.setOutlineColor(sf::Color::Black);
	this->lvl.setOutlineThickness(3.f);
	this->lvl.setString("1"); //(class)Player -> lvl; also update in update() function this->lvl.setString(player->lvl);
	this->lvl.setPosition(730, 700);

	//Set the main view screen
	this->gameView.setTexture(this->gameTextures);

	//Set the properties
	this->gameViewSrc = sf::IntRect(0, 11 * this->unitSize, 800, 30 * this->unitSize);
	this->gameView.setTextureRect(gameViewSrc);
	this->gameView.setScale(1.f, 1.f);

	//Set the main view screen
	this->gui.setTexture(this->gameTextures);
	this->arrowR.setTexture(this->gameTextures);
	this->arrowL.setTexture(this->gameTextures);
	this->arrowRAction.setTexture(this->gameTextures);
	this->arrowLAction.setTexture(this->gameTextures);
	this->upgrade.setTexture(this->gameTextures);
	this->sword.setTexture(this->gameTextures);
	this->shield.setTexture(this->gameTextures);
	this->heart.setTexture(this->gameTextures);
	this->fist.setTexture(this->gameTextures);
	this->clover.setTexture(this->gameTextures);
	this->key.setTexture(this->gameTextures);
	this->coin.setTexture(this->gameTextures);


	/*=================		GRAPHICAL USER INTERFACE	===================*/

	//Set the properties
	this->guiSrc = sf::IntRect(0, 41 * this->unitSize, 800, 20 * this->unitSize);
	this->gui.setTextureRect(guiSrc);
	this->gui.setPosition(sf::Vector2f(0, 30.f * this->unitSize));
	this->gui.setScale(1.f, 1.f);

	//Arrows
	this->arrowsSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowR.setTextureRect(arrowsSrc);
	this->arrowR.setScale(5.f, 5.f);
	this->arrowR.setPosition(sf::Vector2f(25 * this->unitSize, 25 * this->unitSize));

	this->arrowLSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowL.setTextureRect(arrowLSrc);
	this->arrowL.setScale(-5.f, 5.f);
	this->arrowL.setPosition(sf::Vector2f(24 * this->unitSize, 25 * this->unitSize));

	//Upgrade mark
	this->upgradeSrc = sf::IntRect(this->unitSize, 0, this->unitSize, this->unitSize);
	this->upgrade.setTextureRect(upgradeSrc);
	this->upgrade.setScale(3.f, 3.f);
	this->upgrade.setPosition(sf::Vector2f(10 * this->unitSize, 32 * this->unitSize));

	//Sword
	this->swordSrc = sf::IntRect(2 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->sword.setTextureRect(swordSrc);
	this->sword.setScale(5.f, 5.f);
	this->sword.setPosition(sf::Vector2f(20 * this->unitSize, 5 * this->unitSize));

	//Shield
	this->shieldSrc = sf::IntRect(3 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->shield.setTextureRect(shieldSrc);
	this->shield.setScale(5.f, 5.f);
	this->shield.setPosition(sf::Vector2f(1 * this->unitSize, 37 * this->unitSize));

	//Heart
	this->heartSrc = sf::IntRect(4 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->heart.setTextureRect(heartSrc);
	this->heart.setScale(7.f, 7.f);
	this->heart.setPosition(sf::Vector2f(20 * this->unitSize, 20 * this->unitSize));

	//Fist
	this->fistSrc = sf::IntRect(5 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->fist.setTextureRect(fistSrc);
	this->fist.setScale(5.f, 5.f);
	this->fist.setPosition(sf::Vector2f(1 * this->unitSize, 31 * this->unitSize));

	//Clover
	this->cloverSrc = sf::IntRect(6 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->clover.setTextureRect(cloverSrc);
	this->clover.setScale(5.f, 5.f);
	this->clover.setPosition(sf::Vector2f(1 * this->unitSize, 43 * this->unitSize));

	//Coin
	this->coinSrc = sf::IntRect(7 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->coin.setTextureRect(coinSrc);
	this->coin.setScale(5.f, 5.f);
	this->coin.setPosition(sf::Vector2f(25 * this->unitSize, 37 * this->unitSize));

	//Key
	this->keySrc = sf::IntRect(8 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->key.setTextureRect(keySrc);
	this->key.setScale(5.f, 5.f);
	this->key.setPosition(sf::Vector2f(25 * this->unitSize, 43 * this->unitSize));

	//EXP BAR
	this->expBar.setSize(sf::Vector2f(800.f, 20.f));
	this->expBar.setFillColor(sf::Color(155, 135, 12, 255));
	this->expBar.setPosition(sf::Vector2f(0, 780));
}

UI::UI()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->update();
}

UI::~UI()
{
}

void UI::input()
{
	//Arrow right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && arrowTimer >= arrowTimerMax)
	{
		std::cout << "ee";
		this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize);
		this->arrowR.setTextureRect(arrowsSrc);
		arrowTimer = 0;
	}
	//Arrow left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && arrowTimer >= arrowTimerMax)
	{
		std::cout << "ee";
		this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize);
		this->arrowL.setScale(-5.f, 5.f);
		this->arrowL.setTextureRect(arrowsSrc);
		arrowTimer = 0;
	}
}

void UI::update()
{
	if (arrowTimer < arrowTimerMax) //Incement timer 
	{
		arrowTimer++;
	}
	if (arrowTimer == arrowTimerMax) //Back to unactive arrows sprite
	{
		this->arrowsSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
		this->arrowR.setTextureRect(arrowsSrc);
		this->arrowL.setTextureRect(arrowsSrc);
	}
		

	this->input();
}

void UI::renderGV(sf::RenderTarget& target)
{
	target.draw(this->gameView);
}

void UI::renderGUI(sf::RenderTarget& target)
{
	target.draw(this->gui);
	target.draw(this->arrowR);
	target.draw(this->arrowL);
	target.draw(this->upgrade);
	target.draw(this->sword);
	target.draw(this->shield);
	target.draw(this->heart);
	target.draw(this->fist);
	target.draw(this->clover);
	target.draw(this->coin);
	target.draw(this->key);
	target.draw(this->expBar);
	target.draw(this->lvl);
}
