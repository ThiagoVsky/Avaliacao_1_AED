#pragma once
#include <iostream>
#include "Monster.h"

/*
Os aquivos de Monster, MiniBoss e Boss n�o puderam ser implementados nesta vers�o.
*/

using namespace std;
class Boss :
    public Monster
{

public:
    Boss(string name);
    void bossDoor(string name);
};

