#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <string>

class Queen : public Piece {
public:
    Queen(int side, Square* startPos);
    Square* Scan() override;
     
};

#endif