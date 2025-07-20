#include "../../../../../../include/gameStates/level/LevelHeaders.h"

Robbo::Robbo(Coordinates position, Level* level) : LivingObject(ROBBO, position, level)
{
    isCollectingItems = true;
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
        Coordinates* next_pos = this->level->GetNextPosition(this->position, dir);
        if(next_pos != nullptr)
        {
            GameObject* object = level->GetObjectFromPosition(*next_pos);
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
    }
    return false;
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