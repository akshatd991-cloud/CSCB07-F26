#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <string>

class Knight : public Piece {
public:
    Knight(int side, Square* startPos);
    Square* Scan() override;
     
};

#endif