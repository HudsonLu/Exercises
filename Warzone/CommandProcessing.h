#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Command class
class Command {
    private:
        std::string* command;
        std::string* effect;
    public:
        // Constructor & destructor
        Command(const std::string& cmd);
        Command(const Command& c);
        ~Command();
        // Methods
        void saveEffect(const std::string& effect);
        std::string getCommand() const;
        std::string getEffect() const;
        void setCommand(const std::string& c);
        // Overloaded operators
        Command& operator=(const Command& other);
        friend std::ostream& operator<<(std::ostream& out, const Command& c);
};

// CommandProcessor class 
class CommandProcessor {
    private:
        std::vector<Command*> lc;  
        virtual std::string readCommand();
    public:
        // Constructors and Destructor
        CommandProcessor() = default;
        CommandProcessor(const CommandProcessor& other);
        virtual ~CommandProcessor();
        // Public methods
        Command* getCommand();
        const std::vector<Command*>& getCommands() const;
        void setCommands(const std::vector<Command*>& commands);
        void saveCommand(const std::string& commandStr);
        void validate(Command* command);  
        // Operator overloading
        CommandProcessor& operator=(const CommandProcessor& other);
        friend std::ostream& operator<<(std::ostream& out, const CommandProcessor& c);
};

// FileLineReader class
class FileLineReader {
private:
    std::ifstream file;
public:
    // Constructors and Destructor
    FileLineReader();  
    FileLineReader(const std::string& filename);  
    ~FileLineReader(); 
    // Public methods 
    std::string readLineFromFile();  
};










