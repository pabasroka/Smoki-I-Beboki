#include "UI.h"

void UI::initSounds()
{
	this->bHealing.loadFromFile("Sound/healing.ogg");
	this->sHealing.setBuffer(this->bHealing);

	//this->bBack.loadFromFile("Sound/back.ogg");
	//this->sBack.setBuffer(this->bBack);

	this->bDead.loadFromFile("Sound/dead.ogg");
	this->sDead.setBuffer(this->bDead);

	this->bEmpty.loadFromFile("Sound/empty.ogg");
	this->sEmpty.setBuffer(this->bEmpty);

	this->bEnemy.loadFromFile("Sound/enemy.ogg");
	this->sEnemy.setBuffer(this->bEnemy);

	this->bEscape.loadFromFile("Sound/escape.ogg");
	this->sEscape.setBuffer(this->bEscape);

	this->bSecret.loadFromFile("Sound/secret.ogg");
	this->sSecret.setBuffer(this->bSecret);

	this->bTrap.loadFromFile("Sound/trap.ogg");
	this->sTrap.setBuffer(this->bTrap);

	this->bTreasure.loadFromFile("Sound/treasure.ogg");
	this->sTreasure.setBuffer(this->bTreasure);
}

void UI::initVariables()
{
	this->unitSize = 16;
	this->arrowTimerMax = 35;
	this->arrowTimer = this->arrowTimerMax;
	this->inputTimerMax = 15;
	this->inputTimer = this->inputTimerMax;
	this->expIncrease = 8; // when you divide screen width(800) / 100(maxExp you can gain at first lvl) you got 8
	this->isInsideRoom = false;
}

