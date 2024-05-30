//
//  mail.cpp
//  Love_Letters_Mail
//
//  Created by Linda Maas on 30.05.24.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

#include "mail.hpp"
#include "ascii.hpp"

using namespace std;

bool isWin = true;

int macmail() {
    system("open mailto:someone@example.com");

    return 0;
}



int winmail() {
    system("start mailto:someone@example.com");

    return 0;
}

void sendMail(){
 if (isWin == true) {
        winmail();
     
    }
    else {
        macmail();

        
    }
}

void yesOrNo(){

    std::string yorn;
    std::cout << "Do you want to send the love letter? YES or NO:";
    std::cin >> yorn;

    if (yorn == "YES") {
       sendMail();
    }
    else {
        std::cout << "Okay, maybe next time!";
    }
}