#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CommandProcessing.h"

void testFileLineReader(const std::string& filename) {
    FileLineReader fileReader(filename);

    std::cout << "Reading lines from " << filename << ":\n";

    std::string line;
    while (!(line = fileReader.readLineFromFile()).empty()) {
        std::cout << line << std::endl;
    }

    std::cout << "End of file or unable to read more lines.\n";
}

void testCommanProcess(){    
    
    CommandProcessor processor;
    // Test saving and validating commands
    processor.saveCommand("loadmap map1");
    processor.saveCommand("addplayer player1");
    processor.saveCommand("invalid_command");  // Intentionally invalid

    // Display all commands stored in the processor
    std::cout << processor << std::endl;

    // Retrieve and display the last command
    Command* lastCommand = processor.getCommand();
    if (lastCommand) {
        std::cout << "Last command entered: " << lastCommand->getCommand() << std::endl;
        std::cout << "Effect: " << lastCommand->getEffect() << std::endl;
    }}

int main() {
    std::string filename = "testfile.txt";  // Replace with your test file name
    testFileLineReader(filename);
    return 0;
}