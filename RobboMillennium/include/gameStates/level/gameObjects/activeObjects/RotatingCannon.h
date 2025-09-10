#pragma once
#include "Cannon.h"

class RotatingCannon : virtual public Cannon
{
public:
    RotatingCannon(Coordinates position, Direction initialRotation, Level* level);
    void Run() override;
};
