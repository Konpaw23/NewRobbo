#pragma once
#include "../../../basicProjectHeaders.h"
#include "GameObject.h"

class Level;

class MovingObject : virtual public GameObject
{
public:
    MovingObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level);
    virtual bool IsActive();

    //returns true when object moved (no walls etc.)
    virtual bool Move(Direction dir);

protected:
    bool isActive = true;
};