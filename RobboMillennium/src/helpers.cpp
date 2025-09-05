#include "../include/helpers.h"

Direction GetOppositeDirection(Direction dir)
{
    switch(dir)
    {
        case UP:
            return DOWN;
            break;
        case DOWN:
            return UP;
            break;
        case LEFT:
            return RIGHT;
            break;
        case RIGHT:
            return LEFT;
            break;
    }
}