#include "GL/glew.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"

#include <sol/sol.hpp>

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    // Lua + Sol
    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::math);
    lua.script(R"(
        greeting = "Hello from Lua"
        function scale(x) return x * 2.0 end
    )");
    std::string greeting = lua["greeting"];
    float luaScale = lua["scale"](0.5f);

    // GLM
    glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec4 rotated = model * glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

    // SDL3 + OpenGL context
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    SDL_Window* window = SDL_CreateWindow("Tessera", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    SDL_GLContext context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
    SDL_GL_SetSwapInterval(1);

    // GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "glewInit failed" << std::endl;
        return -1;
    }

    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplSDL3_InitForOpenGL(window, context);
    ImGui_ImplOpenGL3_Init("#version 330");

    int sdlVersion = SDL_GetVersion();
    float clearColour[3] = { 0.1f, 0.1f, 0.15f };
    bool running = true;

    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            ImGui_ImplSDL3_ProcessEvent(&event);
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL3_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Tessera Setup Check");
        ImGui::Text("OpenGL: %s", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
        ImGui::Text("GLEW: %s", reinterpret_cast<const char*>(glewGetString(GLEW_VERSION)));
        ImGui::Text("SDL: %d.%d.%d", SDL_VERSIONNUM_MAJOR(sdlVersion), SDL_VERSIONNUM_MINOR(sdlVersion), SDL_VERSIONNUM_MICRO(sdlVersion));
        ImGui::Text("Lua says: %s", greeting.c_str());
        ImGui::Text("Lua scale(0.5) = %.2f", luaScale);
        ImGui::Text("GLM: (1,0,0) rotated 45 deg = (%.3f, %.3f)", rotated.x, rotated.y);
        ImGui::ColorEdit3("Clear colour", clearColour);
        ImGui::End();

        ImGui::Render();

        int width = 0, height = 0;
        SDL_GetWindowSizeInPixels(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(clearColour[0], clearColour[1], clearColour[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DestroyContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}