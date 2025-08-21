#pragma once
#include "../ActiveObject.h"
#include "../StaticObject.h"

class LaserShooter : public ActiveObject, public StaticObject
{
public:
    LaserShooter(Coordinates position, Direction rotation, Level* level);

    Direction GetRotation();

private:
    const Direction rotation;
};