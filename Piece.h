#ifndef PIECE_H
#define PIECE_H
#include "Board.h"

class Square;

class Piece{
    int side; //0 white, 1 black
    int pointVal;
    bool isChecked;
    char name; //CONVENTION : always put the name is lowercase. Uppercase is handled but the getName function

    protected:
        Square* currentPos;
        Square** legalMoves;
    
    public:
        Piece(char name, int value, int side, Square * startPos);
        virtual void Scan(Board* gameBoard) = 0;
        virtual void Move();
        Square* getPos() const;
        bool getIsChecked() const;
        char getName() const;
        int getSide() const;
        Square** getLegalMoves() const;
        int getValue() const;
};

class Bishop : public Piece {
public:
    Bishop(int side, Square* startPos);
    void Scan(Board* gameBoard) override;
     
};

class King : public Piece {
public:
    King(int side, Square* startPos);
    void Scan(Board* gameBoard) override;
    void Castle();
     
};

class Knight : public Piece {
public:
    Knight(int side, Square* startPos);
    void Scan(Board* gameBoard) override;
     
};

class Pawn : public Piece {
public:
    Pawn(int side, Square* startPos);
    void Scan(Board* gameBoard) override;
    void EnPassant();   
};

class Queen : public Piece {
public:
    Queen(int side, Square* startPos);
    void Scan(Board* gameBoard) override;
     
};

class Rook : public Piece {
public:
    Rook(int side, Square* startPos);
    void Scan(Board* gameBoard) override;
    void Castle();
     
};

#endif