#pragma once
#include "../../basicProjectHeaders.h"
#include "LevelHeaders.h"

class Level
{
public:
    Level(Window* window, int levelNumber);
    ~Level();

    void RunSequence();

    bool IsPlayerAlive();
    void SetPlayerAction(RobboAction action);

    int GetHeight();
    int GetWidth();
    GameObject* GetObjectFromPosition(int x, int y);
    class MovingObject* GetMovingObjectFromPosition(int x, int y);
    GameObjectName GetObjectNameFromPosition(int x, int y);

    //must be called after object change its position in own class
    void MoveObjectLeft(GameObject* object);
    void MoveObjectRight(GameObject* object);
    void MoveObjectUp(GameObject* object);
    void MoveObjectDown(GameObject* object);

    void UpdateLevelPosition(double deltaTime);

    void PutLevelPicture();
    void PutEmptyField(int x, int y);
    void PutObject(GameObjectName name, int x, int y);
    Coordinates GetFieldPositionInPixelsOnScreen(int x, int y);
private:
    void FieldsMemoryAlloc();

    void DeleteAllObjects();
    void FieldsMemoryDealloc();

    void LoadObjects(int levelNumber);

    int height;
    int width;

    class Robbo* player = nullptr;
    GameObject*** fields = nullptr;

    void AddObject(GameObjectName name, int x, int y);

    double levelRenderingUpperPosition = 0;
    double moveLevelPositionVertically = 0;
    //up - above 0, down - below 0

    Window* m_window;
};