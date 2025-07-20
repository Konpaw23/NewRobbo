#pragma once
#include "../../../../../basicProjectHeaders.h"
#include "../../../LevelHeaders.h"

class Robbo : public LivingObject
{
public:
    Robbo(Coordinates position, class Level* level);
    void SetAction(RobboAction action);

    bool Move(Direction dir) override;

    void Run() override;
private:
    RobboAction action;
};