#include "../../../../../include/gameStates/level/gameObjects/activeObjects/LaserHead.h"

LaserHead::LaserHead(Coordinates position, Direction rotation, Level *level) : GameObject(LASER_HEAD, position, true, true, level), rotation(rotation)
{
    ;
}

void LaserHead::Run()
{
    ;
}

Direction LaserHead::GetRotation()
{
    return this->rotation;
}