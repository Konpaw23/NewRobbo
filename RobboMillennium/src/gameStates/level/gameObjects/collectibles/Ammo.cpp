#include "../../../../../include/gameStates/level/gameObjects/collectibles/Ammo.h"

Ammo::Ammo(Coordinates position, Level* level) : GameObject(AMMO, position, false, false, level)
{
    ;
}

void Ammo::PickUp(Robbo *other)
{
    other->AddAmmo();
    Collectible::PickUp(other);
}