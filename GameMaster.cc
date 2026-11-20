#include "GameMaster.h"
#include <iostream>

using namespace std;

GameMaster::GameMaster(): 
    gameBoard{new Board}, isPlaying{false}, turn{0}, player1{nullptr}, player2{nullptr}
{}

void GameMaster::drawBoard(){
    cout << gameBoard << endl;
}