#include "../../../../../include/gameStates/level/GameObjects/collectibles/Screw.h"

Screw::Screw(Coordinates position, Level* level) : Collectible(SCREW, position, false, true, level), GameObject(SCREW, position, false, true, level)
{
    ;
}

void Screw::PickUp(Robbo* other)
{
    other->GiveScrew();
    Collectible::PickUp(other);
}