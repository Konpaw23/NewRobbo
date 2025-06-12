#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../../LevelHeaders.h"

class Chest : public MovingObject
{
public:
    Chest(Coordinates position, Level* level);
};