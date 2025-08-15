#include "../../../../../include/gameStates/level/GameObjects/collectibles/Screw.h"

Screw::Screw(Coordinates position, Level* level) : GameObject(SCREW, position, false, true, level)
{
    ;
}

void Screw::PickUp(Robbo* other)
{
    other->GiveScrew();
    Collectible::PickUp(other);
}