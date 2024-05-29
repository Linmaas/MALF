/*
The Ascii Art examples have been created with the help of ChatGPT.

This example requires additional functionality. We need the possibility to write characters
to the console as well as to read from a file, organize the characters, and store the actual character values.
To achieve all of this, we use

iostream    > this is part of the C++ Input/Output library, which takes care of data streams (https://cplusplus.com/reference/iolibrary/)
                iostream in particular ensures that we can input and output data to the command line console
                https://cplusplus.com/reference/istream/iostream/?kw=iostream
fstream    > this is part of the C++ Input/Output library, which takes care of data streams (https://cplusplus.com/reference/iolibrary/)
                fstream in particular ensures that we can input and output data from and to files
                https://cplusplus.com/reference/fstream/fstream/?kw=fstream
vector      > this is a generic (array) container that stores and organizes our data; in contrast to
                classical arrays, vectors have the capability to change in size
                https://cplusplus.com/reference/vector/vector/?kw=vector
string      > this is the data type that takes care of combining sets of single character in a string
                https://cplusplus.com/reference/string/string/?kw=string

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// Function to print the ASCII art to the console
void printAsciiArt(const vector<string> &art)
{
    for (const string &line : art)
    {
        cout << line << endl;
    }
}
// Function to create the blinking effect
void blinkingEyeEffect()
{
    vector<string> faceOpenEye = {
        "\t  *****  ",
        "\t *     * ",
        "\t*  O O  *",
        "\t*   ^   *",
        "\t* \\___/ *",
        "\t *     * ",
        "\t  *****  "};

    vector<string> faceClosedEye = {
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

int main()
{

    std::string answer;
    std::cout << "A) Do you want to read ascii an art file? B) Or get a surprise?: ";

    std::cin >> answer;

    if (answer == "A")
    {
        // Define the filename
        string filename = "ascii_art.txt";

        // Read the ASCII art from the file
        vector<string> asciiArt = readAsciiArtFromFile(filename);
        // Print the ASCII art to the console
        printAsciiArt(asciiArt);
    }

    else if (answer == "B")
    {
        // Run the blinking eye effect
        blinkingEyeEffect();
    };

    return 0;
}
