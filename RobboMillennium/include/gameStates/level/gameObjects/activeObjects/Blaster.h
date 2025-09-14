#pragma once
#include "Bullet.h"

class Blaster : public Bullet
{
public:
    Blaster(Coordinates position, Direction trajectory, Level* level);
    void Run() override;
};