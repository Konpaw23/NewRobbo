#include "../../../../../include/gameStates/level/gameObjects/activeObjects/LaserShooter.h"

LaserShooter::LaserShooter(Coordinates position, Direction rotation, Level* level) : GameObject(LASER_SHOOTER, position, false, true, level), rotation(rotation)
{
    ;
}

void LaserShooter::Run()
{
    ;
}

Direction LaserShooter::GetRotation()
{
    return this->rotation;
}