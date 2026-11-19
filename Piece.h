#ifndef PIECE_H
#define PIECE_H
#include <string>

class Square;

class Piece{
    int side;
    Square* currentPos;
    Square** legalMoves;
    int pointVal;
    bool isChecked;
    std::string name;

    public:
        Piece();
        virtual *Square Scan() = 0;
        virtual void Move();
        Square* getPos() const;
};


#endif