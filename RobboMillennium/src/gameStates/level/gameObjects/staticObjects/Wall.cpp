#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Wall.h"

Wall::Wall(Coordinates position) : StaticObject(WALL, position, true, true, level), GameObject(WALL, position, true, true, level)
{
    ;
}