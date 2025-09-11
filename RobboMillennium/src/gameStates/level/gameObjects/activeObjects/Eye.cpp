#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Eye.h"
#include "../../../../../include/gameStates/level/Level.h"

Eye::Eye(Coordinates position, Level* level) : GameObject(EYE, position, false, false, level)
{
    ;
}

void Eye::Run()
{
    int random = rand() % 100;

    if(random < 70)
    {
        this->MoveTowardsRobbo();
    }
    else if(random < 85)
    {
        this->MoveRandom();
    }

    KillingObject::SearchAndKill();
}

void Eye::MoveTowardsRobbo()
{
    if(level->IsPlayerAlive())
    {
        this->Move(this->position.GetDirectionTorwards(this->level->GetRobboPosition()));
    }
}

void Eye::MoveRandom()
{
    this->Move(GetRandomDirection());
}