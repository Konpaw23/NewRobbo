#pragma once
#include "../../../basicProjectHeaders.h"

class Level;

class GameObject
{
public:
    GameObject(GameObjectName objectName, Coordinates position, bool explosion_resistant, bool projectile_resistant, Level* level);
    GameObject();
    virtual ~GameObject();
    GameObjectName GetObjectName();
    Coordinates GetPosition();
    bool IsProjectileResistant();
    bool IsExplosionResistant();
    bool IsActive();
    void SetToDelete();
    virtual void Destroy();
    virtual void Destroy(GameObjectName source);

protected:
    Coordinates position;

    const bool explosion_resistant;
    const bool projectile_resistant;

    Level* level;

    bool isActive = true;

private:
    GameObjectName objectName;
};