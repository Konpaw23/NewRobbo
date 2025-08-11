#include "../../../../../include/gameStates/level/gameObjects/movingObjects/Chest.h"

Chest::Chest(Coordinates position, Level *level) : MovingObject(CHEST, position, false, true, level), GameObject(CHEST, position, false, true)
{
    ;
}