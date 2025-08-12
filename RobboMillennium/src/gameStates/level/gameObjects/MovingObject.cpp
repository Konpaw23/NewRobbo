#include "../../../../include/gameStates/level/LevelHeaders.h"

MovingObject::MovingObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level) :
    GameObject(objectName, position, explosion_resistant, projectile_resistant, level)
{
    ;
}

bool MovingObject::IsActive()
{
    return isActive;
}

//TODO I don't like this func
bool MovingObject::Move(Direction dir)
{
    Coordinates* dest = level->GetNextPosition(this->position, dir);
    if(dest == nullptr)
        //position out of level range
        return false;
    GameObject* other = level->GetObjectFromPosition(*dest);
    if(level->GetObjectNameFromPosition(*dest) == NULL_OBJECT)
    {
        level->MoveObject(this, *dest);
        this->position = *dest;
        delete dest;
        return true;
    }
    delete dest;
    return false;
}