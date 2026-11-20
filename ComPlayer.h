#ifndef COMPLAYER_H
#define COMPLAYER_H
#include "Player.h"

class ComputerPlayer: public Player{
    int difficulty;

    public:
        ComputerPlayer(int difficulty);
};

#endif