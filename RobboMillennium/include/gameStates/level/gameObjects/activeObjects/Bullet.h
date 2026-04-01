#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"
#include "../MovingObject.h"
#include "../RotatingObject.h"

class Bullet : public ActiveObject, public MovingObject, public RotatingObject
{
public:
    Bullet(Coordinates position, Direction trajectory, class Level* level);
    void Run() override;
};