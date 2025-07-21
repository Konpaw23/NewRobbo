#include "../../../../include/gameStates/level/GameObjects/Collectible.h"

Collectible::Collectible(GameObjectName objectName, Coordinates position, class Level* level) :
        StaticObject(objectName, position), level(level)
{
    ;
}

void Collectible::PickUp(Robbo* other)
{
    delete this;
}