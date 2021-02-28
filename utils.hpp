// utils.hpp for battleship
#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <string>
#include <sstream>

std::string getLine();
int converterStringToInt() ;

bool checkSize(int, int);
bool checkBoardPos(int, char*);

#endif //UTILS_H