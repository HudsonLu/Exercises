#include "CommandProcessing.h"

// Command class implementation
Command::Command(const std::string& cmd) : command(cmd), effect("") {}

void Command::saveEffect(const std::string& effect) {
    this->effect = effect;
}

std::string Command::getCommand() const {
    return command;
}

std::string Command::getEffect() const {
    return effect;
}

// CommandProcessor class implementation
void CommandProcessor::saveCommand(const std::string& commandStr) {
    Command* command = new Command(commandStr);
    validate(command);
    commandList.push_back(command);
}

Command* CommandProcessor::getCommand() {
    if (commandList.empty()) return nullptr;
    Command* command = commandList.back();
    commandList.pop_back();
    return command;
}

void CommandProcessor::validate(Command* command) {
    // Sample validation logic; replace with actual validation based on game state
    if (command->getCommand() == "invalid") {
        command->saveEffect("Invalid command");
    } else {
        command->saveEffect("Valid command executed");
    }
}

// Console-based CommandProcessor implementation (used in derived classes)
std::string CommandProcessor::readCommand() {
    std::string cmd;
    std::cin >> cmd;
    return cmd;
}

// FileLineReader class implementation
FileLineReader::FileLineReader(const std::string& filename) : file(filename) {}

std::string FileLineReader::readLineFromFile() {
    std::string line;
    if (std::getline(file, line)) {
        return line;
    }
    return "";
}

// FileCommandProcessorAdapter class implementation
FileCommandProcessorAdapter::FileCommandProcessorAdapter(const std::string& filename) : flr(filename) {}

std::string FileCommandProcessorAdapter::readCommand() {
    return flr.readLineFromFile();
}
