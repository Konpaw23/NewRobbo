#pragma once
#include <vector>
#include "Mirror.h"

class MirrorGroup
{
public:
    MirrorGroup();

    void TeleportToNext(Robbo* robbo, int mirrorId, Direction out);
    void AddMirror(Mirror* newMirror);
    int GetGroupSize();
    void RemoveMirror(int id);

private:
    std::vector<Mirror*> mirrors = {};
};