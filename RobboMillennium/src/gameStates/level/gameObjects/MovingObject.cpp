#include "../../../../include/gameStates/level/gameObjects/MovingObject.h"
#include "../../../../include/gameStates/level/Level.h"

MovingObject::MovingObject() : GameObject()
{
    ;
}

MovingObject::MovingObject(bool canBeMovedByRobbo) : GameObject(), canBeMovedByRobbo(canBeMovedByRobbo)
{
    ;
}

bool MovingObject::Move(Direction dir)
{
    std::optional<Coordinates> dest = level->GetNextPosition(this->position, dir);
    if(!dest.has_value())
        //position out of level range
        return false;
    GameObject* other = level->GetObjectFromPosition(*dest);
    if(level->GetObjectNameFromPosition(*dest) == NULL_OBJECT)
    {
        level->MoveObject(this, *dest);
        this->position = *dest;
        return true;
    }
    return false;
}