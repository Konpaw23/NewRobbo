#pragma once
#include "../../ActiveObject.h"
#include "../../StaticObject.h"
#include "../../RotatingObject.h"
#include <cstdlib>

class LaserShooter : public ActiveObject, public StaticObject, public RotatingObject
{
public:
    LaserShooter(Coordinates position, Direction rotation, Level* level);
    void Run() override;

private:
    void Shoot();
};