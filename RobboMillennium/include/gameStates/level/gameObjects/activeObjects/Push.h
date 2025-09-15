#pragma once
#include "Bullet.h"

class Push : public Bullet
{
public:
    Push(Coordinates position, Level* level);
    void Run() override;
    void PushPush(Direction direction);
};