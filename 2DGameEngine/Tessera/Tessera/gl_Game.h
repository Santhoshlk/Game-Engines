#pragma once
#include "Game.h"
class gl_Game : public Game
{
private:
    bool bVsync = false;
public:

    gl_Game(bool vsync);

    virtual void Initialize() override;

    virtual  void Run() override;
    virtual void Destroy() override;
    ~gl_Game();


protected:
    
    virtual  void ProcessInput() override;
    virtual   void Update() override;
    virtual  void Render() override;


};

