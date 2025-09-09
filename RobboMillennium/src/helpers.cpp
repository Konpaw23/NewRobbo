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

Direction GetDirectionToLeft(Direction dir)
{
    switch(dir)
    {
        case UP:
            return LEFT;
        case DOWN:
            return RIGHT;
        case LEFT:
            return DOWN;
        case RIGHT:
            return UP;
    }
}

Direction GetDirectionToRight(Direction dir)
{
    switch(dir)
    {
        case UP:
            return RIGHT;
        case DOWN:
            return LEFT;
        case LEFT:
            return UP;
        case RIGHT:
            return DOWN;
    }
}

Direction GetDirectionNextTo(Direction initial, Direction rotate)
{
    if(rotate == LEFT)
    {
        return GetDirectionToLeft(initial);
    }
    else if(rotate == RIGHT)
    {
        return GetDirectionToRight(initial);
    }
    else
    {
        return initial;
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