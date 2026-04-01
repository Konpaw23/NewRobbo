#pragma once
#include "../Collectible.h"

class Life : public Collectible
{
public:
    Life(Coordinates position, Level* level);

    void PickUp(Robbo* other) override;
};