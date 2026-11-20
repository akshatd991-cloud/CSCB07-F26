#ifndef PIECE_H
#define PIECE_H

class Square;

class Piece{
    int side; //0 white, 1 black
    Square* currentPos;
    Square** legalMoves;
    int pointVal;
    bool isChecked;
    char name; //CONVENTION : always put the name is lowercase. Uppercase is handled but the getName function

    public:
        Piece(char name, int value, int side);
        virtual Square* Scan() = 0;
        virtual void Move();
        Square* getPos() const;
        bool getIsChecked() const;
        char getName() const;
};


#endif