#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("example.txt"); // Replace "example.txt" with your file name
    if (!file) {
        std::cerr << "Unable to open file." << std::endl;
        return 1; // Exit with error code
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl; // Print each line
    }

    file.close(); // Close the file
    return 0;
}
