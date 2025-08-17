#pragma once
#include <vector>
#include "Mirror.h"

class MirrorGroup
{
public:
    MirrorGroup(std::vector<Mirror*>* mirrors);

    void TeleportToNext(Robbo* robbo, int mirrorId, Direction out);

private:
    std::vector<Mirror*> mirrors;
};