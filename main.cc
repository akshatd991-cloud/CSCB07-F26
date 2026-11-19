#include <iostream>
#include <string>
#include "Piece.h"
#include "Board.h"
#include "Square.h"

using namespace std;

enum class Commands{
    Game,
    Move,
    Setup,
    Resign,
    Unknown
};

Commands strToCommand(const string& input){
    return Commands::Unknown;
}

int main(){
    string command;
    int state = 0; //0, in menu - 1, in game - 2, in setup 

    while (true){
        cin >> command;
        if (cin.fail() || command == "quit") break;

        switch (command){
            case "game":
            
                break;
        }
    }
}