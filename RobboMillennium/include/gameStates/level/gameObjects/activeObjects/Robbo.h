#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../activeObject.h"

class Robbo : public activeObject
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