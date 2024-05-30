#include "ascii.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdio> // For printf

// #include "mail.hpp"

using namespace std;

void lettersCombination()
{
    std::string username;
    std::cout << "What's your name?";
    std::cin >> username;

    char firstLetterUsername = username[0]; // Accessing the first character

    std::string lover;
    std::cout << "What's the name of your lover?";
    std::cin >> lover;

    char firstLetterLover = lover[0];

    // Create strings from individual characters
    std::string combination = std::string(1, firstLetterUsername) + "+" + std::string(1, firstLetterLover);
    std::cout << "Your combination: " << combination << std::endl;
}

int heart()
{
    std::string username;
    std::cout << "What's your name? ";
    std::cin >> username;

    char firstLetterUsername = username[0]; // Accessing the first character

    // ASCII art for the heart shape with a placeholder for a character
    const char *heart =
        "     ******       ******     \n"
        "   **********   **********   \n"
        " ************* ************* \n"
        "*****************************\n"
        "*****************************\n"
        "************ %c ************\n" // Place the letter in the center
        " *************************** \n"
        "  *************************  \n"
        "   ***********************   \n"
        "    *********************    \n"
        "     *******************     \n"
        "      *****************      \n"
        "       ***************       \n"
        "        *************        \n"
        "         ***********         \n"
        "          *********          \n"
        "           *******           \n"
        "            *****            \n"
        "             ***             \n"
        "              *              \n";

    printf(heart, firstLetterUsername); // Print the heart with the first letter inserted

    return 0;
}
