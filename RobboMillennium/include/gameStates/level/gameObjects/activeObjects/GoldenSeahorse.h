#pragma once
#include "../MovingObject.h"
#include "../ActiveObject.h"
#include "../RotatingObject.h"
#include "../KillingObject.h"

class GoldenSeahorse : public MovingObject, public ActiveObject, public RotatingObject, public KillingObject
{
public:
    GoldenSeahorse(Coordinates position, Direction movementSide, Direction initialDirection, Level* level);
    void Run() override;

private:
    const Direction movementSide;
};