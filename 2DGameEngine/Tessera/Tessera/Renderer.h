#pragma once

#include <fwd.hpp>
#include <GL/glew.h>
#include <GL/GL.h>
#include <vector>
#include <memory>
#include <unordered_map>
#include <string>
#include "RenderStructs.h"


class VertexBuffers;
class VertexArray;
class IndexBuffer;
class ShaderProgram;


class Renderer
{
    std::vector<std::unique_ptr<VertexArray>> vao;
    std::vector < std::unique_ptr<VertexBuffers>> vbo;
    std::vector<std::unique_ptr<IndexBuffer>> ibo;
    std::unordered_map<std::string, std::unique_ptr<ShaderProgram>>Shaders;


public:

    // make functions to abstract all the gl calls basically
    // we have at making clear and draw  blend alpha update class as per ur need

    Renderer();
    void BlendAlpha() const;

    Renderer(const Renderer& va) = delete;
    Renderer& operator=(const Renderer& va) = delete;

    void Rect(const Rectangle& rect,const glm::mat4 & mvp);

    // generally we pass in materials instead of shader
    void Draw(const VertexArray& vao, const IndexBuffer& ibo, const ShaderProgram& program) const;

    void Clear() const;

    ~Renderer();
};

