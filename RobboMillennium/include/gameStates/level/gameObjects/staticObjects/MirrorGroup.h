#pragma once
#include <vector>
#include "Mirror.h"
#include "algorithm"

class MirrorGroup
{
public:
    MirrorGroup();

    void TeleportToNext(Robbo* robbo, Mirror* mirror, Direction out);
    void AddMirror(Mirror* newMirror);
    int GetGroupSize();
    void RemoveMirror(Mirror* mirror);

private:
    std::vector<Mirror*> mirrors = {};
};