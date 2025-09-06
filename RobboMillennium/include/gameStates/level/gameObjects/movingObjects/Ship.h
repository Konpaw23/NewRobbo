#pragma once
#include "../MovingObject.h"

class Ship : public MovingObject
{
public:
    Ship(Coordinates position, Level* level);

    void OpenExit();
    bool IsOpen();

private:
    bool isOpen = false;
};