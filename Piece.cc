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

void Pawn::Scan(Board* gameBoard){
    if (legalMoves) delete[] legalMoves;
    legalMoves = new Square*[4];
    int currCoo = currentPos->getCoordinates();
    int toCheck[4] = {-1}; //holds square that need to be checked before being added to legalMoves (max 4 for a pawn)
    if (getSide() == 0){ //white
        if (currentPos->getPosY() == 1){ //check if position is on the 2nd rank (squares 8 to 15)
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
        }
    } else { //black, everything in reverse
        if (currentPos->getPosY() == 6){ //check if position is on the 7nd rank (squares 49 to 56)
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
        }
    }

    const int sideMult = (getSide() == 0) ? 1 : -1; //Here to reverse the numbers if on black side

    Piece* piece;
    int lastLegalMove = 0;
    for (int square : toCheck){
        if (square == -1){
            //No need to check
        } else {
            //TODO, checks presence and potential side of the piece on the destination
            piece = gameBoard->getBoard()[square]->getOccupant();
            if (piece != nullptr){
                if (piece->getSide() == getSide()){
                    //On the same team, cannot move nor take, not legal move
                } else {
                    if (currCoo - square == sideMult*7 || currCoo - square == sideMult*9){ //NE and NW, we can take
                        legalMoves[lastLegalMove] = piece->getPos();
                        lastLegalMove++;
                    }
                }
            } else {
                if (currCoo - square == sideMult*16) { //twice front, we check if there is a piece N
                    if (gameBoard->getBoard()[currCoo + sideMult*8]->getOccupant() == nullptr) {
                        legalMoves[lastLegalMove] = gameBoard->getBoard()[square];
                        lastLegalMove++;
                    }
                } else if (currCoo - square == sideMult*8){ //N
                    legalMoves[lastLegalMove] = gameBoard->getBoard()[square];
                    lastLegalMove++;
                }
            }
            //For pawn only, move and take are not the same, so check for absence of piece for move and presence for take
        }
    }
}

void Pawn::EnPassant(){

}

#pragma endregion

#pragma region KING

King::King(int side, Square* startPos) : Piece('k', 100, side, startPos) {}

void King::Scan(Board* gameBoard){
    if (legalMoves) delete[] legalMoves;
    legalMoves = new Square*[8];
    //We need to scan each square around him
    int currCoo = currentPos->getCoordinates();
    int toCheck[8] = {-1};
    toCheck[0] = (currentPos->getPosX() == 0 || currentPos->getPosY() == 7) ? -1 : currCoo + 7;//NW
    toCheck[1] = (currentPos->getPosY() == 7) ? -1 : currCoo + 8;//N
    toCheck[2] = (currentPos->getPosX() == 7 || currentPos->getPosY() == 7) ? -1 : currCoo + 9;//NE

    toCheck[3] = (currentPos->getPosX() == 0 || currentPos->getPosY() == 0) ? -1 : currCoo - 9;//SW
    toCheck[4] = (currentPos->getPosY() == 0) ? -1 : currCoo - 8;//S
    toCheck[5] = (currentPos->getPosX() == 7 || currentPos->getPosY() == 0) ? -1 : currCoo - 7;//SE

    toCheck[6] = (currentPos->getPosX() == 0) ? -1 : currCoo - 1;//W
    toCheck[7] = (currentPos->getPosX() == 7) ? -1 : currCoo + 1;//E

    Piece* piece;
    int lastLegalMove = 0;
    for (int square : toCheck){
        if (square == -1){
            //No need to check
        } else {
            //TODO, checks presence and potential side of the piece on the destination
            piece = gameBoard->getBoard()[square]->getOccupant();
            if (piece != nullptr){
                if (piece->getSide() == getSide()){
                    //On the same team, cannot move nor take, not legal move
                } else {
                    //TODO, check if the move creates a check for our team before accepting it
                    legalMoves[lastLegalMove] = gameBoard->getBoard()[square];
                    lastLegalMove++;
                }
            } else {
                //TODO, same as above
                legalMoves[lastLegalMove] = gameBoard->getBoard()[square];
                lastLegalMove++;
            }
        }
    }

}

#pragma endregion

#pragma region QUEEN

Queen::Queen(int side, Square* startPos) : Piece('q', 9, side, startPos) {}

void Queen::Scan(Board* gameBoard){

}

#pragma endregion

#pragma region ROOK

Rook::Rook(int side, Square* startPos) : Piece('r', 5, side, startPos) {}

void Rook::Scan(Board* gameBoard){

}

#pragma endregion


#pragma region KNIGHT

Knight::Knight(int side, Square* startPos) : Piece('n', 3, side, startPos) {}

void Knight::Scan(Board* gameBoard){
    if (legalMoves) delete[] legalMoves;
    legalMoves = new Square*[8];
    //We need to scan each square around him
    int currCoo = currentPos->getCoordinates();
    int toCheck[8] = {-1};
    toCheck[0] = (currentPos->getPosX() == 0 || currentPos->getPosY() >= 6) ? -1 : currCoo + 15;//NW
    toCheck[1] = (currentPos->getPosX() == 7 || currentPos->getPosY() >= 6) ? -1 : currCoo + 17;//NE

    toCheck[2] = (currentPos->getPosX() >= 6 || currentPos->getPosY() == 7) ? -1 : currCoo + 10;//EN
    toCheck[3] = (currentPos->getPosX() >= 6 || currentPos->getPosY() == 0) ? -1 : currCoo - 6;//ES

    toCheck[4] = (currentPos->getPosX() == 0 || currentPos->getPosY() >= 1) ? -1 : currCoo - 15;//SE
    toCheck[5] = (currentPos->getPosX() == 7 || currentPos->getPosY() >= 1) ? -1 : currCoo - 17;//SW

    toCheck[6] = (currentPos->getPosX() >= 1 || currentPos->getPosY() == 0) ? -1 : currCoo - 10;//WS
    toCheck[7] = (currentPos->getPosX() >= 1 || currentPos->getPosY() == 7) ? -1 : currCoo + 6;//WN

    Piece* piece;
    int lastLegalMove = 0;
    for (int square : toCheck){
        if (square == -1){
            //No need to check
        } else {
            //TODO, checks presence and potential side of the piece on the destination
            piece = gameBoard->getBoard()[square]->getOccupant();
            if (piece != nullptr){
                if (piece->getSide() == getSide()){
                    //On the same team, cannot move nor take, not legal move
                } else {
                    //TODO, check if the move creates a check for our team before accepting it
                    legalMoves[lastLegalMove] = gameBoard->getBoard()[square];
                    lastLegalMove++;
                }
            } else {
                //TODO, same as above
                legalMoves[lastLegalMove] = gameBoard->getBoard()[square];
                lastLegalMove++;
            }
        }
    }
}

#pragma endregion


#pragma region BISHOP

Bishop::Bishop(int side, Square* startPos) : Piece('b', 3, side, startPos) {}

void Bishop::Scan(Board* gameBoard){

}

#pragma endregion