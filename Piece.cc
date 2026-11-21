#include "Piece.h"

#pragma region PIECE SUPERCLASS
Piece::Piece(char name, int value, int side, Square* startPos): 
    side{side}, pointVal{value}, name{name}, currentPos{startPos}, legalMoves{nullptr}, isChecked{false} {}

Square *Piece::getPos() const{
    return currentPos;
}

bool Piece::getIsChecked() const{
    return isChecked;
}

char Piece::getName() const{
    if (side == 0) return (name - 32); //It should put the character in upprercase
    return name;
}

int Piece::getSide() const{
    return side;
}

#pragma endregion

#pragma region PAWN

Pawn::Pawn(int side, Square* startPos) : Piece('p', 1, side, startPos) {}

Square* Pawn::Scan(){

}

void Pawn::EnPassant(){
    
}

#pragma endregion