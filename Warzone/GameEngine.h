#pragma once
#include <string>
#include <iostream>

// enum class GameState represents each state in the game
enum GameState {
    Start,
    MapLoaded,
    MapValidated,
    PlayersAdded,
    AssignReinforcement,
    IssueOrder,
    ExecuteOrders,
    Win,
};

class GameEngine {
private:
    GameState* state;

public:
    //Constructor
    GameEngine();
    //Destructor
    ~GameEngine();
    // Assignment Operator
    GameEngine& operator=(const GameEngine& other);
    //Accessor
    GameState* getState() const;
    //Mutator
    void setState(GameState newState);
    // return the list of available commands
    std::string listOfCommands();
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void startupPhase();
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void reinforcementPhase();
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void ordersIssuingPhase();
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void ordersExecutionPhase();
    /* Implementation for each state & phase functionality will be done in Assignment #2. It will first verify the current state and apply the functionality of that state*/
    void endPhase();
    //Return a bool value. validateCommandTransition(std::string command) method validates if the command that user inputs is correct or incorrect.
    bool validateCommandTransition(std::string command);
     //Stream insertion operator
    friend std::ostream& operator<<(std::ostream& out, const GameEngine& game);
   
};
//Free function to test the implementation of the game engine with states, commands, and transition.
void testGameStates();
