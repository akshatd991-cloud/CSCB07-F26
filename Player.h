#ifndef PLAYER_H
#define PLAYER_H
#include "Piece.h"

class Player{
    Piece *pieces;
    bool isChecked;

    public:
        Player();
        void scanForCheck();
        void deletePiece(Piece& piece);
        bool getIsChecked() const;
};

#endif
