#include "../../../../../include/gameStates/level/gameObjects/staticObjects/BushWall.h"

BushWall::BushWall(Coordinates position, Level *level) : Wall(position, level), GameObject(BUSH_WALL, position, true, true, level)
{
    ;
}