#ifndef SQUARE_H
#define SQUARE_H
#include <string>
#include "Piece.h"

class Square{
    std::string coordinates;
    Piece* occupant;
    int posX;
    int posY;

    
};

#endif