#include "Level.h"

int Level::getFloor() { return this->floor; }
void Level::setFloor(int floor) { this->floor = floor; isBegin = true; }
void Level::setName(string name) { this->name = name; }
string Level::getName() { return this->name; }
void Level::setBeginTrue() { this->isBegin = true; }

Level::Level(int floor, string name) : name(name){
    if (floor == 0) {
        setFloor(1);
        isBegin = true;
        levelGen();
    }
    else {
        setFloor(floor);
        isBegin = false;
    }
    
}
void Level::levelGen() {
    switch (getFloor()) {
    case 1:
        floorOne();
        break;
    case 2:
        floorTwo();
        break;
    case 3:
        floorThree();
        break;
    case 4:
        break;
    default:
        system("cls");
        cout << "Um erro ocorreu. Abra o jogo novamente.";
        Sleep(5000);
        exit(1);
        
    }
}
void Level::floorOne() {
    if (isBegin) {
        cout << "Ao adentrar A Torre, que parecia parecia uma construção completamente de madeira por dentro, " << getName() <<
            " se depara com um corredor gelado de labirinto, cujas paredes, piso e teto, todos são feitos de pedra." << 
            " O ar apesar de frio é denso e úmido e um cheiro bolorento se intensifica." << endl << endl;
        Sleep(1000);
        isBegin = false;
    }
    else {
        srand(time(0));
        switch (rand() % 2) {
        case 0:
            cout << getName() << " caminha naquele corredor escuro iluminado apenas por algmas tochas na parede a cada alguns metros, " <<
                "incapazes de gerar qualquer aquecimento ao local." << endl;
            break;
        case 1:
            cout << getName() << " anda cuidadosamente para não tropessar ou esbarrar em algo que não esteja nítido em sua vista." << endl;
            break;
        case 2:
            cout << getName() << " está caminhando quando percebe um vulto em sua visão periférica. Tenta olhar na direção mas não enxerga " <<
                "nada anormal, talvez devido a escuridão." << endl;
            break;
        default:
            system("cls");
            cout << "Um erro ocorreu. Abra o jogo novamente.";
            Sleep(2000);
            exit(2);
        }
    }
}
void Level::floorTwo() {
    if (isBegin) {
        cout << "Ao subir as escadas para o segundo andar, " << getName() << " percebe um local completamente diferente do que estava antes. " << 
            "Ao que parece ser mágica, agora o piso, as paredes e o teto agora compoem uma estrutura toda de madeira, com iluminação claramente " <<
            "artificial, que apesar de fraca e quente, permite ver bem os corredores do labirinto." << endl << endl;
        Sleep(1000);
        isBegin = false;
    }
    else {
        srand(time(0));
        switch (rand() % 2) {
        case 0:
            cout << getName() << " caminha em ritmo normal, percebendo a madeira abaixo de seus pés rangendo ao ritmo de seus passos." << endl;
            break;
        case 1:
            cout << getName() << " anda cautelosamente tentando não chamar atenção de monstros no caminho, embora o ranger da madeira ainda " << 
                "denuncie sua posição." << endl;
            break;
        case 2:
            cout << getName() << " entra em uma porta de correr, estilo japonesa, e sai sem se preocupar em fechá-la novamente." << endl;
            break;
        default:
            system("cls");
            cout << "Um erro ocorreu. Abra o jogo novamente.";
            Sleep(2000);
            exit(2);
        }
    }

}
void Level::floorThree() {
    if (isBegin) {
        cout << getName() << " sobe as escadas da Torre e é instantaneamente cegado pela luz do terceiro andar. Assim que sua visão se reestabelece " <<
            getName() << " tem a sensação de estar em um local feito de luz. Há luz vindo de todas as direções, é quase mágica saber onde está o chão" <<
            "e as paredes. Os passos não produzem som algum. Não está quente nem frio. Mas o que surpreende é o sutil cheiro de pipoca com manteiga" <<
            "que este local exala." << endl << endl;
        Sleep(1000);
        isBegin = false;
    }
    else {
        srand(time(0));
        switch (rand() % 2) {
        case 0:
            cout << getName() << " anda lentamente tentando entender com lógica, sem sucesso, onde está o chão." << endl;
            break;
        case 1:
            cout << getName() << " não está mais prestando atenção no chão, agora está atento aos arredores com olhos aguçados em busca de monstros" << endl;
            break;
        case 2:
            cout << getName() << " Está um pouco cansado de sua jornada no labirinto dA Torre, mas de alguma forma sabe que está perto do final. " << endl;
            break;
        default:
            system("cls");
            cout << "Um erro ocorreu. Abra o jogo novamente.";
            Sleep(2000);
            exit(2);
        }
    }

}