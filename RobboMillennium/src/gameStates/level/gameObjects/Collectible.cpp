#include "../../../../include/gameStates/level/gameObjects/Collectible.h"
#include "../../../../include/gameStates/level/Level.h"

Collectible::Collectible(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, class Level* level) :
        StaticObject(objectName, position, explosion_resistant, projectile_resistant, level), GameObject(*dynamic_cast<GameObject*>(this))
{
    ;
}

void Collectible::PickUp(Robbo* other)
{
    this->level->RemoveObject(this);
    delete this;
}