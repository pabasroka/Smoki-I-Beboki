#pragma once
#include"UI.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window; //create pointer to window cause I dont want to send copy of it (its kind of an optimalisation)
	bool endGame;
	sf::Event sfmlEvent;

	//Objects from other classes
	UI* ui;

	void initWindow();

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
	
	void update();
	void render();
};

