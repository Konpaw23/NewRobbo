#pragma once
#include "../../../basicProjectHeaders.h"
#include "../LevelHeaders.h"

class MovingObject : public GameObject
{
public:
    MovingObject(GameObjectName objectName, Coordinates position, class Level* level);
    virtual bool IsActive();

    //returns true when object moved (no walls etc)
    virtual bool MoveLeft();
    virtual bool MoveRight();
    virtual bool MoveUp();
    virtual bool MoveDown();

protected:
    Level* level;
    bool isActive = true;
    bool isCollectingItems = false;
};