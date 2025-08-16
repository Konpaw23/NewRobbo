#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Bullet.h"
#include "../../../../../include/gameStates/level/Level.h"

Bullet::Bullet(Coordinates position, Direction trajectory, Level* level) : GameObject(BULLET, position, false, true, level), trajectory(trajectory)
{
    ;
}

void Bullet::Run()
{
    if(!this->Move(trajectory))
    {
        GameObject* other = this->level->GetObjectFromPosition(this->GetPosition().GetNext(trajectory));
        if(!other->IsProjectileResistant())
        {
            other->Destroy();
        }
        this->level->RemoveObject(this);
    }
}