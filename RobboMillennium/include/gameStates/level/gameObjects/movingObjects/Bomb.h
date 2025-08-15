#pragma once
#include "../MovingObject.h"
#include "../ActiveObject.h"

class Bomb : public MovingObject, public ActiveObject
{
public:
    Bomb(Coordinates position, Level* level);
    void Destroy() override;
    void Run() override;

private:
    void SetToExplode();
    int explodeTurn = false;
    void Explode();
};