#pragma once
#include "GameObject.h"

class RotatingObject : virtual public GameObject
{
public:
    RotatingObject(Direction rotation);
    Direction GetRotation();

protected:
    Direction rotation;
};