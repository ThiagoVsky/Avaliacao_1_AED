#include "Boss.h"


Boss::Boss(string name) {
    setMonsterAttributes(
        BOSS,
        7,
        "Guardi�o do Beco"
    );
    bossDoor(name);
}
void Boss::bossDoor(string name) {
    cout << name << " est� diante de uma criatura de bem maior, e logo atr�s � poss�vel ver uma luz vinda do pr�ximo andar. Parece haver uma escada." << endl;
}