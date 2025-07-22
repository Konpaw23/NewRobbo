#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Wall.h"

Wall::Wall(Coordinates position) : StaticObject(WALL, position)
{
    explosion_resistant = true;
    projectile_resistant = true;
}