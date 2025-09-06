#pragma once
#include "../../ActiveObject.h"
#include "../../StaticObject.h"
#include <cstdlib>

class LaserShooter : public ActiveObject, public StaticObject
{
public:
    LaserShooter(Coordinates position, Direction rotation, Level* level);
    void Run() override;
    Direction GetRotation();

private:
    void Shoot();
    const Direction rotation;
};