#include "../../../../include/gameStates/level/gameObjects/KillingObject.h"
#include "../../../../include/gameStates/level/Level.h"

KillingObject::KillingObject()
{
    ;
}

void KillingObject::SearchAndKill()
{
    std::vector<Coordinates> fields = this->level->GetFieldsNextTo(this->position);
    for(int i = 0; i < fields.size(); i++)
    {
        if(this->level->GetObjectNameFromPosition(fields[i]) == ROBBO)
        {
            this->level->GetObjectFromPosition(fields[i])->Destroy();
        }
    }
}