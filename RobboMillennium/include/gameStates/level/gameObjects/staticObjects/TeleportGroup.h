#pragma once
#include <vector>
#include "Teleport.h"

class TeleportGroup
{
public:
    TeleportGroup(std::vector<Teleport*>* teleports);

    void TeleportToNext()

private:
    std::vector<Teleport*> teleports;
};