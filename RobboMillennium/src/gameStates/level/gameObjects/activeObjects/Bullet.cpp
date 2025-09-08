#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Bullet.h"
#include "../../../../../include/gameStates/level/Level.h"

Bullet::Bullet(Coordinates position, Direction trajectory, Level* level) : GameObject(BULLET, position, false, true, level),
                                                                           RotatingObject(trajectory)
{
    ;
}

void Bullet::Run()
{
    if(!this->Move(rotation))
    {
        GameObject* other = this->level->GetObjectFromPosition(this->GetPosition().GetNext(rotation));
        if(other != nullptr && !other->IsProjectileResistant())
        {
            other->Destroy();
        }
        this->level->RemoveObject(this);
    }
}