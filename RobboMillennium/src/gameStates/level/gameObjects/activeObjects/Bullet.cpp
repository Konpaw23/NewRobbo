#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Bullet.h"

Bullet::Bullet(Coordinates position, Direction trajectory, class Level* level) :
        ActiveObject(BULLET, position, false, false, level), trajectory(trajectory)
{
    ;
}

void Bullet::Run()
{
    this->Move(trajectory);
}