#pragma once
#include "Cannon.h"
#include "../MovingObject.h"
#include "PurpleSeahorse.h"

class MovingCannon : public Cannon, public MovingObject
{
public:
    MovingCannon(Coordinates position, Level* level);
    void Run();

private:
    Direction moveDirection = RIGHT;
    bool move = false;
};