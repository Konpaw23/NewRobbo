#include "../../../../include/gameStates/level/LevelHeaders.h"

activeObject::activeObject(GameObjectName objectName, Coordinates position, class Level *level)
        : MovingObject(objectName, position, level)
{
    ;
}