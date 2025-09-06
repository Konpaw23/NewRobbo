#include "../include/helpers.h"

Direction GetOppositeDirection(Direction dir)
{
    switch(dir)
    {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
    }
}

Axis GetAxis(Direction dir)
{
    switch (dir)
    {
        case UP:
        case DOWN:
            return VERTICAL;
        case LEFT:
        case RIGHT:
            return HORIZONTAL;
    }
}