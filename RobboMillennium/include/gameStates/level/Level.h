#pragma once
#include "../../basicProjectHeaders.h"
#include "LevelHeaders.h"
#include <optional>

class Level
{
public:
    Level(Window* window, int levelNumber, std::string planet, class LevelState* levelState);
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
    void CreateObject(GameObjectName name, int x, int y);
    void CreateObject(GameObjectName name, int x, int y, Direction rotation);
    void CreateObject(GameObjectName name, int x, int y, Axis axis);
    void CreateObject(GameObjectName name, int x, int y, Direction rotation, int extraValue);
    void CreateGoldenSeahorse(Coordinates position, Direction movementSide, Direction initialDirection);
    void CreateOpenShip(Coordinates position);
    void SpawnBullet(Coordinates pos, Direction trajectory);
    void SpawnSmoke(Coordinates pos);

    void RemoveObject(GameObject* object);
    //to make sure only robbo can call this function
    void DeselectRobbo(class Robbo* robbo);
    void HideRobbo();
    void ShowRobbo();
    bool IsRobboVisible();
    Coordinates GetRobboPosition();
    void FinishLevel();
    bool IsLevelFinished();

    std::optional<Coordinates> GetNextPosition(Coordinates current, Direction dir);
    std::vector<Coordinates> GetFieldsAround(Coordinates position);
    std::vector<Coordinates> GetFieldsNextTo(Coordinates position);
    int GetScrewsNumber();
    int GetKeysNumber();
    int GetAmmoNumber();

    void UpdateLevelPosition(double deltaTime, Uint64 perfFreq);

    void PutLevelPicture();
    void PutEmptyField(int x, int y);
    void PutObject(GameObjectName name, int x, int y);
    void PutObject(GameObjectName name, int x, int y, int frame);
    void PutObject(GameObjectName name, int x, int y, Direction rotation);
    void PutObject(GameObjectName name, int x, int y, Axis axis);
    Coordinates GetFieldPositionInPixelsOnScreen(int x, int y);

    //returns 1 when no more screws needed
    int DecreaseScrewsNumber();
    void AddLife();
    void SetLifeAsTaken(Coordinates position);

    void ActivateStop(int sequences);
    bool IsLevelStopped();

    void RemoveAllKillingObjects();
    void RemoveAllDoors();
    void ReplaceObjects(GameObjectName objToReplace, GameObjectName replacingObject);

private:
    LevelState* levelState;

    void FieldsMemoryAlloc();

    void DeleteAllObjects();
    void FieldsMemoryDealloc();

    void LoadObjects(int levelNumber, std::string planet);
    void AddToActiveObjects(class ActiveObject* object);
    void RemoveFromActiveObjects(int index);
    void DeleteDestroyedObjects();

    int screwsToCollect;

    int height;
    int width;

    int turnNumber = 0;

    //freeze all object instead of Robbo if higher than 0
    int stopActive = 0;

    class Robbo* player = nullptr;
    bool isRobboVisible = true;
    Ship* ship = nullptr;

    bool isLevelFinished = false;

    std::vector<ActiveObject*> activeObjects = {};
    GameObject*** fields = nullptr;

    std::vector<GameObject*> objectsToDelete = {};

    void CreateMirror(int x, int y, MirrorGroup* group);

    double levelRenderingUpperPosition = 0;
    double moveLevelPositionVertically = 0;
    //up - above 0, down - below 0

    Window* m_window;
};