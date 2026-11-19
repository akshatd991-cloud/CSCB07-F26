#ifndef ROOK_H
#define ROOK_H
#include "Piece.h"
#include <string>

class ROOK : public Piece {
public:
    ROOK(int side, Square* startPos);
    Square* Scan() override;
    void Castle();
     
};

#endif