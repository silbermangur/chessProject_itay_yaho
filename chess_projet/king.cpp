#include "king.h"

king::king(bool color) : queen(color, true)
{
}

void king::move(int* position, int* path)
{
    if (abs(position[1] - position[3]) <= 1 && abs(position[0] - position[2]) <= 1)
    {
        this->queen::move(position, path);
    }
    else
    {
        throw 6;
    }    
}
