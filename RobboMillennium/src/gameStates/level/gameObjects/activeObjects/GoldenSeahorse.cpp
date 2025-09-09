#include "../../../../../include/gameStates/level/gameObjects/activeObjects/GoldenSeahorse.h"

GoldenSeahorse::GoldenSeahorse(Coordinates position, Direction movementSide, Direction initialDirection, Level* level) :
        GameObject(GOLDEN_SEAHORSE, position, false, false, level), movementSide(movementSide), RotatingObject(initialDirection)
{
    ;
}

void GoldenSeahorse::Run()
{
    this->SearchAndKill();
}