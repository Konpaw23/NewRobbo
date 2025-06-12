#include "GameState.h"

GameState::GameState(Window* window) : m_running(true), m_window(window)
{
    ;
}

GameState::~GameState()
{
    //Clear textures every state change
    //this->m_window->ClearTextures();
}

GameStateName GameState::GetState()
{
    return state;
}

bool GameState::IsRunning()
{
    return m_running;
}

void GameState::Run()
{
    while(m_running)
    {
        ProcessInput();
        Update();
        Render();
    }
}

void GameState::ProcessInput()
{
    SDL_Event e;

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            state = EXIT;
            m_running = false;
        }
    }
}