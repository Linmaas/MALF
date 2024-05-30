//
//  ascii.hpp
//  example_3
//
//  Created by Linda Maas on 30.05.24.
//

#ifndef ascii_hpp
#define ascii_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

void blinkingEyeEffect();
void printAsciiArt(const std::vector<std::string> &art);
std::vector<std::string> readAsciiArtFromFile(const std::string &filename);

#endif /* ascii_hpp */
