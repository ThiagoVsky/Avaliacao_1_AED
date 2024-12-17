#pragma once
#include <iostream>
#include <windows.h>
#include <random>
#include <ctime>
#include <fstream>

#include "Level.h"
#include "Monster.h"
#include "MiniBoss.h"
#include "Boss.h"

using namespace std;

class Game
{
    bool exitGame = false,
        isAlive = true;
    char selection;
    string charName;
    int charLevel,
        charXp,
        charAtt,
        charDef,
        charLife;
    Level* level;
    Monster* monster;
public:
    char getSelection();
    void setSelection(char slct);
    bool verify(),
        getIsAlive();
    void setCharName(string name);
    string getCharName();
    void setCharLevel(int lvl);
    int getCharLevel();
    void addCharXp(int xp);
    int getCharXp();
    void setCharAtt(int att);
    int getCharAtt();
    void setCharDef(int def);
    int getCharDef();
    void setCharLife(int life);
    int getCharLife();
    void setIsAlive(bool alive);
    void userData(),
        charWalk();


    

    Game();

    void 
        levelUp(),
        startGame(),
        saveGame(),
        pauseGame(),
        gameFinish(),
        battleFinish(),
        floorUpper(),
        gameOver();
    bool loadGame(),
        moveChar(),
        toAttack(),
        toDefense(),
        toRun(),
        battle(),
        battleUI();

};

