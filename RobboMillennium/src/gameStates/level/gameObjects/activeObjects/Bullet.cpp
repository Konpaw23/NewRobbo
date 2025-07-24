#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Bullet.h"

Bullet::Bullet(Coordinates position, Direction trajectory, Level* level) :
        ActiveObject(BULLET, position, false, false, level), trajectory(trajectory)
{
    ;
}

void Bullet::Run()
{
    if(!this->Move(trajectory))
    {
        this->level->RemoveObject(this);
    }
}