#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL3/SDL.h>


class Game
{
private:
   //  some private data etc
    SDL_Window* GameWindow = nullptr;
public:

    Game();
  virtual  ~Game();

  virtual   void Initialize();
  virtual  void Run();
  virtual void Destroy();

  virtual  void ProcessInput();
  virtual   void Update();
  virtual  void Render();

protected:
};

#endif
