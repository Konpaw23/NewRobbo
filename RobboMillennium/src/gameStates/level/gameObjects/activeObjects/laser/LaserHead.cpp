#include "../../../../../../include/gameStates/level/gameObjects/activeObjects/laser/LaserHead.h"
#include "../../../../../../include/gameStates/level/Level.h"

LaserHead::LaserHead(Coordinates position, Direction rotation, Level *level) : GameObject(LASER_HEAD, position, true, true, level),
                                                                               RotatingObject(rotation)
{
    ;
}

void LaserHead::Run()
{
    if(shooting)
    {
        std::optional<Coordinates> nextPosition = this->level->GetNextPosition(this->position, this->rotation);

        if(!nextPosition.has_value())
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
    }
    else
    {
        this->GoBack();
    }
}

void LaserHead::GoForward()
{
    Coordinates initialPosition = this->position;
    this->Move(rotation);
    this->level->CreateObject(LASER_BODY, initialPosition.x, initialPosition.y, GetAxis(this->rotation));
}

void LaserHead::GoBack()
{
    Direction backDir = GetOppositeDirection(rotation);
    std::optional<Coordinates> nextPos = this->level->GetNextPosition(this->position, backDir);
    if(nextPos.has_value())
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
    }
}