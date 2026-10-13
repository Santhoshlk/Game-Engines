#include "Renderer.h"
#include "ShaderProgram.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBuffers.h"
#include "BufferLayout.h"

Renderer::Renderer()
{
}

void Renderer::BlendAlpha() const
{
    glEnable(GL_BLEND);
    // give blend rgba coffecients
    glBlendFunc(GL_SRC_ALPHA,GL_DST_ALPHA );
    glBlendEquation(GL_ADD);
}

void Renderer::Rect(const Rectangle& rect, const glm::mat4& mvp)
{
    VertexArray vao;
    vao.Bind();

    float vertices[] = {
        rect.x,rect.y+rect.height,
        rect.x+rect.width,rect.y+rect.height,
        rect.x + rect.width,rect.y,
        rect.x,rect.y
    };

    VertexBuffers vbo(vertices, 8 * sizeof(float));

    BufferLayout layout;

    layout.PushBuffers(0,2,GL_FLOAT,false,0);

    vao.addBuffer(vbo, layout);

    unsigned int indices [] = 
    {
       0,1,2,
        2,3,0
    };


    IndexBuffer ibo(indices, 6 * sizeof(unsigned int));

    ShaderProgram* program;

    if (Shaders.contains("Rect"))
    {
        program = Shaders["Rect"].get();
    }
    else
    {
        std::unique_ptr<ShaderProgram> shader_program = std::make_unique<ShaderProgram>("objShader.txt");
        Shaders.insert({"Rect",std::move(shader_program)});

        program = Shaders["Rect"].get();
    }

    program->Bind();

    program->SetUniformMat4("u_mvp", mvp);


    // draw
    Draw(vao, ibo, *program);

}

void Renderer::Draw(const VertexArray& vao, const IndexBuffer& ibo, const ShaderProgram& program) const
{
    program.Bind();
    vao.Bind();
    ibo.Bind();
   
    glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr);

}

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

Renderer::~Renderer()
{

}
