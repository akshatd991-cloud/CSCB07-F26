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
        Piece(char name, int value, int side, Square * startPos);
        virtual Square* Scan() = 0;
        virtual void Move();
        Square* getPos() const;
        bool getIsChecked() const;
        char getName() const;
        int getSide() const;
};

class Bishop : public Piece {
public:
    Bishop(int side, Square* startPos);
    Square* Scan() override;
     
};

class King : public Piece {
public:
    King(int side, Square* startPos);
    Square* Scan() override;
    void Castle();
     
};

class Knight : public Piece {
public:
    Knight(int side, Square* startPos);
    Square* Scan() override;
     
};

class Pawn : public Piece {
public:
    Pawn(int side, Square* startPos);
    Square* Scan() override;
    void EnPassant();   
};

class Queen : public Piece {
public:
    Queen(int side, Square* startPos);
    Square* Scan() override;
     
};

class Rook : public Piece {
public:
    Rook(int side, Square* startPos);
    Square* Scan() override;
    void Castle();
     
};

#endif