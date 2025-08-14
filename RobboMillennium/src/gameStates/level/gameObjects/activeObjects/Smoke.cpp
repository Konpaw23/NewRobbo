#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Smoke.h"
#include "../../../../../include/gameStates/level/Level.h"

Smoke::Smoke(Coordinates position, Level *level) : GameObject(SMOKE, position, false, true, level), ActiveObject(SMOKE, position, false, true, level),
                                                   StaticObject(SMOKE, position, false, true, level), density(6)
{
    ;
}

void Smoke::Run()
{
    if(density >= 0)
    {
        this->density--;
    }
    else
    {
        this->level->RemoveObject(this);
    }
}

int Smoke::GetDensity()
{
    return this->density;
}