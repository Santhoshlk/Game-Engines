#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL3/SDL.h>


class Game
{
private:
   
public:

    Game();
  virtual  ~Game();

  virtual   void Initialize();
  virtual  void Run();
  virtual void Destroy();


protected:

    //  some private data etc
    bool isRunning = true;
    SDL_Window* GameWindow = nullptr;
   
    virtual  void ProcessInput();
    virtual   void Update();
    virtual  void Render();
};

#endif
