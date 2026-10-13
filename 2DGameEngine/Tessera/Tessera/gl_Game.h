#pragma once
#include "Game.h"
#include <vector>

class VertexBuffers;
class Texture;

class gl_Game : public Game
{
private:
    bool bVsync = false;
    
    std::vector<std::unique_ptr<VertexArray>> vao;
    std::vector<std::unique_ptr<VertexBuffers>> vbo;
    std::vector<std::unique_ptr<IndexBuffer>> ibo;
    std::vector < std::unique_ptr<ShaderProgram>> shaders;
    std::vector<std::unique_ptr<Texture>> textures;

public:

    gl_Game(bool vsync,int w,int h);

    virtual void Initialize() override;

    virtual  void Run() override;
    virtual void Destroy() override;
    ~gl_Game();


protected:
    
    virtual  void ProcessInput() override;
    virtual   void Update() override;
    virtual  void Render() override;


};

