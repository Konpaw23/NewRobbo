#pragma once
#include "../../basicProjectHeaders.h"

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