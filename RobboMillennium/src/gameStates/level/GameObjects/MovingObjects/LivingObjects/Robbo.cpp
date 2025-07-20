#include "../../../../../../include/gameStates/level/LevelHeaders.h"

Robbo::Robbo(Coordinates position, Level* level) : LivingObject(ROBBO, position, level)
{
    isCollectingItems = true;
}

void Robbo::SetAction(RobboAction action)
{
    this->action = action;
}

bool Robbo::MoveLeft()
{
    if(!MovingObject::MoveLeft())
    {
        GameObject* object = level->GetObjectFromPosition(position.x-1, position.y);
        MovingObject* movingObject = dynamic_cast<MovingObject*>(object);
        if(movingObject != nullptr)
        {
            if(movingObject->MoveLeft())
            {
                level->MoveObjectLeft(this);
                position.x--;
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}
bool Robbo::MoveRight()
{
    if(!MovingObject::MoveRight())
    {
        GameObject* object = level->GetObjectFromPosition(position.x+1, position.y);
        MovingObject* movingObject = dynamic_cast<MovingObject*>(object);
        if(movingObject != nullptr)
        {
            if(movingObject->MoveRight())
            {
                level->MoveObjectRight(this);
                position.x++;
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}
bool Robbo::MoveUp()
{
    if(!MovingObject::MoveUp())
    {
        GameObject* object = level->GetObjectFromPosition(position.x, position.y-1);
        MovingObject* movingObject = dynamic_cast<MovingObject*>(object);
        if(movingObject != nullptr)
        {
            if(movingObject->MoveUp())
            {
                level->MoveObjectUp(this);
                position.y--;
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
}
bool Robbo::MoveDown()
{
    if(!MovingObject::MoveDown())
    {
        GameObject* object = level->GetObjectFromPosition(position.x, position.y+1);
        MovingObject* movingObject = dynamic_cast<MovingObject*>(object);
        if(movingObject != nullptr)
        {
            if(movingObject->MoveDown())
            {
                level->MoveObjectDown(this);
                position.y++;
                return true;
            }
        }
        return false;
    }
    else
    {
        return true;
    }
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