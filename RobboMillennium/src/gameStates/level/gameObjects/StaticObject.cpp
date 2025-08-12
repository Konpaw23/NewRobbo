#include "../../../../include/gameStates/level/GameObjects/StaticObject.h"

StaticObject::StaticObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level) :
    GameObject(objectName, position, explosion_resistant, projectile_resistant, level)
{
    ;
}