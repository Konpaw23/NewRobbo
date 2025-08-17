#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Teleport.h"

//TODO is teleport explosion resistant?
Teleport::Teleport(Coordinates position, Level* level) : GameObject(TELEPORT, position, true, true, level)
{
    ;
}