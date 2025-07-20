#pragma once
#include "../../../../basicProjectHeaders.h"
#include "../../LevelHeaders.h"

//TODO now robbo only overwrites fields in level class when taking screws!
//TODO screws objects should be deleted (func in Collectible class) after being taken

class Screw : public Collectible
{
public:
    Screw(Coordinates position, Level* level);
};