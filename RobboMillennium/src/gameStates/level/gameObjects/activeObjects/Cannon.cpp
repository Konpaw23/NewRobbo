#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Cannon.h"
#include "../../../../../include/gameStates/level/Level.h"

Cannon::Cannon(Coordinates position, Direction rotation, Level* level) : GameObject(CANNON, position, false, true, level),
                                                                         RotatingObject(rotation)
{
    ;
}

void Cannon::Run()
{
    int random = rand() % 100;
    if(random < 5)
    {
        this->Shoot();
    }
}

void Cannon::Shoot()
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
    }
}

void Cannon::PlaceProjectile(Coordinates position)
{
    this->level->SpawnBullet(position, this->rotation);
}