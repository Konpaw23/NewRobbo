#pragma once
#include "../Collectible.h"

//TODO life should not be available after taking in current game
class Life : public Collectible
{
public:
    Life(Coordinates position, Level* level);

    void PickUp(Robbo* other) override;
};