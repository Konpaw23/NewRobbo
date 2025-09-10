#pragma once
#include "../GameState.h"
#include "../../basicProjectHeaders.h"
#include "Level.h"

class LevelState : public GameState
{
public:
    LevelState(Window* window);
    LevelState(Window* window, int levelNumber);
    void AddLife();

private:
    Level* level;
    int levelNumber;
    RobboAction playerAction;
    int lives;

    double deltaSequenceTime;
    double sequenceTime;

    bool isPressedLeft = false;
    bool isPressedRight = false;
    bool isPressedUp = false;
    bool isPressedDown = false;
    bool isPressedSpace = false;
    RobboAction lastActionPressed = NOTHING;

    void ActionMoveToShoot();

    void ProcessInput() override;
    void Update() override;
    void Render() override;

    void PutInfoPanel();

    void SetPlayerMove();
};