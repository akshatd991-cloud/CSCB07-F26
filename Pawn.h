#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <string>

class Pawn : public Piece {
public:
    Pawn(int side, Square* startPos);
    Square* Scan() override;
    void Move() override;   
};

#endif