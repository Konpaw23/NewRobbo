#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"
#include "../MovingObject.h"

//TODO bullets can be moved by Robbo!!! Fix this
class Bullet : public ActiveObject, public MovingObject
{
public:
    Bullet(Coordinates position, Direction trajectory, class Level* level);
    void Run() override;
private:
    const Direction trajectory;
};