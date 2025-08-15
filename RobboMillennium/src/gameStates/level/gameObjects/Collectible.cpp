#include "../../../../include/gameStates/level/gameObjects/Collectible.h"
#include "../../../../include/gameStates/level/Level.h"

Collectible::Collectible() : StaticObject(), GameObject()
{
    ;
}

void Collectible::PickUp(Robbo* other)
{
    this->level->RemoveObject(this);
    delete this;
}