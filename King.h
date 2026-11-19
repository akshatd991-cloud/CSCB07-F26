#ifndef KING_H
#define KING_H
#include "Piece.h"
#include <string>

class King : public Piece {
public:
    King(int side, Square* startPos);
    Square* Scan() override;
    void Castle();
     
};

#endif