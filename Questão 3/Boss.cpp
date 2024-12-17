#include "Boss.h"


Boss::Boss(string name) {
    setMonsterAttributes(
        BOSS,
        7,
        "Guardião do Beco"
    );
    bossDoor(name);
}
void Boss::bossDoor(string name) {
    cout << name << " está diante de uma criatura de bem maior, e logo atrás é possível ver uma luz vinda do próximo andar. Parece haver uma escada." << endl;
}