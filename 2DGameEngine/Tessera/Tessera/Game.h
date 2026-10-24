#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL3/SDL.h>
#include <memory>

class Renderer;

class Game
{
private:
    

public:

    Game();
  virtual  ~Game();
  virtual void Setup();
  virtual   void Initialize();
  virtual  void Run();
  virtual void Destroy();


protected:

    //  some private data etc
    bool isRunning = true;
    SDL_Window* GameWindow = nullptr;
    int width = 1000;
    int height = 500;
    std::unique_ptr<Renderer> renderer;
   
    virtual  void ProcessInput();
    virtual   void Update();
    virtual  void Render();
};

#endif
