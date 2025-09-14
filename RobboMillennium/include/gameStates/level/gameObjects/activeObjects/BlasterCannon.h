#pragma once
#include "Cannon.h"

class BlasterCannon : public Cannon
{
public:
    BlasterCannon(Coordinates position, Direction rotation, Level* level);

private:
    void Shoot() override;
    void PlaceProjectile(Coordinates position) override;
};