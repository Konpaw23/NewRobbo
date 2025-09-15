#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Blaster.h"
#include "../../../../../include/gameStates/level/Level.h"

Blaster::Blaster(Coordinates position, Direction trajectory, Level* level) : GameObject(BLASTER, position, false, true, level), Bullet(position, trajectory, level)
{
    ;
}

void Blaster::Run()
{
    Coordinates start_position = this->position;
    if(!this->Move(rotation))
    {
        GameObject* other = this->level->GetObjectFromPosition(this->GetPosition().GetNext(rotation));
        Bush* bush = dynamic_cast<Bush*>(other);
        if(bush != nullptr)
        {
            this->level->RemoveObject(bush);
            this->Move(rotation);
            this->level->CreateObject(SMOKE, start_position.x, start_position.y);
            return;
        }
        else if(other != nullptr && !other->IsProjectileResistant())
        {
            other->Destroy();
        }
        this->level->RemoveObject(this);
        this->level->CreateObject(SMOKE, start_position.x, start_position.y);
    }
    else
    {
        this->level->CreateObject(SMOKE, start_position.x, start_position.y);
    }
}