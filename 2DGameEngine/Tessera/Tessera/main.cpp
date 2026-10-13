
//** External Included Headers start **//

#include <iostream>

//** External Included Headers end **//


//** Our Headers start **//
#include "gl_Game.h"
//** Our Headers end **//

Game* game = nullptr;


int main(void)
{
    game = new gl_Game(true,1000,500);

    game->Initialize();

    game->Run();

    game->Destroy();
        
    delete game;

}