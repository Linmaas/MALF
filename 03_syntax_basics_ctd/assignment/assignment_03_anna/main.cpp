// This assignment was made with the help of ChatGPT

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

#include "ascii.hpp"
#include "mail.hpp"

using namespace std;



int main() {
   

#if defined(_WIN32)
    std::cout << "Running on Windows" << std::endl;
    bool isWin = true;
        
#elif defined(__APPLE__)
    std::cout << "Running on macOS" << std::endl;
    
#else
    std::cout << "Unknown operating system" << std::endl;
 #endif

    lettersCombination();

    yesOrNo();

    

    return 0;
}