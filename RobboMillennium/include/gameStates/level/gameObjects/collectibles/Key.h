#pragma once
#include "../Collectible.h"

class Key : public Collectible
{
public:
    Key(Coordinates position, Level* level);

    void PickUp(Robbo* other) override;
};