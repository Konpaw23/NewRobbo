#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../MovingObject.h"

class LivingObject : public MovingObject
{
public:
    LivingObject(GameObjectName objectName, Coordinates position, class Level* level);
    virtual void Run() = 0;
};
