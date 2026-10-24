#pragma once
#include "Game.h"
#include <glm.hpp>


class gl_Game : public Game
{
private:
    bool bVsync = false;
    glm::vec2 PlayerPosition;
    glm::vec2 velocity;

public:

    gl_Game(bool vsync,int w,int h,int fps = 60);

    virtual void Initialize() override;

    virtual void Setup() override;

    virtual  void Run() override;
    virtual void Destroy() override;
    ~gl_Game();


protected:
    
    virtual  void ProcessInput() override;
    virtual   void Update() override;
    virtual  void Render() override;


};

