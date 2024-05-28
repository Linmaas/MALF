#include "printAsciiArt.h"

// Function to print the ASCII art
void printAsciiArt(const std::vector<std::string>& art) {

    for (const std::string& line : art) {
        std::cout << line << std::endl;
    }
}