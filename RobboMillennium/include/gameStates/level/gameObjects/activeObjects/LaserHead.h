#pragma once
#include "../ActiveObject.h"
#include "../MovingObject.h"

class LaserHead : public ActiveObject, public MovingObject
{
public:
    LaserHead(Coordinates position, Direction rotation, Level* level);
    void Run() override;
    Direction GetRotation();

private:
    Direction rotation;
};