#include "Piece.h"
#include "Square.h"
#include "Board.h"

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

Square** Piece::getLegalMoves() const{
    return legalMoves;
}

int Piece::getValue() const{
    return pointVal;
}

#pragma endregion

#pragma region PAWN

Pawn::Pawn(int side, Square* startPos) : Piece('p', 1, side, startPos) {}

void Pawn::Scan(){
    int currCoo = currentPos->getCoordinates();
    int toCheck[4]; //holds square that need to be checked before being added to legalMoves (max 4 for a pawn)
    if (getSide() == 0){ //white
        if (currCoo > 7 && currCoo< 16){ //check if position is on the 2nd rank (squares 8 to 15)
            //If second rank, we add 2 on front, NE and NW to legalMoves
            toCheck[0] = (currCoo == 8) ? -1 : currCoo + 7; //case 8 is A2, so no NE for this
            toCheck[1] = currCoo + 8; //N
            toCheck[2] = (currCoo == 15) ?-1 : currCoo + 9; //case 15 is H2, so no NW for this
            toCheck[3] = currCoo + 16;//NN (twice front)
        } else {
            //Else, we check NE, N and NW, same conditions as before, for A and H ranks
            //We also assume that it can't be on the 8th rank, since it would have been promoted
            toCheck[0] = (currCoo%8 == 0) ? -1 : currCoo+7;
            toCheck[1] = currCoo + 8;
            toCheck[2] = (currCoo%8 == 7) ? -1 : currCoo+9;
            toCheck[3] = -1; //No need to check twice in front
        }
    } else { //black, everything in reverse
        if (currCoo > 48 && currCoo< 57){ //check if position is on the 7nd rank (squares 49 to 56)
            toCheck[0] = (currCoo == 49) ? -1 : currCoo - 7; //case 56 is A7, so no SE for this
            toCheck[1] = currCoo - 8; //S
            toCheck[2] = (currCoo == 56) ? -1 : currCoo - 9; //case 15 is H2, so no SW for this
            toCheck[3] = currCoo - 16;//SS (twice back)
        } else {
            //Else, we check SE, S and SW, same conditions as before, for A and H ranks
            //We also assume that it can't be on the 1st rank, since it would have been promoted
            toCheck[0] = (currCoo%8 == 0) ? -1 : currCoo-7;
            toCheck[1] = currCoo - 8;
            toCheck[2] = (currCoo%8 == 7) ? -1 : currCoo-9;
            toCheck[3] = -1; //No need to check twice in frobacknt
        }
    }

    for (int square : toCheck){
        if (square == -1){
            //No need to check
            
        } else {
            //TODO, checks presence and potential side of the piece on the destination

            //For pawn only, move and take are not the same, so check for absence of piece for move and presence for take
        }
    }
}

void Pawn::EnPassant(){

}

#pragma endregion

#pragma region KING

King::King(int side, Square* startPos) : Piece('k', 100, side, startPos) {}

void King::Scan(){

}

#pragma endregion

#pragma region QUEEN

Queen::Queen(int side, Square* startPos) : Piece('q', 9, side, startPos) {}

void Queen::Scan(){

}

#pragma endregion

#pragma region ROOK

Rook::Rook(int side, Square* startPos) : Piece('r', 5, side, startPos) {}

void Rook::Scan(){

}

#pragma endregion


#pragma region KNIGTH

Knight::Knight(int side, Square* startPos) : Piece('n', 3, side, startPos) {}

void Knight::Scan(){

}

#pragma endregion


#pragma region BISHOP

Bishop::Bishop(int side, Square* startPos) : Piece('b', 3, side, startPos) {}

void Bishop::Scan(){

}

#pragma endregion