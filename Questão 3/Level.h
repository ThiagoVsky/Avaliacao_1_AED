#pragma once
#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;
class Level
{
    int floor;
    bool isBegin;
    string name;

public:
    int getFloor();
    string getName();
    void setFloor(int floor),
        setName(string name),
        setBeginTrue();

    Level(int floor, string name);
    void levelGen(),
        floorOne(),
        floorTwo(),
        floorThree();
};

