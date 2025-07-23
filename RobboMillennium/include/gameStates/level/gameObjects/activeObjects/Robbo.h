#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"

class Robbo : public ActiveObject
{
public:
    Robbo(Coordinates position, class Level* level);
    void SetAction(RobboAction action);

    bool Move(Direction dir) override;
    void GiveScrew();
    void AddAmmo();
    void Shot();

    void Run() override;
private:
    int ammo;
    RobboAction action;
};