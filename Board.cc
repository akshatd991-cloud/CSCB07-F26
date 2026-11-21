#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include <utility>
#include <string>
#include <unordered_map>

Board::Board(): boardArr{new Square*[64]}
{
    for (int i = 0; i<8; ++i){
        for (int j=0; j<8; ++j){
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

void Board::setupBoard(){ //Setup a classic chess board
    const std::unordered_map<int, char> board = {
        {0, 'R'},
        {1, 'N'},
        {2, 'B'},
        {3, 'Q'},
        {4, 'K'},
        {5, 'B'},
        {6, 'N'},
        {7, 'R'},

        {63, 'R'},
        {62, 'N'},
        {61, 'B'},
        {60, 'K'},
        {59, 'Q'},
        {58, 'B'},
        {57, 'N'},
        {56, 'R'}
    };

    for (int i = 0; i<64; i++){
        if (board.contains(i)) {
            switch (board.at(i)){
                case 'R':
                    boardArr[i]->setOccupant(new Rook((i<32) ? 0 : 1, boardArr[i]));
                    break;
                case 'N':
                    boardArr[i]->setOccupant(new Knight((i<32) ? 0 : 1, boardArr[i]));
                    break;
                case 'B':
                    boardArr[i]->setOccupant(new Bishop((i<32) ? 0 : 1, boardArr[i]));
                    break;
                case 'Q':
                    boardArr[i]->setOccupant(new Queen((i<32) ? 0 : 1, boardArr[i]));
                    break;
                case 'K':
                    boardArr[i]->setOccupant(new King((i<32) ? 0 : 1, boardArr[i]));
                    break;
                default:
                    if (i > 7 && i < 15){
                        boardArr[i]->setOccupant(new Pawn(0, boardArr[i]));
                    } else if (i < 56 && i > 48){
                        boardArr[i]->setOccupant(new Pawn(1, boardArr[i]));
                    }
            }
            
        }
    }
}

std::ostream& operator<<(std::ostream& out, Board* board){
    Piece* current;
    for (int i = 8; i>0; --i){
        out << i << " ";
        for (int j=8; i>0; --j){
            current = board->getBoard()[8*i + j]->getOccupant();
            if (current == nullptr) {
                out << ((i+j)%2 == 1) ? " ": "-";
            } else {
                out << current->getName();
            }
        }
        out << std::endl;
    }
    out << " abcdefgh" << std::endl; 
}
