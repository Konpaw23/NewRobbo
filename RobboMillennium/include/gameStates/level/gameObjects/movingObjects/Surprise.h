#pragma once
#include "../MovingObject.h"
#include <cstdlib>

//TODO delay after opening surprise
class Surprise : public MovingObject
{
public:
    Surprise(Coordinates position, Level* level);
    void Destroy() override;
    void Destroy(GameObjectName source) override;

private:
    void Open();
};