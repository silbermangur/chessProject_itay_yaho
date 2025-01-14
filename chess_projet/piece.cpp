#include "piece.h"
#include <iostream>

piece::piece(bool color, string type) : _color(color), _hasMoved(false), _type(type)
{                // Color -> true = white, false = black
}

string piece::getType()
{
    return this->_type;
}

bool piece::getColor()
{
    return this->_color;
}

bool piece::getHasMoved()
{
    return _hasMoved;
}

void piece::setHasMoved()
{
    this->_hasMoved = true;
}
