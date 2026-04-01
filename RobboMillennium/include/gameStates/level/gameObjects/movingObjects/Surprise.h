#pragma once
#include "../MovingObject.h"
#include "../ActiveObject.h"
#include <cstdlib>

class Surprise : public MovingObject, public ActiveObject
{
public:
    Surprise(Coordinates position, Level* level);
    void Destroy() override;
    void Destroy(GameObjectName source) override;

    bool IsOpening();

    void Run() override;

private:
    int openDelay = 5;
    bool isOpening = false;

    void SetToOpen();
    void Open();
};