#pragma once
#include "../MovingObject.h"
#include "../ActiveObject.h"
#include "../KillingObject.h"

class Eye : public MovingObject, public ActiveObject, public KillingObject
{
public:
    Eye(Coordinates position, Level* level);

    void Run() override;

private:
    void MoveTowardsRobbo();
    void MoveRandom();
};