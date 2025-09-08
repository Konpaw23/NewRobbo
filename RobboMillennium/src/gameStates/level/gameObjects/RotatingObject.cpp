#include "../../../../include/gameStates/level/gameObjects/RotatingObject.h"

RotatingObject::RotatingObject(Direction rotation) : rotation(rotation)
{
    ;
}

Direction RotatingObject::GetRotation()
{
    return this->rotation;
}