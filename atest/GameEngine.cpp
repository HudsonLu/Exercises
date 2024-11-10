#include "GameEngine.h"
#include <iostream>
using namespace std;

GameEngine::GameEngine() {
    state = new GameState(GameState::Start);
}
//Destructor
GameEngine::~GameEngine() {
    delete state;
}
//Accessor
GameState* GameEngine::getState() const{
    return state;
}
//Mutator
void GameEngine::setState(GameState newState) {
    *state = newState;
}
//Assignment Operator
GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this == &other) {
        return *this;
    }
    delete state;
    state = new GameState(*other.state);
    return *this;
}
// Stream insertion operator for GameState
std::ostream& operator<<(std::ostream& out, const GameState& state) {
    switch (state) {
        case GameState::Start:
            out << "Start";
            break;
        case GameState::MapLoaded:
            out << "MapLoaded";
            break;
        case GameState::MapValidated:
            out << "MapValidated";
            break;
        case GameState::PlayersAdded:
            out << "PlayersAdded";
            break;
        case GameState::AssignReinforcement:
            out << "AssignReinforcement";
            break;
        case GameState::IssueOrder:
            out << "IssueOrder";
            break;
        case GameState::ExecuteOrders:
            out << "ExecuteOrders";
            break;
        case GameState::Win:
            out << "Win";
            break;
        default:
            out << "Unknown State";
            break;
    }
    return out;
}
//Stream insertion operator for GameEngine
std::ostream& operator<<(std::ostream& out, const GameEngine& game) {
    if (game.getState() != nullptr) {
        out << "GameEngine Current State: " << *game.getState();  
    } else {
        out << "GameEngine has no valid state.";
    }
    return out;
}

//Returns a string of a list commands
string GameEngine::listOfCommands() {
    return "Available commands:\n"
           "1. loadmap\n"
           "2. validatemap\n"
           "3. addplayer\n"
           "4. assigncountries\n"
           "5. issueorder\n"
           "6. endissueorders\n"
           "7. execorder\n"
           "8. endexecorders\n"
           "9. win\n"
           "10. play\n"
           "11. end\n"
           "12. exit";
}

//Return a bool value. validateCommandTransition(std::string command) method validates if the command that user inputs is correct or incorrect.
bool GameEngine::validateCommandTransition(std::string command) {
    if (command == "loadmap" && *state == GameState::Start  || command == "loadmap" && *state == GameState::MapLoaded) {
        return true;
    }
    else if (command == "validatemap" && *state == GameState::MapLoaded) {
        return true;
    }
    else if (command == "addplayer" && *state == GameState::MapValidated || command == "addplayer" && *state == GameState::PlayersAdded) {
        return true;
    }
    else if (command == "assigncountries" && *state == GameState::PlayersAdded) {
        return true;
    }
    else if (command == "issueorder" && *state == GameState::AssignReinforcement || command == "issueorder" && *state == GameState::IssueOrder) {
        return true;
    }
    else if (command == "endissueorders" && *state == GameState::IssueOrder) {
        return true;
    }
    else if (command == "execorder" && *state == GameState::ExecuteOrders) {
        return true;
    }
    else if (command == "endexecorders" && *state == GameState::ExecuteOrders) {
        return true;
    }
    else if (command == "win" && *state == GameState::ExecuteOrders) {
        return true;
    }
    else if (command == "play" && *state == GameState::Win) {
        return true;
    }
    else if (command == "end" && *state == GameState::Win) {
        return true;
    }
    return false;
}

    /* Implementation for each state functionality will be done in Assignment #2.  It will verify the current state and apply the functionality of that state*/
    void GameEngine::startupPhase() {
        switch (*state) {
            case GameState::Start: {  
                std::cout << "++++++++++++++++++++++++++++++\n";
                std::cout << "A new Game of Warzone has started.\n";
                std::cout << "++++++++++++++++++++++++++++++\n";
                break;
            }
            case GameState::MapLoaded: {  
                std::cout << "++++++++++++++++++++++++++++++\n";
                std::cout << "Transition to MapLoaded State.\n";
                std::cout << "Map loading.\n";
                std::cout << "...\n";
                std::cout << "Map loaded successfully.\n";
                std::cout << "++++++++++++++++++++++++++++++\n";
                break;
            }
            case GameState::MapValidated: {  
                std::cout << "++++++++++++++++++++++++++++++\n";
                std::cout << "Transition to MapValidated State.\n";
                std::cout << "Map validating.\n";
                std::cout << "...\n";
                std::cout << "Map validated successfully.\n";
                std::cout << "++++++++++++++++++++++++++++++\n";
                break;
            }
            case GameState::PlayersAdded: {  
                std::cout << "++++++++++++++++++++++++++++++\n";
                std::cout << "Adding new player.\n";
                std::cout << "...\n";
                std::cout << "Player added successfully.\n";
                std::cout << "++++++++++++++++++++++++++++++\n";
                break;
            }
            default:
                std::cout << "No valid state transition.\n";
                break;
        }
    }
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void GameEngine::reinforcementPhase(){
        if (*state == GameState::AssignReinforcement){
            std::cout << "++++++++++++++++++++++++++++++\n";
            std::cout << "...\n";
            std::cout << "Countries assigned successfully.\n";
            std::cout << "++++++++++++++++++++++++++++++\n";
        }
    };
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void GameEngine::ordersIssuingPhase(){
        if (*state == GameState::IssueOrder){
            std::cout << "++++++++++++++++++++++++++++++\n";
            std::cout << "Issuing orders phase.\n";
            std::cout << "...\n";
            std::cout << "Orders issued successfully.\n";
            std::cout << "++++++++++++++++++++++++++++++\n";
        }
    };
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void GameEngine::ordersExecutionPhase(){
        if (*state == GameState::ExecuteOrders){
            std::cout << "++++++++++++++++++++++++++++++\n";
            std::cout << "Executing orders phase.\n";
            std::cout << "...\n";
            cout << "End of executing orders phase.\n";
            std::cout << "++++++++++++++++++++++++++++++\n";
        }
    };
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void GameEngine::endPhase(){
    if (*state == GameState::Win){
        std::cout << "++++++++++++++++++++++++++++++\n";
        cout << "You have won the game!\n";
        cout << "Here are some stats: ...\n";
        cout << "To play a new game, please write the command -play\n";
        cout << "To end the game, please write the command -end\n";
        std::cout << "++++++++++++++++++++++++++++++\n";
        }
    };


