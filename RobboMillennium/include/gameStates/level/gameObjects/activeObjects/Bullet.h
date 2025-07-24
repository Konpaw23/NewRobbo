#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"

//TODO bullets can be moved by Robbo!!! Fix this
class Bullet : public ActiveObject
{
public:
    Bullet(Coordinates position, Direction trajectory, class Level* level);
    void Run() override;
private:
    const Direction trajectory;
};