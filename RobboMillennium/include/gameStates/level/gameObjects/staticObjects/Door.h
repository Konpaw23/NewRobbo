#pragma once
#include "../StaticObject.h"
#include "../activeObjects/Robbo.h"

class Door : public StaticObject
{
public:
    Door(Coordinates position, Level* level);

    void Open(Robbo* player);
};
