#pragma once
#include <random>
#include "enums.h"

class Coordinates {
public:
    Coordinates(int x, int y);
    Coordinates(Direction dir);

    bool operator==(Coordinates other);

    Coordinates Sum(Coordinates second);
    Coordinates GetNext(Direction dir);
    Direction GetDirectionTorwards(Coordinates target);

    int x;
    int y;
};