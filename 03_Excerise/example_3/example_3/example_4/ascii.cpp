//
//  ascii.cpp
//  example_3
//
//  Created by Linda Maas on 30.05.24.

#include "ascii.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>


using namespace std;

int X = 1;
// Function to print the ASCII art to the console
void printAsciiArt(const vector<string> &art)
{
    for (const string &line : art)
    {
        std::cout << line << endl;
    }
}



// Function to create the blinking effect


void blinkingEyeEffect()
{
    std::vector<std::string> faceOpenEye = {
        "\t  *****  ",
        "\t *     * ",
        "\t*  O O  *",
        "\t*",  X    ,"*",
        "\t* \\___/ *",
        "\t *     * ",
        "\t  *****  "};

    std::vector<std::string> faceClosedEye = {
        "\t  *****  ",
        "\t *     * ",
        "\t*  O -  *",
        "\t*   ^   *",
        "\t* \\___/ *",
        "\t *     * ",
        "\t  *****  "};

    for (int i = 0; i < 10; ++i)
    { // Blink 10 times
        printAsciiArt(faceOpenEye);
        this_thread::sleep_for(chrono::milliseconds(500)); // Pause for 500 milliseconds
        system("clear");                                   // Clear the console (for UNIX/Linux/macOS). Use "cls" for Windows

        printAsciiArt(faceClosedEye);
        this_thread::sleep_for(chrono::milliseconds(200)); // Pause for 200 milliseconds
        system("clear");                                   // Clear the console (for UNIX/Linux/macOS). Use "cls" for Windows
    }
}





// Function to read ASCII art from a file
vector<string> readAsciiArtFromFile(const string &filename)
{

    vector<string> art;
    ifstream inFile(filename);
    string line;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            art.push_back(line);
        }
        inFile.close();
        cerr << "ASCII Art successfully read from " << filename << endl;
    }
    else
    {
        cerr << "Error opening file: " << filename << endl;
    }

    return art;
}


