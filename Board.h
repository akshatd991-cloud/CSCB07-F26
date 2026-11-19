#ifndef BOARD_H
#define BOARD_H
#include "Square.h"

class Board{
    Square** boardArr;

    public:
        Board();
        bool isCheck();
        Board getBoard();
        Board setBoard();
        void copyBoard();
};

std::ostream& operator<<(std::ostream& out, Board* board);


#endif
