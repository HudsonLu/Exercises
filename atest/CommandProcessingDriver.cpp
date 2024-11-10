#include "CommandProcessing.h"
#include <iostream>
#include <memory>

void testCommandProcessor(const std::string& mode, const std::string& filename = "") {
    std::unique_ptr<CommandProcessor> processor;
    
    if (mode == "-console") {
        processor = std::make_unique<CommandProcessor>();
    } else if (mode == "-file" && !filename.empty()) {
        processor = std::make_unique<FileCommandProcessorAdapter>(filename);
    } else {
        std::cerr << "Invalid mode or missing filename for file mode." << std::endl;
        return;
    }

    while (true) {
        Command* command = processor->getCommand();
        if (!command) break;
        
        std::cout << "Command: " << command->getCommand() << "\nEffect: " << command->getEffect() << std::endl;
        delete command;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./program -console OR ./program -file <filename>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string filename = argc == 3 ? argv[2] : "";

    testCommandProcessor(mode, filename);

    return 0;
}
