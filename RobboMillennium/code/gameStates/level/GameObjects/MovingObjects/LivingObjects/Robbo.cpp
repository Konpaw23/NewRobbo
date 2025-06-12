#include "../../../LevelHeaders.h"

Robbo::Robbo(Coordinates position, Level* level) : LivingObject(ROBBO, position, level)
{
    ;
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

void Robbo::Run()
{
    switch(action)
    {
        case GO_LEFT:
            MoveLeft();
            break;
        case GO_RIGHT:
            MoveRight();
            break;
        case GO_UP:
            MoveUp();
            break;
        case GO_DOWN:
            MoveDown();
            break;
    }
}