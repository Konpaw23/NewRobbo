#pragma once
#include "../../ActiveObject.h"
#include "../../MovingObject.h"
#include "../../RotatingObject.h"

class LaserHead : public ActiveObject, public MovingObject, public RotatingObject
{
public:
    LaserHead(Coordinates position, Direction rotation, Level* level);
    void Run() override;

private:
    void GoForward();
    void GoBack();

    bool shooting = true;
};