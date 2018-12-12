#include "Renderer.hpp"

#include <string>
#include <GL/glew.h>

#include <sci/Application.hpp>
#include <sci/Logger.hpp>
#include <sci/Timer.hpp>

Renderer::Renderer(Application& application)
    : Manager(application)
    , m_window(nullptr)
{
}

Renderer::~Renderer()
{
}

void Renderer::set_gl_viewport(const glm::uvec2 & min, const glm::uvec2& max)
{
}

void Renderer::clear()
{
}

void Renderer::swap_buffers()
{
}

void Renderer::render()
{
}

void Renderer::on_initialize()
{
    initialize_sdl();
    initialize_open_gl();

    set_gl_viewport(glm::uvec2(0, 0), glm::uvec2(m_window_data.width, m_window_data.height));

    create_shader_vertex();
    create_shader_fragment();
    create_shader_program();
    create_render_data();
}

void Renderer::on_terminate()
{
    clean_up();
    terminate_open_gl();
    terminate_sdl();
}

void Renderer::initialize_sdl()
{
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    m_window = SDL_CreateWindow(m_window_data.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_window_data.width, m_window_data.height, m_window_data.flags);
}

void Renderer::terminate_sdl()
{
    SDL_DestroyWindow(m_window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void Renderer::initialize_open_gl()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    m_gl_context = SDL_GL_CreateContext(m_window);
    glewInit();

    SDL_GL_SetSwapInterval(m_window_data.vertical_synchronization);
}

void Renderer::terminate_open_gl()
{
    SDL_GL_DeleteContext(m_gl_context);
}

void Renderer::create_shader_vertex()
{
}

void Renderer::create_shader_fragment()
{
}

void Renderer::create_shader_program()
{
}

void Renderer::create_render_data()
{
}

void Renderer::clean_up()
{
}
