#ifndef BOARD_H
#define BOARD_H
#include "Square.h"

class Board{
    Square** boardArr;

    public:
        bool isCheck();
        Board getBoard();
        Board setBoard();
        void copyBoard();
};

#endif
