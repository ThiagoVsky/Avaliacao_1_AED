#pragma once
#include <iostream>
#include <random>
#include <ctime>


using namespace std;
enum TypeMonster {
    MONSTER,
    MINIBOSS,
    BOSS
};
class Monster
{
    string monsterName;
    int monsterLevel,
        monsterAtt,
        monsterDef,
        monsterLife;
    TypeMonster type;
    bool isDead = false;

protected:
    void setMonsterAttributes(
        TypeMonster type,
        int level,
        string name
        );

public:
    Monster();
    TypeMonster getMonsterType();
    string getMonsterName();
    int getMonsterLevel(),
        getMonsterAtt(),
        getMonsterDef(),
        getMonsterLife();
    void setMonsterName(string name),
        setMonsterLevel(int lvl),
        setMonsterAtt(int att),
        setMonsterDef(int def),
        setMonsterLife(int life),
        setTypeMonster(enum TypeMonster type),
        setIsDead(bool dead);
    bool getIsDead();

    //Monster(int lvl);
};

