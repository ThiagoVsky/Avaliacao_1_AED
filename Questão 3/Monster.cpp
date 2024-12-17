#include "Monster.h"



TypeMonster Monster::getMonsterType() { return this->type; }
int Monster::getMonsterLevel() { return this->monsterLevel; }
int Monster::getMonsterAtt() { return this->monsterAtt; }
int Monster::getMonsterDef() { return this->monsterDef; }
int Monster::getMonsterLife() { return this->monsterLife; }
string Monster::getMonsterName() { return this->monsterName; }
void Monster::setMonsterName(string name) { this->monsterName = name; }
void Monster::setMonsterLevel(int lvl) {
    this->monsterLevel = lvl;
    setMonsterDef(lvl * 2);
    setMonsterAtt(lvl * 5);
    setMonsterLife(lvl * 30);
}
void Monster::setMonsterAtt(int att) { this->monsterAtt = att; }
void Monster::setMonsterDef(int def) { this->monsterDef = def; }
void Monster::setMonsterLife(int life) {
    if (life <= 0) {
        setIsDead(true);
        this->monsterLife = 0;
    }
    else this->monsterLife = life;
}
void Monster::setTypeMonster(enum TypeMonster type) { this->type = type; }
void Monster::setIsDead(bool dead) { this->isDead = dead; }
bool Monster::getIsDead() { return this->isDead; }

Monster::Monster() {
    srand(time(NULL));
    int select = rand() % 6;
    if (select == 0)
        setMonsterAttributes(
            MONSTER,
            1,
            "Goblin"
        );
    else if (select == 1)
        setMonsterAttributes(
            MONSTER,
            1,
            "Hoplitai"
        );
    else if (select == 2)
        setMonsterAttributes(
            MONSTER,
            1,
            "Mandrake"
        );
    else if (select == 3)
        setMonsterAttributes(
            MONSTER,
            1,
            "Goblin Sórdido"
        );
    else if (select == 4)
        setMonsterAttributes(
            MONSTER,
            2,
            "Espectro"
        );
    else 
        setMonsterAttributes(
            MONSTER,
            2,
            "Goblin Subterrâneo"
        );


}

void Monster::setMonsterAttributes(TypeMonster type, int level, string name) {
    setTypeMonster(type);
    setMonsterLevel(level);
    setMonsterName(name);
}