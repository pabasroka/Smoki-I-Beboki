#include "UI.h"

void UI::initVariables()
{
	this->unitSize = 16;
	this->arrowTimerMax = 35;
	this->arrowTimer = this->arrowTimerMax;
	this->inputTimerMax = 25;
	this->inputTimer = this->inputTimerMax;
	this->expIncrease = 8; // when you divide screen width(800) / 100(maxExp you can gain at first lvl) you got 8
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

	//Set the main view screen
	this->gameView.setTexture(this->gameTextures);

	//Set the properties
	this->gameViewSrc = sf::IntRect(0, 17 * this->unitSize, 800, 30 * this->unitSize);
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
	this->upgradeShield.setTexture(this->gameTextures);
	this->heart.setTexture(this->gameTextures);
	this->fist.setTexture(this->gameTextures);
	this->upgradeFist.setTexture(this->gameTextures);
	this->clover.setTexture(this->gameTextures);
	this->upgradeClover.setTexture(this->gameTextures);
	this->key.setTexture(this->gameTextures);
	this->coin.setTexture(this->gameTextures);
	this->door.setTexture(this->gameTextures);
	this->skillPoints.setTexture(this->gameTextures);


	/*=================		GRAPHICAL USER INTERFACE	===================*/

	//Set the properties
	this->guiSrc = sf::IntRect(0, 48 * this->unitSize, 800, 20 * this->unitSize);
	this->gui.setTextureRect(guiSrc);
	this->gui.setPosition(sf::Vector2f(0, 30.f * this->unitSize));
	this->gui.setScale(1.f, 1.f);

	//Arrows
	this->arrowsSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowR.setTextureRect(arrowsSrc);
	this->arrowR.setScale(5.f, 5.f);
	this->arrowR.setPosition(sf::Vector2f(25 * this->unitSize, 18 * this->unitSize));

	this->arrowLSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowL.setTextureRect(arrowLSrc);
	this->arrowL.setScale(-5.f, 5.f);
	this->arrowL.setPosition(sf::Vector2f(24 * this->unitSize, 18 * this->unitSize));

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

	this->upgradeShieldSrc = sf::IntRect(3 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeShield.setTextureRect(upgradeShieldSrc);
	this->upgradeShield.setScale(5.f, 5.f);
	this->upgradeShield.setPosition(sf::Vector2f(13 * this->unitSize, 37 * this->unitSize));

	//Heart
	this->heartSrc = sf::IntRect(4 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->heart.setTextureRect(heartSrc);
	this->heart.setScale(5.f, 5.f);
	this->heart.setPosition(sf::Vector2f(12.8 * this->unitSize, 23.5 * this->unitSize));

	//Fist
	this->fistSrc = sf::IntRect(5 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->fist.setTextureRect(fistSrc);
	this->fist.setScale(5.f, 5.f);
	this->fist.setPosition(sf::Vector2f(1 * this->unitSize, 31 * this->unitSize));

	this->upgradeFistSrc = sf::IntRect(5 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeFist.setTextureRect(upgradeFistSrc);
	this->upgradeFist.setScale(5.f, 5.f);
	this->upgradeFist.setPosition(sf::Vector2f(13 * this->unitSize, 31 * this->unitSize));

	//Clover
	this->cloverSrc = sf::IntRect(6 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->clover.setTextureRect(cloverSrc);
	this->clover.setScale(5.f, 5.f);
	this->clover.setPosition(sf::Vector2f(1 * this->unitSize, 43 * this->unitSize));

	this->upgradeCloverSrc = sf::IntRect(6 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeClover.setTextureRect(upgradeCloverSrc);
	this->upgradeClover.setScale(5.f, 5.f);
	this->upgradeClover.setPosition(sf::Vector2f(13 * this->unitSize, 43 * this->unitSize));

	//Skill points
	this->skillPointsSrc = sf::IntRect(9 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->skillPoints.setTextureRect(skillPointsSrc);
	this->skillPoints.setScale(5.f, 5.f);
	this->skillPoints.setPosition(sf::Vector2f(25 * this->unitSize, 31 * this->unitSize));

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
	this->expBarBg.setSize(sf::Vector2f(800.f, 20.f));
	this->expBarBg.setFillColor(sf::Color(155, 135, 12, 255));
	this->expBarBg.setPosition(sf::Vector2f(0, 780));

	this->expBar.setFillColor(sf::Color::Yellow);
	this->expBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(10)) * 20.f, 20.f));
	this->expBar.setPosition(sf::Vector2f(0, 780));

	//Door counter
	this->doorSrc = sf::IntRect(10 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->door.setTextureRect(doorSrc);
	this->door.setScale(4.f, 4.f);
	this->door.setPosition(sf::Vector2f(0 * this->unitSize, 25 * this->unitSize));
	
	//Hp Bar
	this->hpBarBg.setSize(sf::Vector2f(400.f, 40.f));
	this->hpBarBg.setFillColor(sf::Color(255, 150, 150, 255));
	this->hpBarBg.setOutlineColor(sf::Color(255, 50, 50, 255));
	this->hpBarBg.setOutlineThickness(3.f);
	this->hpBarBg.setPosition(sf::Vector2f(13 * this->unitSize, 25 * this->unitSize));

	this->hpBar.setSize(sf::Vector2f(400.f, 40.f));
	this->hpBar.setFillColor(sf::Color(255, 50, 50, 255));
	this->hpBarBg.setOutlineColor(sf::Color(255, 0, 0, 255));
	this->hpBarBg.setOutlineThickness(6.f);
	this->hpBar.setPosition(sf::Vector2f(13 * this->unitSize, 25 * this->unitSize));

}

void UI::initText()
{
	//Set LVL font and properties
	this->lvlTxt.setFont(font);
	this->lvlTxt.setCharacterSize(40);
	this->lvlTxt.setFillColor(sf::Color::White);
	this->lvlTxt.setOutlineColor(sf::Color::Black);
	this->lvlTxt.setOutlineThickness(3.f);
	this->lvlTxt.setPosition(680, 735);

	this->fistTxt = lvlTxt;
	this->fistTxt.setCharacterSize(60);
	this->fistTxt.setPosition(sf::Vector2f(7 * this->unitSize, 31 * this->unitSize));

	this->shieldTxt = fistTxt;
	this->shieldTxt.setPosition(sf::Vector2f(7 * this->unitSize, 37 * this->unitSize));

	this->cloverTxt = fistTxt;
	this->cloverTxt.setPosition(sf::Vector2f(7 * this->unitSize, 43 * this->unitSize));

	this->skillPointsTxt = fistTxt;
	this->skillPointsTxt.setPosition(sf::Vector2f(31 * this->unitSize, 31 * this->unitSize));

	this->coinTxt = fistTxt;
	this->coinTxt.setPosition(sf::Vector2f(31 * this->unitSize, 37 * this->unitSize));

	this->keyTxt = fistTxt;
	this->keyTxt.setPosition(sf::Vector2f(31 * this->unitSize, 43 * this->unitSize));

	this->doorTxt = fistTxt;
	this->doorTxt.setCharacterSize(40);
	this->doorTxt.setPosition(sf::Vector2f(4 * this->unitSize, 26 * this->unitSize));
}

UI::UI()
{
	this->player = new Player;

	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initText();
	this->update();
	this->updateText();
}

UI::~UI()
{
	delete this->player;
}

void UI::input()
{
	//Arrow right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && arrowTimer >= arrowTimerMax)
	{
		std::cout << "prawo";
		this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize);
		this->arrowR.setTextureRect(arrowsSrc);
		arrowTimer = 0;
	}
	//Arrow left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && arrowTimer >= arrowTimerMax)
	{
		std::cout << "lewo";
		this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize);
		this->arrowL.setScale(-5.f, 5.f);
		this->arrowL.setTextureRect(arrowsSrc);
		arrowTimer = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->player->getProperties(6) >= 1 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(6, -1);
		this->player->setProperties(2, 1);
		inputTimer = 0;
		this->upgradeShieldSrc = sf::IntRect(3 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeShield.setTextureRect(upgradeShieldSrc);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->player->getProperties(6) >= 1 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(6, -1);
		this->player->setProperties(1, 1);
		inputTimer = 0;
		this->upgradeFistSrc = sf::IntRect(5 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeFist.setTextureRect(upgradeFistSrc);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && this->player->getProperties(6) >= 1 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(6, -1);
		this->player->setProperties(3, 1);
		inputTimer = 0;
		this->upgradeCloverSrc = sf::IntRect(6 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeClover.setTextureRect(upgradeCloverSrc);
	}

	/* ==================================== dev tools ==================================== */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		this->player->setProperties(4, -1000);
		this->hpBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(4) * 0.4), 40.f)); // 0.4 -> hbbarwidth/hpMax 400/1000 = 0.4 
		std::cout << "Hp: " << this->player->getProperties(4) << "\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		std::cout << "exp + 10";
		this->player->setProperties(10, rand() % 25 + 5); //(10,10)
		std::cout << "Exp: " << this->player->getProperties(10);

		if (this->player->getProperties(10) >= this->player->getProperties(11))
		{
			this->expBar.setSize(sf::Vector2f(0.f, 20.f));
			this->expIncrease = 800 / this->player->getProperties(11);
		}
		else
			this->expBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(10) * this->expIncrease), 20.f));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		this->player->setProperties(1, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		this->player->setProperties(6, 10);
		this->player->setProperties(9, 50);
	}

}

