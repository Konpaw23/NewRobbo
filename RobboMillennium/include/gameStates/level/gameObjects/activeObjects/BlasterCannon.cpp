#include "BlasterCannon.h"
#include "../../../../../include/gameStates/level/Level.h"

BlasterCannon::BlasterCannon(Coordinates position, Direction rotation, Level *level) : GameObject(BLASTER_CANNON, position, false, true, level), Cannon(position, rotation, level)
{
    ;
}

void BlasterCannon::PlaceProjectile(Coordinates position)
{
    this->level->CreateObject(BLASTER, position.x, position.y, this->rotation);
}