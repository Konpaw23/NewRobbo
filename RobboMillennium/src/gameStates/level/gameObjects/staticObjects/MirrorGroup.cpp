#include "../../../../../include/gameStates/level/gameObjects/staticObjects/MirrorGroup.h"
#include "../../../../../include/gameStates/level/gameObjects/activeObjects/Robbo.h"

MirrorGroup::MirrorGroup()
{
    ;
}

void MirrorGroup::TeleportToNext(Robbo* robbo, Mirror* mirror, Direction out)
{
    int mirrorsAmount = this->mirrors.size();

    auto iterator = std::find(mirrors.begin(), mirrors.end(), mirror);
    int currentMirrorIndex = std::distance(mirrors.begin(), iterator);

    //TODO Robbo may not exit mirror when all ways blocked!!!
    for(int i = 1; i <= mirrorsAmount; i++)
    {
        if(mirrors[(currentMirrorIndex + i) % mirrorsAmount]->Exit(robbo, out))
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

void MirrorGroup::RemoveMirror(Mirror* mirror)
{
    this->mirrors.erase(std::remove(mirrors.begin(), mirrors.end(), mirror), mirrors.end());
}