#pragma once
#include "../../StaticObject.h"

class LaserBody : public StaticObject
{
public:
    LaserBody(Coordinates position, Axis axis, Level* level);
    const Axis axis;
};
