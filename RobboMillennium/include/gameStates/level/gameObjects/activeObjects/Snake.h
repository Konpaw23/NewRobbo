#pragma once
#include "../MovingObject.h"
#include "../ActiveObject.h"

class Snake : public MovingObject, public ActiveObject
{
public:
    Snake(Coordinates position, Level* level);
    void Run() override;
    void Destroy() override;
    bool Move();

private:
    int lastMoveTime = -1;
};