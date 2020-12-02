#include "Game.h"

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(800, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Smoki & Beboki", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initSprite()
{
	this->ui = new UI;
}

Game::Game()
{
	this->initWindow();
	this->initSprite();
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

void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		//All stuff to update

	}
}

void Game::render()
{
	//Clear window before new frame
	this->window->clear();

	//Render stuff
	this->ui->render(*this->window);

	//Display new frame
	this->window->display();
}
