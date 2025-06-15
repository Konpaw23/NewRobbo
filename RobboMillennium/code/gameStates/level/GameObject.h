#pragma once
#include "../../basicProjectHeaders.h"

/*
 * TODO in moving objects make two type of collisions:
 * in_collision and round_collision
 * (both will be activated after object moves??
 */

class GameObject
{
public:
    GameObject(GameObjectName objectName, Coordinates position);
    virtual ~GameObject();
    GameObjectName GetObjectName();
    Coordinates GetPosition();

protected:
    Coordinates position;

private:
    GameObjectName objectName;
};