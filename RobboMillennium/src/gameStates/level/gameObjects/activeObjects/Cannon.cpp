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
        this->level->SpawnBullet(bulletField, this->rotation);
    }
    else if(!other->IsProjectileResistant())
    {
        other->Destroy();
    }
    //else - projectile resistant object next to laser shooter
}