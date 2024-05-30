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
#include "ascii.h"


using namespace std;


int main() {

    // user input 

    std::string answer;
    std::cout << "A) Do you want to read the ascii art file? or B) get a surprise?";

    std::cin >> answer;


    if (answer == "A") {
        // Define the filename
        string filename = "ascii_art.txt";

        // Read the ASCII art from the file
        vector<string> asciiArt = readAsciiArtFromFile(filename);

        // Print the ASCII art to the console
        printAsciiArt(asciiArt);
    }
    else if (answer == "B") {
        // Run the blinking eye effect
        blinkingEyeEffect();
    }



    return 0;
}

