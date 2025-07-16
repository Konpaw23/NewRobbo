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
    double time;
    bool m_running;
    virtual void ProcessInput();

private:
    virtual void Update() = 0;
    virtual void Render() = 0;
};