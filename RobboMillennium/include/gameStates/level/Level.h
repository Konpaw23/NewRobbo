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
    GameObject* GetObjectFromPosition(Coordinates pos);
    class MovingObject* GetMovingObjectFromPosition(int x, int y);
    GameObjectName GetObjectNameFromPosition(int x, int y);
    GameObjectName GetObjectNameFromPosition(Coordinates pos);
    bool IsObjectCollectible(int x, int y);
    bool IsObjectCollectible(Coordinates dest);

    //must be called after object change its position in own GameObject class
    void MoveObject(GameObject* object, Coordinates dest);

    Coordinates* GetNextPosition(Coordinates current, Direction dir);
    int GetScrewsNumber();

    void UpdateLevelPosition(double deltaTime);

    void PutLevelPicture();
    void PutEmptyField(int x, int y);
    void PutObject(GameObjectName name, int x, int y);
    Coordinates GetFieldPositionInPixelsOnScreen(int x, int y);

    //returns 1 when no more screws needed
    int DecreaseScrewsNumber();
private:
    void FieldsMemoryAlloc();

    void DeleteAllObjects();
    void FieldsMemoryDealloc();

    void LoadObjects(int levelNumber);

    int screwsToCollect;

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