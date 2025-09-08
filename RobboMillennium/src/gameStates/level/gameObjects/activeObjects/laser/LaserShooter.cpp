#include "../../../../../../include/gameStates/level/gameObjects/activeObjects/laser/LaserShooter.h"
#include "../../../../../../include/gameStates/level/Level.h"

LaserShooter::LaserShooter(Coordinates position, Direction rotation, Level* level) : GameObject(LASER_SHOOTER, position, false, true, level),
                                                                                     RotatingObject(rotation)
{
    ;
}

void LaserShooter::Run()
{
    int random = rand() % 100;
    if(random < 5)
    {
        this->Shoot();
    }
}

void LaserShooter::Shoot()
{
    Coordinates laserStartField = this->position.GetNext(this->rotation);

    GameObject* other = this->level->GetObjectFromPosition(laserStartField);

    if(other == nullptr)
    {
        this->level->CreateObject(LASER_HEAD, laserStartField.x, laserStartField.y, this->rotation);
    }
    else if(!other->IsProjectileResistant())
    {
        other->Destroy();
    }
    //else - projectile resistant object next to laser shooter
}