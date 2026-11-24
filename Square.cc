#include "Square.h"
#include "Piece.h"
#include <string>

Square::Square(int posX, int posY): posX{posX}, posY{posY}, occupant{nullptr} 
{
    char cooH = 97 + posX; //horizontal coordinates (97 being ASCII for 'a', posX 0)
    coordinates += cooH;
    coordinates += std::to_string(posY);
}

Piece *Square::getOccupant() const{
    return occupant;
}

void Square::setOccupant(Piece* piece){
    if (occupant == nullptr){
        occupant = piece;
    } else {
        //Check for take move, or reject and do nothing
    }
}

int Square::getCoordinates() const{
    return (8*posY + posX);
}

int Square::getPosX() const{
    return posX;
}

int Square::getPosY() const{
    return posY;
}