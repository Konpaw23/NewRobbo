#pragma once
#include "../ActiveObject.h"
#include "../StaticObject.h"
#include "../RotatingObject.h"

class Cannon : public ActiveObject, public StaticObject, public RotatingObject
{
public:
    Cannon(Coordinates position, Direction rotation, Level* level);
    void Run() override;

protected:
    virtual void Shoot();

private:
    virtual void PlaceProjectile(Coordinates position);
};