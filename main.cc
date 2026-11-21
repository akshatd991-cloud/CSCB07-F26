#include <iostream>
#include <string>
#include <unordered_map>
#include "Piece.h"
#include "Board.h"
#include "Square.h"
#include "GameMaster.h"

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
    const unordered_map<string, Commands> conversion = {
        {"game", Commands::Game},
        {"move", Commands::Move},
        {"setup", Commands::Setup},
        {"resign", Commands::Resign}
    };

    return (conversion.contains(input)) ? conversion.at(input) : Commands::Unknown;
}

int main(){
    GameMaster* gm = new GameMaster;
    string command;
    string p1, p2;
    int state = 0; //0, in menu - 1, in game - 2, in setup 

    while (true){
        cin >> command;
        if (cin.fail() || command == "quit") break;

        switch (strToCommand(command)){
            case Commands::Game:
                cin >> p1;
                cin >> p2;
                gm->startGame(p1, p2);
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