#include "../../../../../include/gameStates/level/gameObjects/movingObjects/Bomb.h"
#include "../../../../../include/gameStates/level/Level.h"

Bomb::Bomb(Coordinates position, Level* level) : GameObject(BOMB, position, false, false, level), MovingObject(true)
{
    ;
}

void Bomb::Destroy()
{
    SetToExplode();
}

void Bomb::Run()
{
    if(explodeTurn == this->level->GetTurnNumber())
    {
        Explode();
    }
}

void Bomb::SetToExplode()
{
    this->explodeTurn = this->level->GetTurnNumber() + 1;
}

void Bomb::Explode()
{
    std::vector<Coordinates> explosionFields = this->level->GetFieldsAround(this->position);
    for(int i = 0; i < explosionFields.size(); i++)
    {
        GameObject* other = this->level->GetObjectFromPosition(explosionFields[i]);
        if(other == nullptr)
        {
            level->SpawnSmoke(explosionFields[i]);
        }
        else if(!other->IsExplosionResistant())
        {
            other->Destroy();
        }
    }
    explosionFields.clear();
    GameObject::Destroy();
}