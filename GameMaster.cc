#include "GameMaster.h"
#include <iostream>
#include <typeinfo>
#include <string>
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
    return false; //Temporary
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
    gameBoard->setupBoard();
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

void GameMaster::nextMove(){
    string startSquare, endSquare;
    string letters = "abcdefgh";
    string numbers = "12345678";
    if (turn%2 == 0){
        //Player 1 turn
        if (typeid(*player1) == typeid(HumanPlayer)){
            //Player 1 is human
            cin >> startSquare;
            cin >> endSquare;

            if (startSquare.length() != 2 || endSquare.length() != 2){
                //Wrong inputs
            } else if (letters.find(startSquare[0]) == string::npos || letters.find(startSquare[0]) == string::npos){
                //Wrong format for letters
            } else if (numbers.find(startSquare[1]) == string::npos || numbers.find(startSquare[1]) == string::npos){
                //Wrong format for number
            } else {
                //The inputs are correct, process the move

                //TODO, convert the input from "a1" to "0"

                //TODO, check if there is a piece on the start square

                //TODO, check the side of the piece

                //TODO, check if the destination is a valid move (using Scan and legalMoves)

                //TODO, execute the move if everything passes
            }
        } else {
            //Player 1 is computer

            //TODO, call the computer scan, then execute the move (the move should always be valid due to the scan)
        }
    }
    else{
        //Player 2 turn
        if (typeid(*player2) == typeid(HumanPlayer)){
            //Player 2 is human

            //TODO, just copy from player 1, adjust for sides
        } else {
            //Player 2 is computer

            //TODO, same as player 1 computer
        }
    }
}