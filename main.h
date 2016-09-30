#include <windows.h>

#include <stdio.h>
#include <string>
#include <sstream>
#include <cmath>
#include <random>
#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

//Beep(rand()%1720+20,rand()%300+10);
std::string uint64ToString(uint64_t i)
{
    std::stringstream ss;
    ss<<i;
    return ss.str();
}
std::string intToString(int i)
{
    std::stringstream ss;
    ss<<i;
    return ss.str();
}
std::string floatToString(float i)
{
    std::stringstream ss;
    ss<<i;
    return ss.str();
}
std::string uint64ToString2(double i)
{
    std::stringstream ss;
    ss<<i;
    return ss.str();
}
