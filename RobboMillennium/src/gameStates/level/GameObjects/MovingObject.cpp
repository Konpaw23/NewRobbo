#include "../../../../include/gameStates/level/LevelHeaders.h"

MovingObject::MovingObject(GameObjectName objectName, Coordinates position, Level* level) : GameObject(objectName, position), level(level)
{
    ;
}

bool MovingObject::IsActive()
{
    return isActive;
}

//TODO it only overwrites field data when robbo get screws!!!
//TODO I don't like this func
bool MovingObject::Move(Direction dir)
{
    Coordinates* dest = level->GetNextPosition(this->position, dir);
    if(dest != nullptr && (level->GetObjectNameFromPosition(*dest) == NULL_OBJECT ||
        (this->isCollectingItems && level->IsObjectCollectible(*dest) ) ) )
    {
        level->MoveObject(this, *dest);
        this->position = *dest;
        delete dest;
        return true;
    }
    else
    {
        delete dest;
        return false;
    }
}