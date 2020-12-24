#pragma once
#include"UI.h"
#include <sstream>

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window; //create pointer to window cause I dont want to send copy of it (its kind of an optimalisation)
	bool endGame;
	sf::Event sfmlEvent;

	//Game Icon
	sf::Image gameIcon;
	sf::IntRect gameIconSrc;

	//Game over
	sf::Font font;
	sf::Text gameOver;
	std::stringstream resetString;
	sf::Text resetTxt;

	//Objects from other classes
	//Player* player;

	UI* ui;

	void initWindow();

	void initGameOverText(int rooms);
	void initSprite();
public:
	//Constructor and Destructor
	Game();
	virtual ~Game();

	//Accessors (getter)
	const bool& getEndGame() const;

	//Modifiers (setter)

	//Functions (general stuff)
	const bool running() const;
	void pollEvents();
	void reset();
	
	void update();
	void render();
};

