#include "../../../../../include/gameStates/level/gameObjects/staticObjects/MirrorGroup.h"
#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"

MirrorGroup::MirrorGroup()
{
    ;
}

void MirrorGroup::TeleportToNext(Robbo* robbo, int mirrorId, Direction out)
{
    int mirrorsAmount = this->mirrors.size();

    //TODO Robbo may not exit mirror when all ways blocked!!!
    for(int i = 1; i <= mirrorsAmount; i++)
    {
        if(mirrors[(mirrorId + i) % mirrorsAmount]->Exit(robbo, out))
        {
            break;
        }
    }
}

void MirrorGroup::AddMirror(Mirror *newMirror)
{
    this->mirrors.push_back(newMirror);
}

int MirrorGroup::GetGroupSize()
{
    return this->mirrors.size();
}

void MirrorGroup::RemoveMirror(int id)
{
    this->mirrors.erase(mirrors.begin() + id);
}