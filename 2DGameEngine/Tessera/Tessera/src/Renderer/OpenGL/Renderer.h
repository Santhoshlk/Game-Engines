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
class Texture;

class Renderer
{
    std::unordered_map<std::string, std::vector<std::unique_ptr<VertexArray>>> vao;
    std::unordered_map<std::string, std::vector<std::unique_ptr<VertexBuffers>>> vbo;
    std::unordered_map<std::string, std::vector<std::unique_ptr<IndexBuffer>>> ibo;
    std::unordered_map<std::string, std::unique_ptr<ShaderProgram>> Shaders;
    std::unordered_map<std::string, std::vector<std::unique_ptr<Texture>>> Textures;

public:

    // make functions to abstract all the gl calls basically
    // we have at making clear and draw  blend alpha update class as per ur need


    // Push: create outside, move it in under a name
    void PushVertexArray(const std::string& name, std::unique_ptr<VertexArray> vertexArray);
    void PushVertexBuffer(const std::string& name, std::unique_ptr<VertexBuffers> vertexBuffer);
    void PushIndexBuffer(const std::string& name, std::unique_ptr<IndexBuffer> indexBuffer);
    void SetShader(const std::string& name, std::unique_ptr<ShaderProgram> shaderProgram);
    void PushTexture(const std::string& name, std::unique_ptr<Texture> texture);

    // Access: hand back the whole container
    std::unordered_map<std::string, std::vector<std::unique_ptr<VertexArray>>>& GetVertexArrays();
    std::unordered_map<std::string, std::vector<std::unique_ptr<VertexBuffers>>>& GetVertexBuffers();
    std::unordered_map<std::string, std::vector<std::unique_ptr<IndexBuffer>>>& GetIndexBuffers();
    std::unordered_map<std::string, std::unique_ptr<ShaderProgram>>& GetShaders();
    std::unordered_map<std::string, std::vector<std::unique_ptr<Texture>>>& GetTextures();





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

