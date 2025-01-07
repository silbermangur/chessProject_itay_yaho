#include "king.h"

king::king(bool color) : queen(color)
{
}

int* king::move(int* position)
{
    if (abs(position[1] - position[3]) <= 1 && abs(position[0] - position[2]) <= 1)
    {
        int* path = this->queen::move(position);
        return path;
    }
    else
    {
        cout << "Error!" << endl;
    }
    return NULL;
    
}