void UI::initTextures()
{
	//Load textures from file
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
	this->gameView.setTextureRect(this->gameViewSrc);
	this->gameView.setScale(1.f, 1.f);

	//Set the main view screen
	this->gui.setTexture(this->gameTextures);
	this->arrowR.setTexture(this->gameTextures);
	this->arrowL.setTexture(this->gameTextures);
	this->arrowU.setTexture(this->gameTextures);
	this->arrowD.setTexture(this->gameTextures);
	this->arrowRAction.setTexture(this->gameTextures);
	this->arrowLAction.setTexture(this->gameTextures);
	this->arrowUAction.setTexture(this->gameTextures);
	this->arrowDAction.setTexture(this->gameTextures);
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
	this->upgradeKey.setTexture(this->gameTextures);
	this->coin.setTexture(this->gameTextures);
	this->door.setTexture(this->gameTextures);
	this->skillPoints.setTexture(this->gameTextures);
	this->upgradeSkillPoints.setTexture(this->gameTextures);
	this->insideObject.setTexture(this->gameTextures);
	this->upgradeCost.setTexture(this->gameTextures);
	this->upgradeHp.setTexture(this->gameTextures);


	/*=================		GRAPHICAL USER INTERFACE	===================*/

	//Set the properties
	this->guiSrc = sf::IntRect(0, 47 * this->unitSize, 800, 20 * this->unitSize);
	this->gui.setTextureRect(this->guiSrc);
	this->gui.setPosition(sf::Vector2f(0, 30.f * this->unitSize));
	this->gui.setScale(1.f, 1.f);

	//Arrows
	this->arrowsSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowR.setTextureRect(this->arrowsSrc);
	this->arrowR.setScale(5.f, 5.f);
	this->arrowR.setPosition(sf::Vector2f(25 * this->unitSize, 18 * this->unitSize));

	this->arrowLSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowL.setTextureRect(this->arrowLSrc);
	this->arrowL.setScale(-5.f, 5.f);
	this->arrowL.setPosition(sf::Vector2f(24 * this->unitSize, 18 * this->unitSize));

	this->arrowUSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowU.setTextureRect(this->arrowUSrc);
	this->arrowU.setScale(5.f, 5.f);
	this->arrowU.rotate(-90.f);
	this->arrowU.setPosition(sf::Vector2f(35 * this->unitSize, 10 * this->unitSize));

	this->arrowDSrc = sf::IntRect(0, 0, this->unitSize, this->unitSize);
	this->arrowD.setTextureRect(this->arrowDSrc);
	this->arrowD.setScale(5.f, 5.f);
	this->arrowD.rotate(90.f);
	this->arrowD.setPosition(sf::Vector2f(40 * this->unitSize, 13 * this->unitSize));

	//Upgrade mark
	this->upgradeSrc = sf::IntRect(this->unitSize, 0, this->unitSize, this->unitSize);
	this->upgrade.setTextureRect(this->upgradeSrc);
	this->upgrade.setScale(3.f, 3.f);
	this->upgrade.setPosition(sf::Vector2f(10 * this->unitSize, 32 * this->unitSize));

	//Sword
	this->swordSrc = sf::IntRect(2 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->sword.setTextureRect(this->swordSrc);
	this->sword.setScale(5.f, 5.f);
	this->sword.setPosition(sf::Vector2f(1 * this->unitSize, 31 * this->unitSize));

	//Shield
	this->shieldSrc = sf::IntRect(3 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->shield.setTextureRect(this->shieldSrc);
	this->shield.setScale(5.f, 5.f);
	this->shield.setPosition(sf::Vector2f(1 * this->unitSize, 37 * this->unitSize));

	this->upgradeShieldSrc = sf::IntRect(3 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeShield.setTextureRect(this->upgradeShieldSrc);
	this->upgradeShield.setScale(5.f, 5.f);
	this->upgradeShield.setPosition(sf::Vector2f(13 * this->unitSize, 37 * this->unitSize));

	//Heart
	this->heartSrc = sf::IntRect(4 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->heart.setTextureRect(this->heartSrc);
	this->heart.setScale(5.f, 5.f);
	this->heart.setPosition(sf::Vector2f(12.8 * this->unitSize, 23.5 * this->unitSize));

	//Fist
	this->fistSrc = sf::IntRect(5 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->fist.setTextureRect(this->fistSrc);
	this->fist.setScale(5.f, 5.f);
	this->fist.setPosition(sf::Vector2f(1 * this->unitSize, 31 * this->unitSize));

	this->upgradeFistSrc = sf::IntRect(5 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeFist.setTextureRect(this->upgradeFistSrc);
	this->upgradeFist.setScale(5.f, 5.f);
	this->upgradeFist.setPosition(sf::Vector2f(13 * this->unitSize, 31 * this->unitSize));

	//Clover
	this->cloverSrc = sf::IntRect(6 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->clover.setTextureRect(this->cloverSrc);
	this->clover.setScale(5.f, 5.f);
	this->clover.setPosition(sf::Vector2f(1 * this->unitSize, 43 * this->unitSize));

	this->upgradeCloverSrc = sf::IntRect(6 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeClover.setTextureRect(this->upgradeCloverSrc);
	this->upgradeClover.setScale(5.f, 5.f);
	this->upgradeClover.setPosition(sf::Vector2f(13 * this->unitSize, 43 * this->unitSize));

	//Skill points
	this->skillPointsSrc = sf::IntRect(9 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->skillPoints.setTextureRect(this->skillPointsSrc);
	this->skillPoints.setScale(5.f, 5.f);
	this->skillPoints.setPosition(sf::Vector2f(25 * this->unitSize, 31 * this->unitSize));

	this->upgradeSkillPointsSrc = sf::IntRect(9 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeSkillPoints.setTextureRect(this->upgradeSkillPointsSrc);
	this->upgradeSkillPoints.setScale(5.f, 5.f);
	this->upgradeSkillPoints.setPosition(sf::Vector2f(37 * this->unitSize, 31 * this->unitSize));

	//Coin
	this->coinSrc = sf::IntRect(7 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->coin.setTextureRect(this->coinSrc);
	this->coin.setScale(5.f, 5.f);
	this->coin.setPosition(sf::Vector2f(25 * this->unitSize, 43 * this->unitSize));

	//Key
	this->keySrc = sf::IntRect(8 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->key.setTextureRect(this->keySrc);
	this->key.setScale(5.f, 5.f);
	this->key.setPosition(sf::Vector2f(25 * this->unitSize, 37 * this->unitSize));

	this->upgradeKeySrc = sf::IntRect(8 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeKey.setTextureRect(this->upgradeKeySrc);
	this->upgradeKey.setScale(5.f, 5.f);
	this->upgradeKey.setPosition(sf::Vector2f(37 * this->unitSize, 37 * this->unitSize));

	//EXP BAR
	this->expBar.setFillColor(sf::Color(212, 175, 55, 255));
	this->expBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(10)) * 20.f, 20.f));
	this->expBar.setPosition(sf::Vector2f(0, 780));

	//Door counter
	this->doorSrc = sf::IntRect(10 * this->unitSize, 0, this->unitSize, this->unitSize);
	this->door.setTextureRect(this->doorSrc);
	this->door.setScale(4.f, 4.f);
	this->door.setPosition(sf::Vector2f(0 * this->unitSize, 25 * this->unitSize));
	
	//Hp Bar
	this->hpBarBg.setSize(sf::Vector2f(400.f, 40.f));
	this->hpBarBg.setFillColor(sf::Color(255, 150, 150, 255));
	this->hpBarBg.setOutlineColor(sf::Color(255, 50, 50, 255));
	this->hpBarBg.setOutlineThickness(3.f);
	this->hpBarBg.setPosition(sf::Vector2f(13 * this->unitSize, 25 * this->unitSize));
	this->hpBarBg.setOutlineColor(sf::Color(255, 0, 0, 255));
	this->hpBarBg.setOutlineThickness(6.f);

	this->hpBar.setSize(sf::Vector2f(400.f, 40.f));
	this->hpBar.setFillColor(sf::Color(255, 50, 50, 255));
	this->hpBar.setPosition(sf::Vector2f(13 * this->unitSize, 25 * this->unitSize));

	this->upgradeHpSrc = sf::IntRect(4 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeHp.setTextureRect(this->upgradeHpSrc);
	this->upgradeHp.setScale(3.f, 3.f);
	this->upgradeHp.setPosition(sf::Vector2f(40 * this->unitSize, 25 * this->unitSize));

	//Inside object
	this->insideObjectSrc = sf::IntRect(51 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
	this->insideObject.setTextureRect(this->insideObjectSrc);
	this->insideObject.setPosition(350.f, 150.f);
	this->insideObject.setScale(5.f, 5.f);

	//Upgrade cost sprite
	this->upgradeCostSrc = sf::IntRect(7 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
	this->upgradeCost.setTextureRect(this->upgradeCostSrc);
	this->upgradeCost.setScale(5.f, 5.f);
	this->upgradeCost.setPosition(sf::Vector2f(43 * this->unitSize, 35 * this->unitSize));
	this->upgradeCost2 = this->upgradeCost;
	this->upgradeCost2.setScale(4.f, 4.f);
	this->upgradeCost2.setPosition(sf::Vector2f(44 * this->unitSize, 25 * this->unitSize));

	//Rooms
	this->roomA = new Room;
	this->roomB = new Room;
	this->selectedRoom = 0;
	this->selectedRoomR = this->roomA;
}

void UI::initText()
{
	//Set LVL font and properties
	this->lvlTxt.setFont(font);
	this->lvlTxt.setCharacterSize(40);
	this->lvlTxt.setFillColor(sf::Color::White);
	this->lvlTxt.setOutlineColor(sf::Color::Black);
	this->lvlTxt.setOutlineThickness(3.f);
	this->lvlTxt.setPosition(680, 725);

	this->fistTxt = this->lvlTxt;
	this->fistTxt.setCharacterSize(60);
	this->fistTxt.setPosition(sf::Vector2f(7 * this->unitSize, 31 * this->unitSize));
	
	this->shieldTxt = this->fistTxt;
	this->shieldTxt.setPosition(sf::Vector2f(7 * this->unitSize, 37 * this->unitSize));

	this->cloverTxt = this->fistTxt;
	this->cloverTxt.setPosition(sf::Vector2f(7 * this->unitSize, 43 * this->unitSize));

	this->skillPointsTxt = this->fistTxt;
	this->skillPointsTxt.setPosition(sf::Vector2f(31 * this->unitSize, 31 * this->unitSize));

	this->coinTxt = this->fistTxt;
	this->coinTxt.setPosition(sf::Vector2f(31 * this->unitSize, 43 * this->unitSize));

	this->keyTxt = this->fistTxt;
	this->keyTxt.setPosition(sf::Vector2f(31 * this->unitSize, 37 * this->unitSize));

	this->doorTxt = this->fistTxt;
	this->doorTxt.setCharacterSize(40);
	this->doorTxt.setPosition(sf::Vector2f(4 * this->unitSize, 26 * this->unitSize));

	this->hpTxt = this->fistTxt;
	this->doorTxt.setCharacterSize(40);
	this->hpTxt.setFillColor(sf::Color(237, 100, 94));
	this->hpTxt.setPosition(sf::Vector2f(23 * this->unitSize, 24 * this->unitSize));
}

void UI::initRooms()
{
	this->deleteRooms();
	this->roomA = new Room; //Room(this->player->level, this->player->dmg, ->hp, ->luck);
	this->roomB = new Room;
	if (this->roomB->getRoomType() == 1 && this->roomA->getRoomType() == 1) //there could be only one room with treasue to choose
		this->initRooms();

	this->roomA->setPosition(sf::Vector2f(7 * this->unitSize, 5 * this->unitSize));
	this->roomB->setPosition(sf::Vector2f(33 * this->unitSize, 5 * this->unitSize));
}

void UI::deleteRooms()
{
	delete this->roomA;
	delete this->roomB;
}

UI::UI()
{
	this->player = new Player;

	//Interface and basic game mechanics fuctions
	this->initVariables();
	this->initTextures();
	this->initSprites();
	this->initText();
	this->update();
	this->updateText();
	this->initSounds();

	this->initRooms();
}

UI::~UI()
{
	delete this->player;
}

void UI::input()
{
	//CHOICE ROOM 
	if (this->isInsideRoom == false)
	{
		//Arrow right && ROOM B
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && arrowTimer >= arrowTimerMax)
		{
			//std::cout << "prawo";
			this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize); //set default
			this->arrowR.setTextureRect(arrowsSrc);
			arrowTimer = 0;
			if (this->roomB->getRoomType() == 4) //if roomType == back: decrease room counter 
			{
				player->setProperties(12, -1);
				this->initRooms();
			}
			else if (this->roomB->getRoomType() == 1) //if treasure room, you must have key to open door
			{
				if (player->getProperties(7) >= 1)
				{
					player->setProperties(7, -1);
					this->updateInsideRoom(this->roomB->getRoomType());
					this->selectedRoom = this->roomB->getRoomType();
					this->selectedRoomR = this->roomB;
					this->isInsideRoom = true;
				}
			}
			else
			{
				this->updateInsideRoom(this->roomB->getRoomType());
				this->selectedRoom = this->roomB->getRoomType();
				this->selectedRoomR = this->roomB;
				this->isInsideRoom = true;
			}
		}
		//Arrow left && ROOM A
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && arrowTimer >= arrowTimerMax)
		{
			//std::cout << "lewo";
			this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize); //set default
			this->arrowL.setScale(-5.f, 5.f);
			this->arrowL.setTextureRect(arrowsSrc);
			arrowTimer = 0;
			if (this->roomA->getRoomType() == 4) //if roomType == back: decrease room counter 
			{
				player->setProperties(12, -1);
				this->initRooms();
			}
			else if (this->roomA->getRoomType() == 1) //if treasure room, you must have key to open door
			{
				if (player->getProperties(7) >= 1)
				{
					player->setProperties(7, -1);
					this->updateInsideRoom(this->roomA->getRoomType());
					this->selectedRoom = this->roomA->getRoomType();
					this->selectedRoomR = this->roomA;
					this->isInsideRoom = true;
				}
			}
			else
			{
				this->updateInsideRoom(this->roomA->getRoomType());
				this->selectedRoom = this->roomA->getRoomType();
				this->selectedRoomR = this->roomA;
				this->isInsideRoom = true;
			}
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && arrowTimer >= arrowTimerMax)
		{
			std::cout << "gora";
			this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize);
			this->arrowU.setTextureRect(arrowsSrc);
			arrowTimer = 0;
			this->isInsideRoom = false;

			this->playSound(this->selectedRoomR->getRoomType());

			this->selectedRoomR->action(this->selectedRoom, *this->player);
			this->initRooms();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && arrowTimer >= arrowTimerMax)
		{
			std::cout << "dol";
			this->arrowsSrc = sf::IntRect(0, this->unitSize, this->unitSize, this->unitSize);
			this->arrowD.setTextureRect(arrowsSrc);
			arrowTimer = 0;
			this->isInsideRoom = false;

			this->sEscape.play();

			//setPlayerPropertiesRoom(this->selectedRoom, *this->player);
			this->selectedRoomR->escape(this->selectedRoom, *this->player);
			this->initRooms();
		}
	}
	
	//INTERACTION IN BOTH OF STATES
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && this->player->getProperties(6) >= 1 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(6, -1);
		this->player->setProperties(2, 1);
		inputTimer = 0;
		this->upgradeShieldSrc = sf::IntRect(3 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeShield.setTextureRect(upgradeShieldSrc);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && this->player->getProperties(6) >= 1 && inputTimer >= inputTimerMax)
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && this->player->getProperties(8) >= 10 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(8, -10);
		this->player->setProperties(7, 1);
		inputTimer = 0;
		this->upgradeKeySrc = sf::IntRect(8 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeKey.setTextureRect(this->upgradeKeySrc);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && this->player->getProperties(8) >= 10 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(8, -10);
		this->player->setProperties(6, 1);
		inputTimer = 0;
		this->upgradeSkillPointsSrc = sf::IntRect(9 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeSkillPoints.setTextureRect(upgradeSkillPointsSrc);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && this->player->getProperties(8) >= 10 && this->player->getProperties(4) <= 960 && inputTimer >= inputTimerMax)
	{
		this->player->setProperties(8, -10);
		this->player->setProperties(4, 40);
		inputTimer = 0;
		this->upgradeHpSrc= sf::IntRect(4 * this->unitSize, 2 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeHp.setTextureRect(upgradeHpSrc);
	}

	/* ==================================== dev tools ==================================== */
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		this->player->setProperties(4, -1000);
		this->hpBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(4) * 0.4), 40.f)); // 0.4 -> hbbarwidth/hpMax 400/1000 = 0.4 
		//std::cout << "Hp: " << this->player->getProperties(4) << "\n";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		//std::cout << "exp + 10";
		this->player->setProperties(10, rand() % 25 + 5); //(10,10)
		//std::cout << "Exp: " << this->player->getProperties(10);
		this->player->setProperties(8, 10);

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		this->initRooms();
		//this->roomA->update(*this->player);
		//this->isInsideRoom = true;
	}

}

bool UI::isDead()
{
	return this->player->isDead();
}

void UI::playSound(int roomType)
{
	switch (roomType)
	{
	case 0:
		this->sEmpty.play();
		break;
	case 1:
		this->sTreasure.play();
		break;
	case 2:
		this->sEnemy.play();
		break;
	case 3:
		this->sTrap.play();
		break;
	case 4:
		this->sBack.play();
		break;
	case 5:
		this->sSecret.play();
		break;
	case 6:
		this->sHealing.play();
		break;
	}
}

const int& UI::getRoomCounter() const
{
	return this->player->getProperties(12);
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
		this->arrowU.setTextureRect(arrowsSrc);
		this->arrowD.setTextureRect(arrowsSrc);
	}
	if (this->inputTimer == this->inputTimerMax) //Back to unactive upgrade sprites
	{
		this->upgradeShieldSrc = sf::IntRect(3 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeShield.setTextureRect(upgradeShieldSrc);
		this->upgradeFistSrc = sf::IntRect(5 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeFist.setTextureRect(upgradeFistSrc);
		this->upgradeCloverSrc = sf::IntRect(6 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeClover.setTextureRect(upgradeCloverSrc);
		this->upgradeSkillPointsSrc = sf::IntRect(9 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeSkillPoints.setTextureRect(upgradeSkillPointsSrc);
		this->upgradeKeySrc = sf::IntRect(8 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeKey.setTextureRect(this->upgradeKeySrc);
		this->upgradeHpSrc = sf::IntRect(4 * this->unitSize, 1 * this->unitSize, this->unitSize, this->unitSize);
		this->upgradeHp.setTextureRect(this->upgradeHpSrc);
	}
	//HEALTH BAR AND EXP BAR
	this->hpBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(4) * 0.4), 40.f));
	this->expBar.setSize(sf::Vector2f(static_cast<float>(this->player->getProperties(10) * this->expIncrease), 20.f));

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
	this->hpTxt.setString(std::to_string(player->getProperties(4)));
}

void UI::updateInsideRoom(int roomType)
{
	this->insideObject.setPosition(350.f, 150.f);
	this->insideObject.setScale(5.f, 5.f);
	switch (roomType)
	{
	case 0: 
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 48 * this->unitSize, 0 * this->unitSize, 0 * this->unitSize);
		break;
	case 1:
		this->insideObjectSrc = sf::IntRect(51 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);	
		this->insideObject.setScale(sf::Vector2f(2.7f, 2.7f));
		this->insideObject.setPosition(sf::Vector2f(320.f, 220.f));
		break;
	case 2: 
		this->randomEnemy();
		break;
	case 3: 
		this->randomTrap();
		break;
	case 4: 
		this->insideObjectSrc = sf::IntRect(60 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		break;
	case 5:
		this->insideObjectSrc = sf::IntRect(63 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);	
		break;
	case 6:
		this->insideObjectSrc = sf::IntRect(66 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		break;
	}
	this->insideObject.setTextureRect(this->insideObjectSrc);
}

void UI::renderGV(sf::RenderTarget& target) //Game view
{
	if (this->isInsideRoom == false)
	{
		this->gameViewSrc = sf::IntRect(0, 17 * this->unitSize, 800, 30 * this->unitSize);
		this->gameView.setTextureRect(this->gameViewSrc);
		target.draw(this->gameView);
		target.draw(this->arrowR);
		target.draw(this->arrowL);
	}
	else
	{
		this->gameViewSrc = sf::IntRect(50 * this->unitSize, 17 * this->unitSize, 800, 30 * this->unitSize);
		this->gameView.setTextureRect(this->gameViewSrc);
		target.draw(this->gameView);
		target.draw(this->arrowU);
		target.draw(this->arrowD);
		target.draw(this->insideObject);
	}
}

void UI::renderGUI(sf::RenderTarget& target) // Graphical User Interface
{
	target.draw(this->gui);
	//target.draw(this->upgrade);
	target.draw(this->sword);
	target.draw(this->shield);	
	target.draw(this->upgradeShield);
	//target.draw(this->fist);
	target.draw(this->upgradeFist);
	target.draw(this->clover);
	target.draw(this->upgradeClover);
	target.draw(this->skillPoints);
	target.draw(this->upgradeSkillPoints);
	target.draw(this->coin);
	target.draw(this->key);
	target.draw(this->upgradeKey);
	target.draw(this->hpBarBg);	
	target.draw(this->expBar);	
	target.draw(this->door);	
	target.draw(this->upgradeHp);	
	target.draw(this->hpBar);	
	target.draw(this->heart);
	target.draw(this->upgradeCost);
	target.draw(this->upgradeCost2);
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
	target.draw(this->hpTxt);
}

void UI::renderRoom(sf::RenderTarget& target)
{
	if (this->isInsideRoom == false)
	{
		//Render two random generated rooms
		target.draw(this->roomA->getSprite());
		target.draw(this->roomB->getSprite());
	}
	
	//Shows message about perks you get
	target.draw(this->roomA->displayText());
	target.draw(this->roomB->displayText());
}

void UI::randomEnemy()
{
	this->randomizeEnemy = rand() % 6;
	switch (this->randomizeEnemy)
	{
	case 0:
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		break;
	case 1:
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 51 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		break;
	case 2:
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 54 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		this->insideObject.setPosition(sf::Vector2f(280.f, 120.f));
		break;
	case 3:
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 57 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		this->insideObject.setPosition(sf::Vector2f(180.f, 140.f));
		break;
	case 4:
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 60 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		break;
	case 5:
		this->insideObjectSrc = sf::IntRect(54 * this->unitSize, 63 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		break;
	}

	
}

void UI::randomTrap()
{
	this->randomizeTrap = rand() % 2;
	switch (this->randomizeTrap)
	{
	case 0:
		this->insideObjectSrc = sf::IntRect(57 * this->unitSize, 48 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		this->insideObject.setPosition(sf::Vector2f(240.f, 180.f));
		break;
	case 1:
		this->insideObjectSrc = sf::IntRect(57 * this->unitSize, 51 * this->unitSize, 3 * this->unitSize, 3 * this->unitSize);
		this->insideObject.setPosition(sf::Vector2f(190.f, 80.f));
		break;
	}
}

void UI::render(sf::RenderTarget& target)
{
	this->renderGV(target);
	this->renderGUI(target);
	this->renderText(target);
	this->renderRoom(target);
}
