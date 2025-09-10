#pragma once
#include "GameObject.h"

class RotatingObject : virtual public GameObject
{
public:
    RotatingObject(Direction rotation);
    Direction GetRotation();

protected:
    void Rotate(Direction direction);
    void RotateToOpposite();

    Direction rotation;
};