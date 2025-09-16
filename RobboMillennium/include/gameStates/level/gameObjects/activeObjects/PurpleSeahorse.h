#pragma once
#include "../MovingObject.h"
#include "../ActiveObject.h"
#include "../RotatingObject.h"
#include "../KillingObject.h"

class PurpleSeahorse : public MovingObject, public ActiveObject, public RotatingObject, public KillingObject
{
public:
    PurpleSeahorse(Coordinates position, Direction initialDirection, Level* level);
    PurpleSeahorse(Coordinates position, Direction initialDirection, int initialMovePause, Level* level);
    void Run() override;

private:
    const Axis movementAxis;
    int movePause = 0;
};