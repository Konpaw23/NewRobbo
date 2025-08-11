#pragma once
#include "../../../basicProjectHeaders.h"
#include "GameObject.h"

//TODO activeObject should inherit from GameObject, because it is not that active object always moves (example: shooter, laser)
//TODO then active and moving object should inherit from two classes
class ActiveObject : virtual public GameObject
{
public:
    ActiveObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, class Level* level);
    virtual void Run() = 0;
};
