#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../MovingObject.h"

class Chest : public MovingObject
{
public:
    Chest(Coordinates position, Level* level);
};