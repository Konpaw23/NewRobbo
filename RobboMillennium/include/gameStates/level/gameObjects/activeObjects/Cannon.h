#pragma once
#include "../ActiveObject.h"
#include "../StaticObject.h"

class Cannon : public ActiveObject, public StaticObject
{
public:
    Cannon(Coordinates position, Direction rotation, Level* level);
    void Run() override;
    Direction GetRotation();

private:
    void Shoot();
    const Direction rotation;
};