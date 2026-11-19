#include <iostream>
#include <string>
#include "Piece.h"
#include "Board.h"
#include "Square.h"

using namespace std;

//I found this technique online, adapt a string into an enum to use switch
//and get a cleaner code than chained if statements
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

        switch (strToCommand(command)){
            case Commands::Game:
                cout<< "Game starting" << endl;
                break;
            case Commands::Move:
                cout << "Move" << endl;
                break;
            case Commands::Setup:
                cout << "entering setup" << endl;
                break;
            case Commands::Resign:
                cout << "resigned the game" << endl;
                break;
            case Commands::Unknown:
                cout << "Wrong command, please enter again" << endl;
        }
    }
}