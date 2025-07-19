#pragma once
#include "../../../basicProjectHeaders.h"
#include "../LevelHeaders.h"

class Collectible : GameObject
{
public:
    Collectible(GameObjectName objectName, Coordinates position, class Level* level);
    void PickUp();

private:
    Level* level;
};