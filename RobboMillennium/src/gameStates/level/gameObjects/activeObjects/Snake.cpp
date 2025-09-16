#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Snake.h"
#include "../../../../../include/gameStates/level/Level.h"

Snake::Snake(Coordinates position, Level* level) : GameObject(SNAKE, position, false, false, level), MovingObject(false)
{
    ;
}

void Snake::Run()
{
    this->Move();
}

void Snake::Destroy()
{
    this->level->RemoveObject(this);
}

bool Snake::Move()
{
    if(this->lastMoveTime == this->level->GetTurnNumber())
    {
        return false;
    }
    this->lastMoveTime = this->level->GetTurnNumber();

    if(!MovingObject::Move(LEFT))
    {
        GameObject* other = this->level->GetObjectFromPosition(this->position.GetNext(LEFT));
        if(other != nullptr && !other->IsExplosionResistant())
        {
            if(other->GetObjectName() == SNAKE)
            {
                Snake* otherSnake = dynamic_cast<Snake*>(other);
                if(!otherSnake->Move())
                {
                    return false;
                }
            }
            else
            {
                this->level->RemoveObject(other);
            }
            return MovingObject::Move(LEFT);
        }
        else
        {
            Coordinates onRight = this->position.GetNext(RIGHT);
            while(true)
            {
                other = this->level->GetObjectFromPosition(onRight);
                if(other != nullptr && other->IsExplosionResistant() || this->level->GetObjectNameFromPosition(onRight) == WALL)
                {
                    Coordinates newPos = onRight.GetNext(LEFT);
                    other = this->level->GetObjectFromPosition(newPos);
                    if(other != nullptr)
                    {
                        if(other->GetObjectName() == SNAKE)
                        {
                            Snake* otherSnake = dynamic_cast<Snake*>(other);
                            if(!otherSnake->Move())
                            {
                                return false;
                            }
                        }
                        else
                        {
                            this->level->RemoveObject(other);
                        }
                    }
                    this->level->MoveObject(this, newPos);
                    this->position = newPos;
                    return true;
                }
                else
                {
                    onRight = onRight.GetNext(RIGHT);
                }
            }
        }
    }
    else
    {
        return true;
    }
}