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
        cout << "Ao adentrar A Torre, que parecia parecia uma constru��o completamente de madeira por dentro, " << getName() <<
            " se depara com um corredor gelado de labirinto, cujas paredes, piso e teto, todos s�o feitos de pedra." << 
            " O ar apesar de frio � denso e �mido e um cheiro bolorento se intensifica." << endl << endl;
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
            cout << getName() << " anda cuidadosamente para n�o tropessar ou esbarrar em algo que n�o esteja n�tido em sua vista." << endl;
            break;
        case 2:
            cout << getName() << " est� caminhando quando percebe um vulto em sua vis�o perif�rica. Tenta olhar na dire��o mas n�o enxerga " <<
                "nada anormal, talvez devido a escurid�o." << endl;
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
            "Ao que parece ser m�gica, agora o piso, as paredes e o teto agora compoem uma estrutura toda de madeira, com ilumina��o claramente " <<
            "artificial, que apesar de fraca e quente, permite ver bem os corredores do labirinto." << endl << endl;
        Sleep(1000);
        isBegin = false;
    }
    else {
        srand(time(0));
        switch (rand() % 2) {
        case 0:
            cout << getName() << " caminha em ritmo normal, percebendo a madeira abaixo de seus p�s rangendo ao ritmo de seus passos." << endl;
            break;
        case 1:
            cout << getName() << " anda cautelosamente tentando n�o chamar aten��o de monstros no caminho, embora o ranger da madeira ainda " << 
                "denuncie sua posi��o." << endl;
            break;
        case 2:
            cout << getName() << " entra em uma porta de correr, estilo japonesa, e sai sem se preocupar em fech�-la novamente." << endl;
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
        cout << getName() << " sobe as escadas da Torre e � instantaneamente cegado pela luz do terceiro andar. Assim que sua vis�o se reestabelece " <<
            getName() << " tem a sensa��o de estar em um local feito de luz. H� luz vindo de todas as dire��es, � quase m�gica saber onde est� o ch�o" <<
            "e as paredes. Os passos n�o produzem som algum. N�o est� quente nem frio. Mas o que surpreende � o sutil cheiro de pipoca com manteiga" <<
            "que este local exala." << endl << endl;
        Sleep(1000);
        isBegin = false;
    }
    else {
        srand(time(0));
        switch (rand() % 2) {
        case 0:
            cout << getName() << " anda lentamente tentando entender com l�gica, sem sucesso, onde est� o ch�o." << endl;
            break;
        case 1:
            cout << getName() << " n�o est� mais prestando aten��o no ch�o, agora est� atento aos arredores com olhos agu�ados em busca de monstros" << endl;
            break;
        case 2:
            cout << getName() << " Est� um pouco cansado de sua jornada no labirinto dA Torre, mas de alguma forma sabe que est� perto do final. " << endl;
            break;
        default:
            system("cls");
            cout << "Um erro ocorreu. Abra o jogo novamente.";
            Sleep(2000);
            exit(2);
        }
    }

}