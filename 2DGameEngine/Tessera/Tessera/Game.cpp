#include "Game.h"
#include <stdio.h>
#include "Renderer.h"


Game::Game()
{

}

Game::~Game()
{
    std::cout << "The Game Instance has been Destroyed" << std::endl;

    SDL_DestroyWindow(GameWindow);
    SDL_Quit();
}

void Game::Initialize()
{
   if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO))
   {
       printf("The Sdl has not been initialized correctly\n");
       return;
   }
  const SDL_DisplayMode* Display = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());

   SDL_SetWindowFullscreenMode(GameWindow,Display);

    SDL_SetWindowFullscreen(GameWindow,true);


   SDL_Window* mainwindow = SDL_CreateWindow("Game Window",1000,500,SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!mainwindow)
    {
        printf("The sdl window creation has not been initialized correctly\n");
        SDL_Quit();
        return;
    }
    GameWindow = mainwindow;


}

void Game::Run()
{

    while (isRunning)
    {
        Uint64 frameStart = SDL_GetTicksNS();

        ProcessInput();
        if (!isRunning)
        {
            break;
        }

        Update();
        Render();

        Uint64 frameTimeNS = SDL_GetTicksNS() - frameStart;
        double fps = 1'000'000'000.0 / frameTimeNS;
        std::cout << "Fps :" << fps << std::endl;
    }
}

void Game::Destroy()
{
    SDL_Quit();
}

void Game::ProcessInput()
{
  
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
       
        if (event.type == SDL_EVENT_QUIT)
        {
            isRunning = false;
            break;
        }
        else if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
        {
            isRunning = false;
            break;
        }

    }
    
}

void Game::Update()
{
}

void Game::Render()
{
}
