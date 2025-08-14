#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Wall.h"

Wall::Wall(Coordinates position, Level* level) : StaticObject(WALL, position, true, true, level), GameObject(WALL, position, true, true, nullptr)
{
    ;
}