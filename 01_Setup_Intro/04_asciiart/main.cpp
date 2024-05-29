// Ascii Art example adapted from ChatGPT example

#include <iostream>
#include <vector>
#include <string>
#include "printAsciiArt.h"

int main()
{

    // user inputs

    std::string animal;
    std::cout << "What do you prefer: cats, dogs or both?: ";

    std::cin >> animal;

    // Define the ASCII art
    std::vector<std::string> cat = {
        "|\---/|",
        "| o_o |",
        " \_^_/"};

    std::vector<std::string> dog = {
        "      __",
        " (___()'`;",
        " /,    /`",
        " \\''--\\ "};

    std::vector<std::string> frog = {
        "        _   _",
        "       (.)_(.)",
        "    _ (   _   ) _",
        "   / \/`-----'\/ \ ",
        " __\ ( (     ) ) /__",
        " )   /\ \._./ /\   (",
        "  )_/ /|\   /|\ \_("};

    if (animal == "cats")
    {
        printAsciiArt(cat);
    }
    else if (animal == "dogs")
    {
        printAsciiArt(dog);
    }
    else if (animal == "both")
    {
        printAsciiArt(frog);
    };

    return 0;
}
