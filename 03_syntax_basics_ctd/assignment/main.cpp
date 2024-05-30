// This assignment was made with the help of ChatGPT

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

#include "ascii.h"
#include "mail.h"

using namespace std;

// Check which operating system the application is running

int main() {
    #if defined(_WIN32)
        std::cout << "Running on Windows" << std::endl;
        winmail();
    #elif defined(__APPLE__)
        std::cout << "Running on macOS" << std::endl;
        macmail();
    #else
        std::cout << "Unknown operating system" << std::endl;
    #endif

    return 0;
}