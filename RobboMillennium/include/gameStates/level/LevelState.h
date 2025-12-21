#pragma once
#include "../GameState.h"
#include "../../basicProjectHeaders.h"
#include "Level.h"
#include "InfoPanel.h"
#include "enums.h"

class LevelState : public GameState
{
public:
    LevelState(Window* window);
    LevelState(Window* window, GameStateName planet);
    LevelState(Window* window, int levelNumber);
    void AddLife();
    void SetLivesPositions(std::vector<Coordinates> positions);
    bool IsLiveAtPositionAvailable(Coordinates position);
    void RemoveLiveAtPosition(Coordinates position);
    bool IsFirstLevelGame();

private:
    Level* level;
    int levelNumber;
    std::string planet;
    RobboAction playerAction;
    int lives;
    std::vector<Coordinates> levelLivesPositions = {};
    bool isFirstLevelGame = true;

    InfoPanel* infoPanel;

    double deltaSequenceTime;
    double sequenceTime;

    bool isPressedLeft = false;
    bool isPressedRight = false;
    bool isPressedUp = false;
    bool isPressedDown = false;
    bool isPressedSpace = false;
    RobboAction lastActionPressed = NOTHING;

    InfoPanelData GetDataForInfoPanel();

    void ActionMoveToShoot();

    void ProcessInput() override;
    void Update() override;
    void Render() override;

    void PutInfoPanel();

    void SetPlayerMove();
};