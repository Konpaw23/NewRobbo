#include "../../include/gameStates/GameState.h"
#include <thread>
#include <chrono>

GameState::GameState(Window* window) : m_running(true), m_window(window)
{
    tick = SDL_GetPerformanceCounter();
    FPSRefreshTick = SDL_GetPerformanceCounter();
    perfFreq = SDL_GetPerformanceFrequency();

    SDL_DisplayMode dm;
    SDL_GetCurrentDisplayMode(0, &dm);
    refreshRate = dm.refresh_rate;
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
        deltaTime = double( SDL_GetPerformanceCounter() - tick ) / perfFreq;
        if (deltaTime >= 1.0/refreshRate)
        {
            tick = SDL_GetPerformanceCounter();
            this->frames++;
            ProcessInput();
            Update();
            Render();
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::microseconds(250));
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

void GameState::DisplayFPS()
{
    this->FPSRefreshTimeDelta = double( SDL_GetPerformanceCounter() - FPSRefreshTick ) / perfFreq;
    if(FPSRefreshTimeDelta >= 1.0/2)
    {
        this->currentFPS = double(frames) / FPSRefreshTimeDelta;
        frames = 0;
        FPSRefreshTick = SDL_GetPerformanceCounter();
    }
    m_window->Write(std::to_string(currentFPS), {1840, 0}, 64, {127,127,127});
}

void GameState::Render()
{
    this->DisplayFPS();
}