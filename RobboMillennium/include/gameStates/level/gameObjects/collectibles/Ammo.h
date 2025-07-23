#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../Collectible.h"

class Ammo : public Collectible
{
public:
    Ammo(Coordinates position, Level* level);
    void PickUp(Robbo* other) override;
};