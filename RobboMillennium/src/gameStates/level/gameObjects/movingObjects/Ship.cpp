#include "../../../../../include/gameStates/level/gameObjects/movingObjects/Ship.h"

Ship::Ship(Coordinates position, Level* level) : GameObject(SHIP, position, false, true, level), MovingObject(true)
{
    ;
}

void Ship::OpenExit()
{
    this->isOpen = true;
}

bool Ship::IsOpen()
{
    return this->isOpen;
}