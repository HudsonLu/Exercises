#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib> // For atoi

// Function to validate the format of the tournament command
bool validateTournamentCommand(const std::string& commandText) {
    std::istringstream stream(commandText);
    std::string token;
    int mapsCount = 0, strategiesCount = 0;
    std::string gamesToken, turnsToken;

    std::string currentCategory = "";

    // Parse and count each category
    while (stream >> token) {
        if (token == "-M") {
            currentCategory = "maps";
        } else if (token == "-P") {
            currentCategory = "strategies";
        } else if (token == "-G") {
            currentCategory = "games";
        } else if (token == "-D") {
            currentCategory = "turns";
        } else {
            if (currentCategory == "maps") {
                mapsCount++;
            } else if (currentCategory == "strategies") {
                strategiesCount++;
            } else if (currentCategory == "games") {
                gamesToken = token;
            } else if (currentCategory == "turns") {
                turnsToken = token;
            }
        }
    }

    // Validate counts
    if (mapsCount < 1 || mapsCount > 5) {
        std::cout << "Error: Invalid number of maps (must be between 1 and 5).\n";
        return false;
    }
    if (strategiesCount < 2 || strategiesCount > 4) {
        std::cout << "Error: Invalid number of strategies (must be between 2 and 4).\n";
        return false;
    }
    if (gamesToken.empty() || atoi(gamesToken.c_str()) < 1 || atoi(gamesToken.c_str()) > 5) {
        std::cout << "Error: Invalid number of games (must be between 1 and 5).\n";
        return false;
    }
    if (turnsToken.empty() || atoi(turnsToken.c_str()) < 10 || atoi(turnsToken.c_str()) > 50) {
        std::cout << "Error: Invalid number of turns (must be between 10 and 50).\n";
        return false;
    }

    return true;
}

// Function to parse the tournament command and return a 2D vector
std::vector<std::vector<std::string>> parseTournamentCommand(const std::string& commandText) {
    std::istringstream stream(commandText);
    std::string token;
    std::vector<std::vector<std::string>> parsedCommand(4); // 0: maps, 1: strategies, 2: games, 3: turns

    std::string currentCategory = "";

    // Parse command
    while (stream >> token) {
        if (token == "-M") {
            currentCategory = "maps";
        } else if (token == "-P") {
            currentCategory = "strategies";
        } else if (token == "-G") {
            currentCategory = "games";
        } else if (token == "-D") {
            currentCategory = "turns";
        } else {
            if (currentCategory == "maps") {
                parsedCommand[0].push_back(token);
            } else if (currentCategory == "strategies") {
                parsedCommand[1].push_back(token);
            } else if (currentCategory == "games") {
                parsedCommand[2].push_back(token);
            } else if (currentCategory == "turns") {
                parsedCommand[3].push_back(token);
            }
        }
    }

    return parsedCommand;
}

int main() {
    // Test commands
    std::vector<std::string> testCommands = {
        "tournament -M res/TestMap1_valid.map res/TestMap4_valid.map -P Aggressive Neutral -G 3 -D 20",
        "tournament -M res/TestMap1_valid.map -P Aggressive Aggressive -G 3 -D 20",
        "tournament -M res/TestMap3_invalid.map -P Aggressive Aggressive -G 3 -D 20",
        "tournament -M res/TestMap1_valid.map -P Aggressive -G 6 -D 20" // Invalid
    };

    for (const std::string& command : testCommands) {
        std::cout << "Processing command: " << command << "\n";

        if (validateTournamentCommand(command)) {
            std::cout << "Command is valid.\n";
            std::vector<std::vector<std::string>> parsedCommand = parseTournamentCommand(command);

            // Print parsed components
            std::cout << "Maps:\n";
            for (const std::string& map : parsedCommand[0]) {
                std::cout << "- " << map << "\n";
            }
            std::cout << "Player Strategies:\n";
            for (const std::string& strategy : parsedCommand[1]) {
                std::cout << "- " << strategy << "\n";
            }
            std::cout << "Number of Games: " << parsedCommand[2][0] << "\n";
            std::cout << "Max Turns: " << parsedCommand[3][0] << "\n";
        } else {
            std::cout << "Command is invalid.\n";
        }
        std::cout << "----------------------------------------\n";
    }

    return 0;
}
