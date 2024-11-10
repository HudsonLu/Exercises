#include "CommandProcessing.h"

// Command class implementation
// Constructors & Destructor
Command::Command(const std::string& cmd) {
    command = new std::string(cmd);
    effect = new std::string("");
}
Command::Command(const Command& c) {
    command = new std::string(*c.command);
    effect = new std::string(*c.effect);
}
Command::~Command() {
    delete command;
    delete effect;
}
// Accessors and Mutators
std::string Command::getCommand() const {
    return *command;
}
std::string Command::getEffect() const {
    return *effect;
}
void Command::setCommand(const std::string& c) {
    *command = c;
}
// Methods
void Command::saveEffect(const std::string& eff) {
    *effect = eff;
}
// Assignment operator and << operator
Command& Command::operator=(const Command& other) {
    if (this != &other) {
        *command = *other.command;
        *effect = *other.effect;
    }
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Command& c) {
    out << "Command: " << *c.command << ", Effect: " << *c.effect;
    return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CommandProcessor class implementation
// Constructors and Destructor
CommandProcessor::CommandProcessor(const CommandProcessor& other) {
    for (Command* cmd : other.lc) {
        lc.push_back(new Command(*cmd));
    }
}
CommandProcessor::~CommandProcessor() {
    for (Command* cmd : lc) {
        delete cmd;
    }
}
// Accessor and Mutator
Command* CommandProcessor::getCommand() {
    if (lc.empty()) return nullptr;
    return lc.back();  
}
const std::vector<Command*>& CommandProcessor::getCommands() const {
    return lc;
}
void CommandProcessor::setCommands(const std::vector<Command*>& commands) {
    for (Command* cmd : lc) {
        delete cmd;
    }
    lc.clear();
    for (Command* cmd : commands) {
        lc.push_back(new Command(*cmd));
    }
}
// Methods
std::string CommandProcessor::readCommand() {
    std::string userInput;
    std::cout << "Enter command: ";
    std::getline(std::cin, userInput);
    return userInput;
}
void CommandProcessor::saveCommand(const std::string& commandStr) {
    Command* command = new Command(commandStr);
    validate(command);
    lc.push_back(command);
}
void CommandProcessor::validate(Command* command) {
    std::string cmdText = command->getCommand();
    if (cmdText == "invalid_command") {
        command->saveEffect("Error: Invalid command in the current game state.");
    } else {
        command->saveEffect("Command executed successfully.");
    }
}
// Assignment operator and << operator
CommandProcessor& CommandProcessor::operator=(const CommandProcessor& other) {
    if (this != &other) {
        for (Command* cmd : lc) {
            delete cmd;
        }
        lc.clear();
        for (Command* cmd : other.lc) {
            lc.push_back(new Command(*cmd));
        }
    }
    return *this;
}
std::ostream& operator<<(std::ostream& out, const CommandProcessor& cp) {
    out << "CommandProcessor with " << cp.lc.size() << " commands:\n";
    for (const Command* cmd : cp.lc) {
        out << *cmd << "\n";
    }
    return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors and Destructor
FileLineReader::FileLineReader() {}
FileLineReader::FileLineReader(const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}
FileLineReader::~FileLineReader() {
    if (file.is_open()) {
        file.close();
    }
}
// Methods
std::string FileLineReader::readLineFromFile() {
    std::string line;
    if (file.is_open() && std::getline(file, line)) {
        return line;
    } else {
        return ""; 
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Free Functions
void printCommandsMenu() {
    std::cout << "Command Menu\n";
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "Command               Valid in State                Transitions to\n";
    std::cout << "---------------------------------------------------------------------\n";
    std::cout << "loadmap <mapfile>     start, maploaded              maploaded\n";
    std::cout << "validatemap           maploaded                     mapvalidated\n";
    std::cout << "addplayer <playername> mapvalidated, playersadded   playersadded\n";
    std::cout << "gamestart             playersadded                  assignreinforcement\n";
    std::cout << "replay                win                           start\n";
    std::cout << "quit                  win                           exit program\n";
}