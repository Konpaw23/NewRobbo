#include "../../../../include/gameStates/level/gameObjects/RotatingObject.h"

RotatingObject::RotatingObject(Direction rotation) : rotation(rotation)
{
    ;
}

Direction RotatingObject::GetRotation()
{
    return this->rotation;
}

void RotatingObject::Rotate(Direction direction)
{
    this->rotation = GetDirectionNextTo(this->rotation, direction);
}