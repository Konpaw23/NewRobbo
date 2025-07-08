#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../../LevelHeaders.h"

class LivingObject : public MovingObject
{
public:
    LivingObject(GameObjectName objectName, Coordinates position, class Level* level);
    virtual void Run() = 0;
};
