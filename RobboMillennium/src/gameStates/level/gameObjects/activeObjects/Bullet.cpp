#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Bullet.h"
#include "../../../../../include/gameStates/level/Level.h"

//TODO when two constructors from both ActiveObject and MovingObject called, redundancy of data
//TODO not sure if bullets are bulletproof (when shot on side of bullet, its not disappears?)
Bullet::Bullet(Coordinates position, Direction trajectory, Level* level) :
        ActiveObject(BULLET, position, false, true, level), MovingObject(BULLET, position, false, true, level), trajectory(trajectory), GameObject(BULLET, position, false, true, level)
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