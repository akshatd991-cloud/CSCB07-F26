#include "GameMaster.h"
#include <iostream>
#include "HumanPlayer.h"
#include "ComPlayer.h"

using namespace std;

GameMaster::GameMaster(): 
    gameBoard{new Board}, isPlaying{false}, turn{0}, player1{nullptr}, player2{nullptr}
{}

void GameMaster::drawBoard(){
    cout << gameBoard << endl;
}

bool GameMaster::checkMate(){
    return false;
}

void GameMaster::startGame(std::string p1, std::string p2){
    if (p1 == "human"){
        player1 = new HumanPlayer;
    } else { //if the player is not "human" then it is "computer[x]", where x is a single digit for the difficulty
        int botDiff = p1[9] - '0'; //converts the digit char into an int
        player1 = new ComputerPlayer(botDiff);
    }

    if (p2 == "human"){
        player2 = new HumanPlayer;
    } else {
        int botDiff = p2[9] - '0';
        player2 = new ComputerPlayer(botDiff);
    }

    isPlaying = true;
}

void GameMaster::endGame(){
    isPlaying = false;
    turn = 0;

    delete player1;
    player1 = nullptr;
    delete player2;
    player2 =nullptr;

    delete gameBoard;
    gameBoard = new Board;
}