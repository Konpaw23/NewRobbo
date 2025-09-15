#include "../../../../../include/gameStates/level/gameObjects/activeObjects/BlasterCannon.h"
#include "../../../../../include/gameStates/level/Level.h"

BlasterCannon::BlasterCannon(Coordinates position, Direction rotation, Level *level) : GameObject(BLASTER_CANNON, position, false, true, level), Cannon(position, rotation, level)
{
    ;
}

void BlasterCannon::Shoot()
{
    Coordinates bulletField = this->position.GetNext(this->rotation);

    GameObject* other = this->level->GetObjectFromPosition(bulletField);

    if(other == nullptr)
    {
        this->PlaceProjectile(bulletField);
    }
    else if(!other->IsProjectileResistant())
    {
        other->Destroy();
        if(other->GetObjectName() == BUSH)
        {
            this->PlaceProjectile(bulletField);
        }
    }
}

void BlasterCannon::PlaceProjectile(Coordinates position)
{
    this->level->CreateObject(BLASTER, position.x, position.y, this->rotation);
}