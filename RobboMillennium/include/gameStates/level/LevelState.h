#pragma once
#include "../GameState.h"
#include "../../basicProjectHeaders.h"
#include "LevelHeaders.h"

class LevelState : public GameState
{
public:
    LevelState(Window* window);
    LevelState(Window* window, int levelNumber);

private:
    Level* level;
    int levelNumber;
    RobboAction playerAction;

    double deltaSequenceTime;
    double sequenceTime;

    bool isPressedLeft = false;
    bool isPressedRight = false;
    bool isPressedUp = false;
    bool isPressedDown = false;
    RobboAction lastActionPressed = NOTHING;

    void ProcessInput() override;
    void Update() override;
    void Render() override;

    void SetPlayerMove();
};