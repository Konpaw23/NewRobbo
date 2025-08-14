#include "../../../../../include/gameStates/level/gameObjects/staticObjects/Bush.h"

Bush::Bush(Coordinates position, Level* level) : GameObject(BUSH, position, false, false, level), StaticObject(BUSH, position, false, false, level)
{
    ;
}