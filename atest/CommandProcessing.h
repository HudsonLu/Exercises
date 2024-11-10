#ifndef COMMAND_PROCESSING_H
#define COMMAND_PROCESSING_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

// Command class
class Command {
public:
    Command(const std::string& cmd);
    void saveEffect(const std::string& effect);
    std::string getCommand() const;
    std::string getEffect() const;

private:
    std::string command;
    std::string effect;
};

// CommandProcessor class
class CommandProcessor {
public:
    virtual ~CommandProcessor() = default;
    virtual Command* getCommand();
    
protected:
    void saveCommand(const std::string& command);
    virtual std::string readCommand() = 0;
    void validate(Command* command);

    std::vector<Command*> commandList;
};

// FileLineReader class
class FileLineReader {
public:
    FileLineReader(const std::string& filename);
    std::string readLineFromFile();

private:
    std::ifstream file;
};

// FileCommandProcessorAdapter class
class FileCommandProcessorAdapter : public CommandProcessor {
public:
    FileCommandProcessorAdapter(const std::string& filename);
    
protected:
    std::string readCommand() override;

private:
    FileLineReader flr;
};

#endif // COMMAND_PROCESSING_H
