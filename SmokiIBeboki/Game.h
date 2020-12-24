#pragma once
#include"UI.h"
#include <sstream>

class Game
{
private:
	sf::VideoMode videoMode;
	//create pointer to window cause I dont want to send copy of it
	//(its kind of an optimalisation)
	sf::RenderWindow* window; 
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

	//Game rules
	sf::Texture rulesTxt;
	sf::Sprite rules;
	bool rulesInfo;

	//Sounds
	sf::Music music;

	// Main game object which includes interface and also mechanics
	UI* ui;

	void initWindow();
	void initGameRules();

	void initGameOverText(int rooms);
	void initSprite();
public:
	//Constructor and Destructor
	Game();
	virtual ~Game();

	//Accessors (getter)
	const bool& getEndGame() const;

	//Functions (general stuff)
	const bool running() const;
	void pollEvents();
	void reset();
	
	void update();
	void render();
};

