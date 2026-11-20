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
        explicit Square(int posX = 1, int posY = 1); //Explicit to avoid having a tuple casted into a square
        // Square(const Square &other);
        // Square(Square &&other);

        // Square &operator=(const Square &other);
        // Square &operator=(Square &&other);

        // ~Square();

        Piece* getOccupant() const;
        void setOccupant(Piece* piece);
};

#endif