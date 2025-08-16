#pragma once
#include "../../basicProjectHeaders.h"
#include "LevelHeaders.h"

class Level
{
public:
    Level(Window* window, int levelNumber);
    ~Level();

    void RunSequence();
    int GetTurnNumber();

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
    void SpawnBullet(Coordinates pos, Direction trajectory);
    void SpawnSmoke(Coordinates pos);

    void RemoveObject(GameObject* object);

    Coordinates* GetNextPosition(Coordinates current, Direction dir);
    std::vector<Coordinates> GetFieldsAround(Coordinates position);
    int GetScrewsNumber();

    void UpdateLevelPosition(double deltaTime);

    void PutLevelPicture();
    void PutEmptyField(int x, int y);
    void PutObject(GameObjectName name, int x, int y);
    void PutObject(GameObjectName name, int x, int y, int frame);
    Coordinates GetFieldPositionInPixelsOnScreen(int x, int y);

    //returns 1 when no more screws needed
    int DecreaseScrewsNumber();

private:
    void FieldsMemoryAlloc();

    void DeleteAllObjects();
    void FieldsMemoryDealloc();

    void LoadObjects(int levelNumber);
    void AddToActiveObjects(class ActiveObject* object);
    void RemoveFromActiveObjects(int index);
    void DeleteDestroyedObjects();

    int screwsToCollect;

    int height;
    int width;

    int turnNumber = 0;

    class Robbo* player = nullptr;

    std::vector<ActiveObject*> activeObjects = {};
    GameObject*** fields = nullptr;

    //TODO idk if this is proper way to delete objects that is destroyed
    //could not do it destroy in RemoveObject because some objects can generate smoke after being destroyed
    //also deleting object in own class isn't clear especially when objects are created in Level class
    std::vector<GameObject*> objectsToDelete = {};

    void CreateObject(GameObjectName name, int x, int y);

    double levelRenderingUpperPosition = 0;
    double moveLevelPositionVertically = 0;
    //up - above 0, down - below 0

    Window* m_window;
};