#include "../../../../include/gameStates/level/GameObjects/Collectible.h"

Collectible::Collectible(GameObjectName objectName, Coordinates position, class Level* level) :
        GameObject(objectName, position), level(level)
{
    ;
}

void Collectible::PickUp()
{
    delete this;
}