#pragma once
#include "../../../basicProjectHeaders.h"
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
    MovingObject(GameObjectName objectName, Coordinates position, class Level* level);
    virtual bool IsActive();

    //returns true when object moved (no walls etc.)
    virtual bool Move(Direction dir);

protected:
    Level* level;
    bool isActive = true;
};