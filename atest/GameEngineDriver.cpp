#include "GameEngine.h"
#include <iostream>
using namespace std;

//Free function to test the implementation of the game engine with states, commands, and transition.
void testGameStates() {
    GameEngine gameEngine;
    cout << endl;
    cout << "Game Started" << endl;
    cout << endl;
    gameEngine.setState(GameState::Start);
    cout << gameEngine << endl;
    
    bool loop = true;

    while (loop) {
        string command = "";
        cout << gameEngine.listOfCommands() << endl;
        cout << "Enter a command: ";
        cin >> command;
        cout << endl;

        if (command == "exit"){
            loop = false;
            break;
        }
        if (gameEngine.validateCommandTransition(command)) {
            if (command == "loadmap") {
                gameEngine.setState(GameState::MapLoaded);
                gameEngine.startupPhase();

            }
            else if (command == "validatemap") {
                gameEngine.setState(GameState::MapValidated);
                gameEngine.startupPhase();
            }
            else if (command == "addplayer") {
                gameEngine.setState(GameState::PlayersAdded);
                gameEngine.startupPhase();
            }
            else if (command == "assigncountries") {
                gameEngine.setState(GameState::AssignReinforcement);
                gameEngine.reinforcementPhase();
            }
            else if (command == "issueorder") {
                gameEngine.setState(GameState::IssueOrder);
                gameEngine.ordersIssuingPhase(); 
            }
            else if (command == "endissueorders") {
                gameEngine.setState(GameState::ExecuteOrders);
                gameEngine.ordersExecutionPhase(); 
            }
            else if (command == "execorder") {
                gameEngine.setState(GameState::ExecuteOrders);
                gameEngine.ordersExecutionPhase(); 
            }
            else if (command == "endexecorders") {
                gameEngine.setState(GameState::AssignReinforcement);
                gameEngine.reinforcementPhase(); 
            }
            else if (command == "win") {
                gameEngine.setState(GameState::Win);
                gameEngine.endPhase(); 
            }
            else if (command == "play") {
                gameEngine.setState(GameState::Start);
                gameEngine.startupPhase();
            }
            else if (command == "end") {
                cout << "Game ended. Thank you for playing!\n";
                loop = false;
                break;
            }
            else {
                cout << endl;
                cout << "Invalid command transition. Please retry again.\n";
            }
        } else {
            cout << endl;
            cout << "Invalid command transition. Please retry again.\n";
        }
        cout << gameEngine << endl;
        cout << endl;
    }
}
