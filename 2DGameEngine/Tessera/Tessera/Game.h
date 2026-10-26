#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL3/SDL.h>
#include <memory>
#include "Logger.h"

class Renderer;

class Game
{
private:
  

public:
    Game();
    Game(int fps);
  virtual  ~Game();
  virtual void Setup();
  virtual   void Initialize();
  virtual  void Run();
  virtual void Destroy();


protected:

    //  some private data etc
    bool isRunning = true;
    float deltatime = 0.f;

    size_t nanosecperframe;
    size_t previousframetime = 0.f;
    SDL_Window* GameWindow = nullptr;
    int width = 1000;
    int height = 500;
    std::unique_ptr<Renderer> renderer;
   
    virtual  void ProcessInput();
    virtual   void Update();
    virtual  void Render();
};

#endif
