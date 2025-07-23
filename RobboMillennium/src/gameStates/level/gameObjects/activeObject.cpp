#include "../../../../include/gameStates/level/LevelHeaders.h"

activeObject::activeObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, class Level *level)
        : MovingObject(objectName, position, explosion_resistant, projectile_resistant, level)
{
    ;
}