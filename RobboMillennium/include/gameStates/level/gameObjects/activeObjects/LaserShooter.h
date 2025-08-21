#pragma once
#include "../ActiveObject.h"
#include "../StaticObject.h"

class LaserShooter : public ActiveObject, public StaticObject
{
public:
    LaserShooter(Coordinates position, Direction rotation, Level* level);
    void Run() override;
    Direction GetRotation();

private:
    const Direction rotation;
};