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

void heart(char letter)
{
    // ASCII art for the heart shape with a placeholder for a character
    const char *heartUser =
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

    printf(  heartUser,  letter); // Print the heart with the first letter inserted


}

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

    // Print the heart ASCII art with the first letter of the username and lover side by side
    heart(firstLetterUsername);
    cout << "  ";
    heart(firstLetterLover);
    cout << endl;

}


