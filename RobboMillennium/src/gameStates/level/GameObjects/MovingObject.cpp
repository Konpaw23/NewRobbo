#include "../../../../include/gameStates/level/LevelHeaders.h"

MovingObject::MovingObject(GameObjectName objectName, Coordinates position, Level* level) : GameObject(objectName, position), level(level)
{
    ;
}

bool MovingObject::IsActive()
{
    return isActive;
}

bool MovingObject::MoveLeft()
{
    if(position.x > 0 && level->GetObjectNameFromPosition(position.x-1, position.y) == NULL_OBJECT ||
        (isCollectingItems && level->IsObjectCollectible(position.x-1, position.y)))
    {
        level->MoveObjectLeft(this);
        position.x--;
        return true;
    }
    else
    {
        return false;
    }
}

//TODO it only overwrites field data when robbo get screws!!!
bool MovingObject::MoveRight()
{
    int xMax = level->GetWidth() - 1;
    if(position.x < xMax && level->GetObjectNameFromPosition(position.x+1, position.y) == NULL_OBJECT ||
        (isCollectingItems && level->IsObjectCollectible(position.x+1, position.y)))
    {
        level->MoveObjectRight(this);
        position.x++;
        return true;
    }
    else
    {
        return false;
    }
}
bool MovingObject::MoveUp()
{
    if(position.y > 0 && level->GetObjectNameFromPosition(position.x, position.y-1) == NULL_OBJECT ||
         (isCollectingItems && level->IsObjectCollectible(position.x, position.y-1)))
    {
        level->MoveObjectUp(this);
        position.y--;
        return true;
    }
    else
    {
        return false;
    }
}
bool MovingObject::MoveDown()
{
    int yMax = level->GetHeight() - 1;
    if(position.y < yMax && level->GetObjectNameFromPosition(position.x, position.y+1) == NULL_OBJECT ||
        (isCollectingItems && level->IsObjectCollectible(position.x, position.y+1)))
    {
        level->MoveObjectDown(this);
        position.y++;
        return true;
    }
    else
    {
        return false;
    }
}