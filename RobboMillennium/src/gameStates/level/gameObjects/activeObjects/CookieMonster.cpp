#include "../../../../../include/gameStates/level/gameObjects/activeObjects/CookieMonster.h"
#include "../../../../../include/gameStates/level/Level.h"

CookieMonster::CookieMonster(Coordinates position, Direction initialRotation, Level *level) : PurpleSeahorse(position, initialRotation, level),
    GameObject(COOKIE_MONSTER, position, false, false, level)
{
    ;
}

void CookieMonster::Run()
{
    int random = rand() % 100;
    if(random < 5)
    {
        this->Shoot();
    }
    else
    {
        PurpleSeahorse::Run();
    }
}

void CookieMonster::Shoot()
{
    Coordinates bulletField = this->position.GetNext(DOWN);

    GameObject* other = this->level->GetObjectFromPosition(bulletField);

    if(other == nullptr)
    {
        this->level->SpawnBullet(bulletField, DOWN);
    }
    else if(!other->IsProjectileResistant())
    {
        other->Destroy();
    }
}