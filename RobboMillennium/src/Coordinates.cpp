#include "../include/Coordinates.h"

Coordinates::Coordinates(int x, int y) : x(x), y(y)
{
    ;
}

Coordinates::Coordinates(Direction dir)
{
    x = 0;
    y = 0;
    if(dir == LEFT)
    {
        x = -1;
    }
    else if(dir == RIGHT)
    {
        x = 1;
    }
    else if(dir == UP)
    {
        y = 1;
    }
    else if(dir == DOWN)
    {
        y = -1;
    }
}

Coordinates Coordinates::Sum(Coordinates second)
{
    return {x + second.x, y + second.y};
}

Coordinates Coordinates::GetNext(Direction dir)
{
    return Sum(Coordinates(dir));
}