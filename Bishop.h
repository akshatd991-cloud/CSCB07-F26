#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <string>

class Bishop : public Piece {
public:
    Bishop(int side, Square* startPos);
    Square* Scan() override;
     
};

#endif