#pragma once
#include "../StaticObject.h"
#include "../ActiveObject.h"

class Smoke : public StaticObject, public ActiveObject
{
public:
    Smoke(Coordinates position, Level* level);
    void Run() override;
    int GetDensity();

private:
    int density;
};