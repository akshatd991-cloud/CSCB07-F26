#include "Board.h"
#include "Piece.h"

Board::Board(): boardArr{new Square*[64]} 
{
    for (int i = 0; i<8; ++i){
        for (int j=0; i<8; ++j){
            boardArr[8*i + j] = new Square(i, j);
        }
    }
}

bool Board::isCheck(){
    for (int i = 0; i<64; ++i){
        if (boardArr[i]->getOccupant()->getIsChecked()) return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream& out, Board* board){

}