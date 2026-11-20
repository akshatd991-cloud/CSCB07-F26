#ifndef GAMEMASTER_H
#define GAMEMASTER_H
#include <iostream>
#include "Board.h"
#include "Player.h"

class GameMaster{
    Board *gameBoard;
    bool isPlaying;
    int turn;
    Player *player1, *player2;

    public:
        GameMaster();
        void drawBoard();
        bool checkMate();
        void takeInput(std::string input);
};

#endif