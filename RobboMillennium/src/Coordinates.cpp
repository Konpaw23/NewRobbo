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
        y = -1;
    }
    else if(dir == DOWN)
    {
        y = 1;
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

Direction Coordinates::GetDirectionTorwards(Coordinates target)
{
    int xOffset = target.x - this->x;
    int yOffset = target.y - this->y;
    bool onePossible = false;
    Direction possibleDirections[2] = {};
    if(yOffset > 0)
        possibleDirections[0] = DOWN;
    else if(yOffset < 0)
        possibleDirections[0] = UP;
    else
        onePossible = true;

    if(xOffset == 0)
    {
        if(onePossible)
            return NULL_DIR;
        else
            return possibleDirections[0];
    }
    else if(xOffset > 0)
        possibleDirections[1] = RIGHT;
    else
        possibleDirections[1] = LEFT;

    if(onePossible)
       return possibleDirections[1];

    int random = rand() % 2;
    if(random == 0)
        return possibleDirections[0];
    else
        return possibleDirections[1];
}