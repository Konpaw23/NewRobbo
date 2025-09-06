#include "../../../../../include/gameStates/level/gameObjects/activeObjects/laser/LaserHead.h"
#include "../../../../../include/gameStates/level/Level.h"

LaserHead::LaserHead(Coordinates position, Direction rotation, Level *level) : GameObject(LASER_HEAD, position, true, true, level), rotation(rotation)
{
    ;
}

void LaserHead::Run()
{
    if(shooting)
    {
        Coordinates* nextPosition = this->level->GetNextPosition(this->position, this->rotation);

        if(nextPosition == nullptr)
        {
            this->shooting = false;
            this->GoBack();
            return;
        }

        GameObject* other = this->level->GetObjectFromPosition(*nextPosition);
        if(other == nullptr)
        {
            this->GoForward();
        }
        else
        {
            if(!other->IsProjectileResistant())
            {
                other->Destroy();
            }
            this->shooting = false;
            this->GoBack();
        }


        delete nextPosition;
    }
    else
    {
        this->GoBack();
    }
}

Direction LaserHead::GetRotation()
{
    return this->rotation;
}

void LaserHead::GoForward()
{
    this->Move(rotation);
    //TODO create here LaserBody object in level
}

void LaserHead::GoBack()
{
    Direction backDir = GetOppositeDirection(rotation);
    Coordinates* nextPos = this->level->GetNextPosition(this->position, backDir);
    if(nextPos != nullptr)
    {
        GameObject* other = this->level->GetObjectFromPosition(*nextPos);
        if(other != nullptr && other->GetObjectName() == LASER_BODY)
        {
            this->level->RemoveObject(other);
            this->Move(backDir);
        }
        else
        {
            this->level->RemoveObject(this);
        }
        delete nextPos;
    }
}