bool UI::isDead()
{
	return this->player->isDead();
}

void UI::update()
{
	if (this->arrowTimer < this->arrowTimerMax) //Incement timer 
	{
		arrowTimer++;
	}
	if (this->inputTimer < this->inputTimerMax) //Incement timer 
	{
		inputTimer++;
	}
	if (this->arrowTimer == this->arrowTimerMax) //Back to unactive arrows sprite
	{
		this->arrowsSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
		this->arrowR.setTextureRect(arrowsSrc);
		this->arrowL.setTextureRect(arrowsSrc);
	}
	if (this->inputTimer == this->inputTimerMax) //Back to unactive upgrade sprites
	{
		this->upgradeShieldSrc = sf::IntRect(3 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeShield.setTextureRect(upgradeShieldSrc);
		this->upgradeFistSrc = sf::IntRect(5 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeFist.setTextureRect(upgradeFistSrc);
		this->upgradeCloverSrc = sf::IntRect(6 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeClover.setTextureRect(upgradeCloverSrc);
	}

	

	this->updateText();
	this->player->levelUp();
	this->player->isDead();

	this->input();
}

void UI::updateText()
{
	this->fistTxt.setString(std::to_string(player->getProperties(1)));
	this->shieldTxt.setString(std::to_string(player->getProperties(2)));
	this->cloverTxt.setString(std::to_string(player->getProperties(3)));
	this->skillPointsTxt.setString(std::to_string(player->getProperties(6)));
	this->coinTxt.setString(std::to_string(player->getProperties(8)));
	this->keyTxt.setString(std::to_string(player->getProperties(7)));
	this->lvlTxt.setString("Lvl: " + std::to_string(player->getProperties(9)));
	this->doorTxt.setString(std::to_string(player->getProperties(12)));
}

void UI::renderGV(sf::RenderTarget& target) //Game view
{
	target.draw(this->gameView);
}

void UI::renderGUI(sf::RenderTarget& target) // Graphical User Interface
{
	target.draw(this->gui);
	target.draw(this->arrowR);
	target.draw(this->arrowL);
	//target.draw(this->upgrade);
	target.draw(this->sword);
	target.draw(this->shield);	
	target.draw(this->upgradeShield);
	target.draw(this->fist);
	target.draw(this->upgradeFist);
	target.draw(this->clover);
	target.draw(this->upgradeClover);
	target.draw(this->skillPoints);
	target.draw(this->coin);
	target.draw(this->key);
	target.draw(this->expBarBg);	
	target.draw(this->expBar);	
	target.draw(this->door);	
	target.draw(this->hpBarBg);	
	target.draw(this->hpBar);	
	target.draw(this->heart);
}

void UI::renderText(sf::RenderTarget& target)
{
	target.draw(this->fistTxt);
	target.draw(this->shieldTxt);
	target.draw(this->cloverTxt);
	target.draw(this->skillPointsTxt);
	target.draw(this->coinTxt);
	target.draw(this->keyTxt);
	target.draw(this->lvlTxt);
	target.draw(this->doorTxt);
}

void UI::render(sf::RenderTarget& target)
{
	this->renderGV(target);
	this->renderGUI(target);
	this->renderText(target);
}
