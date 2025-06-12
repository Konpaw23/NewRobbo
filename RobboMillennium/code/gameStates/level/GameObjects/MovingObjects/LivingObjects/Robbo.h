#pragma once
#include "../../../../../basicProjectHeaders.h"
#include "../../../LevelHeaders.h"

class Robbo : public LivingObject
{
public:
    Robbo(Coordinates position, class Level* level);
    void SetAction(RobboAction action);

    virtual bool MoveLeft() override;
    bool MoveRight() override;
    bool MoveUp() override;
    bool MoveDown() override;

    void Run() override;
private:
    RobboAction action;
};