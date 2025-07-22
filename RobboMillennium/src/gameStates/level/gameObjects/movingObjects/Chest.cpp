#include "../../../../../include/gameStates/level/LevelHeaders.h"

Chest::Chest(Coordinates position, Level *level) : MovingObject(CHEST, position, level)
{
    explosion_resistant = false;
    projectile_resistant = true;
}