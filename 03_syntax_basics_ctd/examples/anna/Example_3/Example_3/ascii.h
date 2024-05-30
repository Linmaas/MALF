#pragma once

#ifndef ascii_h
#define ascii_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

using namespace std;


void printAsciiArt(const vector<string>& art);

void blinkingEyeEffect();

std::vector<string> readAsciiArtFromFile(const string& filename);

#endif /* ascii_h + */