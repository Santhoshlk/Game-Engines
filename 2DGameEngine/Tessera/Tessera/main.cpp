
//** External Included Headers start **//

#include <iostream>

//** External Included Headers end **//


//** Our Headers start **//
#include "Game.h"
//** Our Headers end **//

Game* game = nullptr;


int main(void)
{
    game = new Game;

    game->Initialize();

    game->Run();


    game->Destroy();


    delete game;

}