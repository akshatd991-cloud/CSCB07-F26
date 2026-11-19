#include "Board.h"
#include "Piece.h"
#include <utility>

Board::Board(): boardArr{new Square*[64]} 
{
    for (int i = 0; i<8; ++i){
        for (int j=0; i<8; ++j){
            boardArr[8*i + j] = new Square(i, j);
        }
    }
}

Board::Board(const Board &other){
    for (int i = 0; i<64; ++i){
        boardArr[i] = new Square(*other.boardArr[i]);
    }
}

Board::Board(Board &&other): boardArr{other.boardArr} {}

Board &Board::operator=(const Board &other){
    if (&other == this) return *this;

    Square **newBoard = nullptr;
    for (int i = 0; i<64; ++i){
        newBoard[i] = new Square(*other.boardArr[i]);
    }

    for (int i = 0; i<64; ++i){
        delete boardArr[i];
    }
    delete[] boardArr;

    boardArr = newBoard;

    return *this;
}

Board &Board::operator=(Board &&other){
    std::swap(boardArr, other.boardArr);

    return *this;
}

Board::~Board(){
    for (int i = 0; i<64; ++i){
        delete boardArr[i];
    }
    delete[] boardArr;
}

bool Board::isCheck(){
    for (int i = 0; i<64; ++i){
        if (boardArr[i]->getOccupant()->getIsChecked()) return true;
    }

    return false;
}

Square** Board::getBoard(){
    return boardArr;
}

std::ostream& operator<<(std::ostream& out, Board* board){
    for (int i = 0; i<8; ++i){
        out << i << " ";
        for (int j=0; i<8; ++j){
            out << board->getBoard()[8*i + j]->getOccupant()->getName();
        }
        out << std::endl;
    }
    out << " abcdefgh" << std::endl; 
}