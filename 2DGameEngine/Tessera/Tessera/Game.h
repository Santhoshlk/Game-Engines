#ifndef GAME_H
#define GAME_H

#include <iostream>


class Game
{
private:
    // some private data etc

public:

    Game();
    ~Game();

    void Initialize();
    void Run();
    void Destroy();

    void ProcessInput();
    void Update();
    void Render();

protected:
};

#endif
