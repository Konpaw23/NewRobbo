#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"
#include "../MovingObject.h"

class Robbo : public ActiveObject, public MovingObject
{
public:
    Robbo(Coordinates position, class Level* level);
    void SetAction(RobboAction action);

    bool Move(Direction dir) override;
    void GiveScrew();
    void GiveKey();
    bool HasKey();
    void UseKey();
    void AddAmmo();
    void Shot(Direction dir);

    void Run() override;
private:
    int keys;
    int ammo;
    int shootDelay;
    RobboAction action;
};