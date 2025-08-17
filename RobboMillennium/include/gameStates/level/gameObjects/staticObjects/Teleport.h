#pragma once
#include "../StaticObject.h"

class Teleport : public StaticObject
{
public:
    Teleport(Coordinates position, Level* level);
};