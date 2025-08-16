#pragma once
#include "../../../basicProjectHeaders.h"
#include "GameObject.h"

class Level;

class MovingObject : virtual public GameObject
{
public:
    MovingObject();

    //returns true when object moved (no walls etc.)
    virtual bool Move(Direction dir);
};