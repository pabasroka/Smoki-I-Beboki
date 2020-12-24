#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Smoki & Beboki", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->gameIcon.loadFromFile("Textures/dragon.png");
	this->window->setIcon(this->gameIcon.getSize().x, this->gameIcon.getSize().y, this->gameIcon.getPixelsPtr());
	this->music.openFromFile("Sound/zelda.ogg");
	
	//this->music.play();
}

void Game::initGameRules()
{
	if (!this->rulesTxt.loadFromFile("Textures/gameRules.png"))
		std::cout << "Could not load gameRules.png file \n";
	this->rules.setTexture(this->rulesTxt);
	this->rulesInfo = true;
}

void Game::initGameOverText(int rooms)
{
	if (!this->font.loadFromFile("Fonts/AncientModernTales-a7Po.ttf"))
		std::cout << "Could not load font \n";

	this->gameOver.setFont(font);
	this->gameOver.setCharacterSize(120);
	this->gameOver.setFillColor(sf::Color::Red);
	this->gameOver.setOutlineColor(sf::Color::Black);
	this->gameOver.setOutlineThickness(3.f);
	this->gameOver.setPosition(120, 200);
	this->gameOver.setString("KONIEC GRY !");

	this->resetTxt.setFont(font);
	this->resetTxt.setCharacterSize(50);
	this->resetTxt.setFillColor(sf::Color::White);
	this->resetTxt.setOutlineColor(sf::Color::Black);
	this->resetTxt.setOutlineThickness(3.f);
	this->resetTxt.setPosition(20, 350);
	this->resetString.str("");
	this->resetString << "Twoj wynik: " << rooms << " \n \n WCISNIJ 'R' ABY ZRESTARTOWAC !"; 
	this->resetTxt.setString(this->resetString.str());
}

void Game::initSprite()
{
	this->ui = new UI;
}

Game::Game()
{
	this->initWindow();
	this->initSprite();
	this->initGameRules();
}

Game::~Game()
{
	//Delete dynamic allocated variables
	delete this->window;

	delete this->ui;
}

const bool& Game::getEndGame() const
{
	return this->endGame;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::reset()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->endGame = false;
		this->ui = new UI;
	}
	
}

void Game::update()
{
	this->pollEvents();

	//All stuff to update
	if(this->rulesInfo == false)
		this->ui->update();

	if (this->ui->isDead())
		this->endGame = true;
		
}

void Game::render()
{	
	// Game render
	if (this->endGame)
	{
		this->window->clear(sf::Color::Black);

		this->initGameOverText(this->ui->getRoomCounter());

		this->window->draw(gameOver);
		this->window->draw(resetTxt);
		this->reset();

		//Display new frame
		this->window->display();
	}
	else
	{
		//Clear window before new frame
		this->window->clear();

		// Game rules 
		if (this->rulesInfo)
		{
			this->window->draw(this->rules);
			//for (int i = sf::Keyboard::A; i <= sf::Keyboard::Z; i++) sf::Keyboard::
			// PRESS ANY KEY
			for(int i = 0; i <= 100; i++)
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i)))
					this->rulesInfo = false;
		}
		else
			//Render frame
			this->ui->render(*this->window);

		//Display new frame
		this->window->display();
	}

}
