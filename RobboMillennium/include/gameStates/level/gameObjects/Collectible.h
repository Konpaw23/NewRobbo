#pragma once
#include "../../../basicProjectHeaders.h"
#include "StaticObject.h"
#include "activeObjects/Robbo.h"

class Collectible : public StaticObject
{
public:
    Collectible(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, class Level* level);
    virtual void PickUp(Robbo* other);
};