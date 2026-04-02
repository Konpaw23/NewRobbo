#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../ActiveObject.h"
#include "../MovingObject.h"

class Robbo : public ActiveObject, public MovingObject
{
public:
    Robbo(Coordinates position, class Level* level);
    void SetAction(RobboAction action);

    bool Move(Direction dir) override;
    bool Teleport(Coordinates position);
    void GiveScrew();
    void GiveKey();
    int GetKeysNumber();
    int GetAmmoNumber();
    bool HasKey();
    void UseKey();
    void AddAmmo();
    void Shot(Direction dir);

    void DisableMoving();
    void EnableMoving();

    void Run() override;
    void Destroy() override;
private:
    bool canMove = true;
    int keys;
    int ammo;
    int shootDelay;
    RobboAction action;
};