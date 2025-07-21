#include "../../../../../../include/gameStates/level/LevelHeaders.h"

Robbo::Robbo(Coordinates position, Level* level) : LivingObject(ROBBO, position, level)
{
    ;
}

void Robbo::SetAction(RobboAction action)
{
    this->action = action;
}

bool Robbo::Move(Direction dir)
{
    if(!MovingObject::Move(dir))
    {
        //TODO powalone rzeczy sie tu dzieja
        Coordinates* dest = this->level->GetNextPosition(this->position, dir);
        if(dest != nullptr)
        {
            GameObject* object = level->GetObjectFromPosition(*dest);
            MovingObject* movingObject = dynamic_cast<MovingObject*>(object);
            if(movingObject != nullptr)
            {
                if(movingObject->Move(dir))
                {
                    //can use this function because movable object is moved already (inside if statement above)
                    MovingObject::Move(dir);
                    return true;
                }
            }
        }

        //screws
        GameObject* other = level->GetObjectFromPosition(*dest);
        Collectible* item = dynamic_cast<Collectible*>(other);
        if(item != nullptr)
        {
            item->PickUp(this);
            level->MoveObject(this, *dest);
            this->position = *dest;
            delete dest;
            return true;
        }
    }
    return false;
}

void Robbo::GiveScrew()
{
    this->level->DecreaseScrewsNumber();
}

void Robbo::Run()
{
    switch(action)
    {
        case GO_LEFT:
            Move(LEFT);
            break;
        case GO_RIGHT:
            Move(RIGHT);
            break;
        case GO_UP:
            Move(UP);
            break;
        case GO_DOWN:
            Move(DOWN);
            break;
    }
}