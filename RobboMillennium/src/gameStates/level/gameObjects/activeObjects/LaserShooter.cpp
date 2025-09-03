#include "../../../../../include/gameStates/level/gameObjects/activeObjects/LaserShooter.h"

LaserShooter::LaserShooter(Coordinates position, Direction rotation, Level* level) : GameObject(LASER_SHOOTER, position, false, true, level), rotation(rotation)
{
    ;
}

void LaserShooter::Run()
{
    int random = rand() % 100;
    if(random < 20)
    {
        this->Shoot();
    }
}

Direction LaserShooter::GetRotation()
{
    return this->rotation;
}

void LaserShooter::Shoot()
{
    //TODO;
}