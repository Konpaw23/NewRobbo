#include "../../../../../../include/gameStates/level/gameObjects/activeObjects/laser/LaserBody.h"

LaserBody::LaserBody(Coordinates position, Axis axis, Level *level) : GameObject(LASER_BODY, position, true, true, level), axis(axis)
{
    ;
}