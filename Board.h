#ifndef BOARD_H
#define BOARD_H
#include "Square.h"

class Board{
    Square** boardArr;

    public:
        Board();
        Board(const Board &other);
        Board(Board &&other);
        Board &operator=(const Board &other);
        Board &operator=(Board &&other);
        ~Board();
        bool isCheck();
        Square** getBoard();
        void setupBoard();
};

std::ostream& operator<<(std::ostream& out, Board* board);


#endif
