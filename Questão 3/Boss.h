#pragma once
#include <iostream>
#include "Monster.h"

/*
Os aquivos de Monster, MiniBoss e Boss não puderam ser implementados nesta versão.
*/

using namespace std;
class Boss :
    public Monster
{

public:
    Boss(string name);
    void bossDoor(string name);
};

