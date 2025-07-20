#pragma once
#include "../../../basicProjectHeaders.h"
#include "StaticObject.h"

class Collectible : public StaticObject
{
public:
    Collectible(GameObjectName objectName, Coordinates position, class Level* level);
    void PickUp();

private:
    Level* level;
};