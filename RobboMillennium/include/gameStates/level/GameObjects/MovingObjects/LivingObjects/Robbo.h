#pragma once
#include "../../../../../basicProjectHeaders.h"
#include "../LivingObject.h"

class Robbo : public LivingObject
{
public:
    Robbo(Coordinates position, class Level* level);
    void SetAction(RobboAction action);

    bool Move(Direction dir) override;
    void GiveScrew();

    void Run() override;
private:
    RobboAction action;
};