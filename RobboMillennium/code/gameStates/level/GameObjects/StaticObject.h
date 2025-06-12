#pragma once
#include "../../../basicProjectHeaders.h"
#include "../GameObject.h"

class StaticObject : public GameObject
{
public:
    StaticObject(GameObjectName objectName, Coordinates position);
};