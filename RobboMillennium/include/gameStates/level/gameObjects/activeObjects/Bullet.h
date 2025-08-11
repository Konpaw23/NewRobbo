#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"
#include "../MovingObject.h"

//TODO bullets can be moved by Robbo!!! Fix this
//TODO when bullet hit wall, Robbo disappears in the same place!!!
//TODO it seems like bullet is still in the field (in active objects but no in fields!!)
class Bullet : public ActiveObject, public MovingObject
{
public:
    Bullet(Coordinates position, Direction trajectory, class Level* level);
    void Run() override;
private:
    const Direction trajectory;
};