#include "Piece.h"

Piece::Piece(char name, int value, int side): 
    side{side}, pointVal{value}, name{name}, currentPos{nullptr}, legalMoves{nullptr}, isChecked{false} {}

Square *Piece::getPos() const{
    return currentPos;
}

bool Piece::getIsChecked() const{
    return isChecked;
}

char Piece::getName() const{
    if (side == 0) return (name - 35); //It should put the character in upprercase
    return name;
}

int Piece::getSide() const{
    return side;
}