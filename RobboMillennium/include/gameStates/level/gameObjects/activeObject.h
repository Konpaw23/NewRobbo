#pragma once
#include "../../../basicProjectHeaders.h"
#include "MovingObject.h"

class activeObject : public MovingObject
{
public:
    activeObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, class Level* level);
    virtual void Run() = 0;
};
