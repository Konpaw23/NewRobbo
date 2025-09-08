#pragma once
#include "../ActiveObject.h"
#include "../StaticObject.h"
#include "../RotatingObject.h"

class Cannon : public ActiveObject, public StaticObject, public RotatingObject
{
public:
    Cannon(Coordinates position, Direction rotation, Level* level);
    void Run() override;

private:
    void Shoot();
};