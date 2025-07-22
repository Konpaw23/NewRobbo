#pragma once
#include "../../../basicProjectHeaders.h"
#include "MovingObject.h"

class activeObject : public MovingObject
{
public:
    activeObject(GameObjectName objectName, Coordinates position, class Level* level);
    virtual void Run() = 0;
};
