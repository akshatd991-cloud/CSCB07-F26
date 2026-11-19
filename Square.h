#ifndef SQUARE_H
#define SQUARE_H
#include <string>
#include <iostream>
#include "Piece.h"

class Square{
    std::string coordinates;
    Piece* occupant;
    int posX;
    int posY;

    public:
        Square(int posX = 1, int posY = 1);
        // Square(const Square &other);
        // Square(Square &&other);

        // Square &operator=(const Square &other);
        // Square &operator=(Square &&other);

        // ~Square();

        Piece* getOccupant() const;
};

#endif