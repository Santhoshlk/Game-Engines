#include "Game.h"
#include <stdio.h>


Game::Game()
{

}

Game::~Game()
{
    Destroy();
}

void Game::Initialize()
{
   if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO))
   {
       printf("The Sdl has not been initialized correctly");
       return;
   }
   
   SDL_Window* mainwindow = SDL_CreateWindow("Game Window",1000,500,SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!mainwindow)
    {
        printf("The sdl window creation has not been initialized correctly");
        SDL_Quit();
        return;
    }
    GameWindow = mainwindow;


}

void Game::Run()
{
    while (true)
    {
        ProcessInput(); 
        Update();
        Render();
    }


}

void Game::Destroy()
{
    std::cout << "The Game Instance has been Destroyed" << std::endl;
}

void Game::ProcessInput()
{
}

void Game::Update()
{
}

void Game::Render()
{
}
