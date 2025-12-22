#pragma once
#include "gameStates/level/gameObjects/Collectible.h"

class Stop : public Collectible
{
public:
    Stop(Coordinates position, Level* level);
    void PickUp(Robbo* other) override;

private:
    //duration in number of sequences
    const int stopDuration = 30;
};