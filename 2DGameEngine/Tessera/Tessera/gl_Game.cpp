#include "gl_Game.h"
#include <GL/glew.h>
#include  <GL/GL.h>
#include <iostream>
#include "Renderer.h"
#include <gtc/matrix_transform.hpp>
#include "ShaderProgram.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBuffers.h"
#include "BufferLayout.h"
#include "Texture.h"


gl_Game::gl_Game(bool vsync, int w, int h, int fps) :bVsync(vsync)
{
    width = w;
    height = h;
    renderer = std::make_unique<Renderer>();
    nanosecperframe = pow(10.f,9) / static_cast<float>(fps);
}
void gl_Game::Initialize()
{
    if (!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO))
    {
        printf("The Sdl has not been initialized correctly\n");
        return;
    }

    // set the window hint
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG | SDL_GL_CONTEXT_DEBUG_FLAG);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);


    //TODO: add double buffer add vsync add depth 
   

 


    SDL_Window* mainwindow = SDL_CreateWindow("Game Window", width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
        
    if (!mainwindow)
    {
        printf("The sdl window creation has not been initialized correctly\n");
        SDL_Quit();
        return;
    }
    GameWindow = mainwindow;

    const SDL_DisplayMode* Display = SDL_GetCurrentDisplayMode(SDL_GetPrimaryDisplay());

    SDL_SetWindowFullscreenMode(GameWindow, Display);
    SDL_SetWindowFullscreen(GameWindow, true);

    SDL_GLContext Context = SDL_GL_CreateContext(GameWindow);

    if (!Context)
    {

        std::cout << "The error in creating the context :" << SDL_GetError() << std::endl;
        printf("The sdl context has not been able to be initialized properly\n");
        SDL_GL_DestroyContext(Context);
        SDL_DestroyWindow(GameWindow);
        SDL_Quit();
        return;
    }


    // NOTE: Vsync should only be set after context has been created
    SDL_GL_SetSwapInterval(bVsync);
     
    int framebufferwidth, framebufferheight;

    //TO GET THE WINDOW SIZE IN PIXELS

    SDL_GetWindowSizeInPixels(GameWindow,&framebufferwidth,&framebufferheight);

    glewExperimental = GL_TRUE;


    //Glew init
    if (glewInit()!=GLEW_OK)
    {
        
        printf("The glew has not been initialized properly\n");

        SDL_GL_DestroyContext(Context);
        SDL_DestroyWindow(GameWindow);
        SDL_Quit();
        return;
    }
    glViewport(0,0,framebufferwidth,framebufferheight);
}

void gl_Game::Setup()
{
    PlayerPosition = glm::vec2(0.f, 0.f);
    velocity = glm::vec2(1.f, 1.f);
}

void gl_Game::Run()
{
    Game::Run();
}

void gl_Game::Destroy()
{
    //Todo : destroy gl ones.
    Game::Destroy();
}

gl_Game::~gl_Game()
{
    std::cout << "The gl game instance has been destroyed ." << std::endl;
}

void gl_Game::ProcessInput()
{
    // yep call super for all
    Game::ProcessInput();
  
    

}

void gl_Game::Update()
{
    // here
    PlayerPosition.x += velocity.x*deltatime;
    Game::Update();
}

void gl_Game::Render()
{
    Game::Render();

    renderer->Clear();

   


    //Todo : actual rendering.
    // glm::mat4 proj = glm::ortho(0.f, (float)width, (float)height,0.f, -1.f, 1.f);
    //
    // Rectangle rect(10.f, 10.f, 10.f, 20.f);
    //
    // renderer->Rect(rect,proj);

    glm::mat4 proj = glm::ortho(0.f, (float)width, (float)height,0.f, -1.f, 1.f);

    Rectangle rect(PlayerPosition.x,PlayerPosition.y,10,20);

    renderer->Rect(rect,proj);



  // swap buffer
    SDL_GL_SwapWindow(GameWindow);


}
