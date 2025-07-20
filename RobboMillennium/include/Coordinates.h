#pragma once
#include "enums.h"

class Coordinates {
public:
    Coordinates(int x, int y);
    Coordinates(Direction dir);

    Coordinates Sum(Coordinates second);
    Coordinates GetNext(Direction dir);

    int x;
    int y;
};