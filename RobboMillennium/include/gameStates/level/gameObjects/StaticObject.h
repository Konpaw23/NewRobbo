#pragma once
#include "../../../basicProjectHeaders.h"
#include "GameObject.h"

class StaticObject : virtual public GameObject
{
public:
    StaticObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level);
};