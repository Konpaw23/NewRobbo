#include "../../include/gameStates/GameState.h"

GameState::GameState(Window* window) : m_running(true), m_window(window)
{
    time = clock();
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
    //fixed to 60 fps
    while(m_running)
    {
        deltaTime = clock() - time;
        if (deltaTime >= 1.0/60.0 * CLOCKS_PER_SEC)
        {
            ProcessInput();
            Update();
            Render();
            time = clock();
        }
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