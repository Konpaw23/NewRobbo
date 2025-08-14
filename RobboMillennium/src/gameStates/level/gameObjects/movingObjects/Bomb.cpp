#include "../../../../../include/gameStates/level/gameObjects/movingObjects/Bomb.h"
#include "../../../../../include/gameStates/level/Level.h"

Bomb::Bomb(Coordinates position, Level* level) : GameObject(BOMB, position, false, false, level),
    MovingObject(BOMB, position, false, false, level), ActiveObject(BOMB, position, false, false, level)
{
    ;
}

void Bomb::Destroy()
{
    SetToExplode();
}

void Bomb::Run()
{
    if(explode)
    {
        Explode();
    }
}

void Bomb::SetToExplode()
{
    this->explode = true;
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