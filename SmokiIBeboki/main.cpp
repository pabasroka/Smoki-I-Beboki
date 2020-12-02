#include"Game.h"

int main()
{
    //Init random
    srand(static_cast<unsigned>(time(0)));

    //Init game object
    Game game;

    //Game loop
    while (game.running() && !game.getEndGame())
    {
        game.update(); //updates all variables
        game.render(); //display it
    }

    return 0;
}