#include "../../../../../include/gameStates/level/gameObjects/activeObjects/RotatingCannon.h"

//TODO better constructor without redundancy??
RotatingCannon::RotatingCannon(Coordinates position, Direction initialRotation, Level* level) : Cannon(position, initialRotation, level),
                                                                                                GameObject(ROTATING_CANNON, position, false, true, level)
{
    ;
}

void RotatingCannon::Run()
{
    int random = rand() % 50;
    if(random == 0)
    {
        this->Rotate(LEFT);
    }
    else if(random == 1)
    {
        this->Rotate(RIGHT);
    }
    else
    {
        Cannon::Run();
    }
}