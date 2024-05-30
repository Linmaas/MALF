#include "ascii.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

//#include "mail.hpp"


using namespace std;

void lettersCombination(){
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