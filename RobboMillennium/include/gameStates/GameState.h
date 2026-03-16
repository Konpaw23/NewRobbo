#pragma once
#include "../basicProjectHeaders.h"

class GameState
{
public:
    GameState(Window* window);
    ~GameState();

    GameStateName GetState();
    bool IsRunning();
    void Run();

protected:
    GameStateName state;
    Window* m_window;
    double deltaTime;
    Uint64 tick;
    Uint64 perfFreq;
    bool m_running;
    virtual void ProcessInput();
    void DisplayFPS();

    virtual void Render();
private:
    int refreshRate;
    int currentFPS = 0;
    int frames = 0;
    double FPSRefreshTimeDelta;

    Uint64 FPSRefreshTick;
    virtual void Update() = 0;
};