#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../Collectible.h"

class Screw : public Collectible
{
public:
    Screw(Coordinates position, Level* level);

    void PickUp(Robbo* other) override;
};