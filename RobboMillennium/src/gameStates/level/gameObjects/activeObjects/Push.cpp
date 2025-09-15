#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Push.h"
#include "../../../../../include/gameStates/level/Level.h"

Push::Push(Coordinates position, Level* level) : GameObject(PUSH, position, false, true, level), Bullet(position, NULL_DIR, level)
{
    ;
}

void Push::Run()
{
    if(this->rotation != NULL_DIR && !this->Move(rotation))
    {
        GameObject* other = this->level->GetObjectFromPosition(this->GetPosition().GetNext(rotation));
        if(other != nullptr && !other->IsProjectileResistant())
        {
            other->Destroy();
        }
        this->rotation = NULL_DIR;
    }
}

void Push::PushPush(Direction direction)
{
    if(this->level->GetObjectNameFromPosition(this->position.GetNext(direction)) == NULL_OBJECT)
    {
        this->rotation = direction;
    }
}