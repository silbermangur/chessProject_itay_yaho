#include "piece.h"
#include <iostream>

piece::piece(bool color) : _color(color), _hasMoved(false)
{                // Color - true = white, false = black
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
