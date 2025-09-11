#pragma once
#include "../ActiveObject.h"
#include "../RotatingObject.h"
#include "../StaticObject.h"
#include "Robbo.h"

class Magnet : public ActiveObject, public RotatingObject, public StaticObject
{
public:
    Magnet(Coordinates position, Direction rotation, Level* level);

    void Run() override;

private:
    void AttractRobbo(Robbo* robbo);
};