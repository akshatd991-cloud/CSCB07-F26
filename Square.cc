#include "Square.h"
#include "Piece.h"
#include <string>

Square::Square(int posX, int posY): posX{posX}, posY{posY}, occupant{nullptr} 
{
    char cooH = 96 + posX; //horizontal coordinates (97 being ASCII for 'a')
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