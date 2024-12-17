#include "Game.h"

void spaceScreen() {
    for (int i = 0; i < 100; i++) {
        cout << "-";
    }
    cout << endl;
}

char Game::getSelection() { return this->selection; }
void Game::setSelection(char slct) {
    this->selection = toupper(slct);
}
bool Game::verify() {
    char ver;
    cout << "Y/N ";
    cin >> ver;
    ver = toupper(ver);
    if (ver == 'Y') return true;
    return false;
}
bool Game::getIsAlive() { return this->isAlive; }

void Game::setCharName(string name){ this->charName = name; }
void Game::setCharLevel(int lvl) {
    this->charLevel = lvl;
    setCharDef(3 * lvl);
    setCharAtt(8 * lvl);
}
void Game::addCharXp(int xp) {
    this->charXp = getCharXp() + xp;
    cout << "Você ganhou: " << xp << "XP" << endl;
    if (getCharXp() >= 1000) {
        levelUp();
        this->charXp = getCharXp() - 1000;
    }
}
void Game::setCharAtt(int att) { this->charAtt = att; }
void Game::setCharDef(int def) { this->charDef = def; }
void Game::setCharLife(int life) {
    if (life <= 100 && life > 0) this->charLife = life;
    else if (life > 100) this->charLife = 100;
    else {
        setIsAlive(false);
        this->charLife = 0;
    }
}
string Game::getCharName() { return this->charName; }
int Game::getCharLevel() { return this->charLevel; }
int Game::getCharXp() { return this->charXp; }
int Game::getCharAtt() { return this->charAtt; }
int Game::getCharDef() { return this->charDef; }
int Game::getCharLife() { return this->charLife; }
void Game::setIsAlive(bool alive) { this->isAlive = alive; }


void Game::userData() {
    spaceScreen();
    cout << getCharName() << endl << "nvl: " << getCharLevel() << " || exp: " << getCharXp() << " || vida: " << getCharLife() <<
        "/100 || " << level->getFloor() << "º andar" << endl;

}
void Game::charWalk() {

    char wtd = 'm';
    do {
        userData();
        cout << "O que deseja fazer?" << endl << "W -> Frente || A -> Esquerda || D -> Direita || S -> Para trás || F -> Menu" << endl;
        cin >> wtd;
        setSelection(wtd);
        switch (getSelection()) {
        case 'W':
            cout << getCharName() << " segue em frente." << endl;
            break;
        case 'A':
            cout << getCharName() << " vira para a esquerda." << endl;
            break;
        case 'D':
            cout << getCharName() << " vira para a direita." << endl;
            break;
        case 'S':
            cout << getCharName() << " vira para trás e segue." << endl;
            break;
        case 'F':
            pauseGame();
            break;
        default:
            spaceScreen();
            cout << "Entrada desconecida. Tente novamente." << endl;
            wtd = 'm';
            Sleep(500);
            system("cls");
        }
    }while (wtd == 'm');
}

Game::Game() : level(nullptr), monster(nullptr) {
    this->charXp = 0;
    while (!exitGame) {
        spaceScreen();
        if (!loadGame()) startGame();
        while (moveChar()){
            if (monster == nullptr) continue;
            if(battle()) break;
        }
    }
    delete level;
}

bool Game::moveChar() {
    charWalk();
    if (level->getFloor() == 4) {
        gameFinish();
        return false;
    }
    if (getSelection() != 'S' && getSelection() != 'C' && getSelection() != 'Q') {
        srand(time(0));
        int r = rand() % 10;
        if (r <= 3) {
            system("cls");
            int r = rand() % 20;
            if (r <= 12) monster = new Monster();
            else if (r <= 17) monster = new MiniBoss();
            else monster = new Boss(getCharName());

            return true;
        }
        system("cls");
        level->levelGen();
    }
    if (!getIsAlive()) {
        gameOver();
        return false;
    }
    if (exitGame) return false;
    return true;
    system("cls");
}
bool Game::battle() {
    cout << "Batalha com " << monster->getMonsterName() << "!" << endl;
    Sleep(1000);
    while (battleUI()) {
        if (toDefense()) break;
    }
    if (getIsAlive()) battleFinish();
    else return true;
    return false;
}   
void Game::battleFinish() {
    if (monster != nullptr) {
        int xp = 2,
            xpCalc = monster->getMonsterLevel();
        cout << "Você venceu!" << endl;
        switch(monster->getMonsterType()) {
        case 0:
            xp = xpCalc * 200;
            break;
        case 1:
            xp = xpCalc * 150;
            break;
        case 2:
            xp = xpCalc * 100;
            floorUpper();
            break;
        }
        addCharXp(xp);
    }
    delete monster;
    monster = nullptr;
    Sleep(1500);
}
void Game::floorUpper() {

    level->setFloor(level->getFloor() + 1);
}
void Game::levelUp() {
    setCharLevel(getCharLevel() + 1);
    cout << "\nPARABÉNS!!!" << endl << getCharName() << " subiu para o nível " << getCharLevel() << endl;
    cout << "atq: " << getCharAtt() << " || def: " << getCharDef() << endl;
    setCharLife(getCharLife() + 50);
}
void Game::startGame() {
    string nome;
    cout << "Seja muito bem-vindo(a) a A Torre.\nEsta Aventura é curta, mas aproveite a estadia neste labirinto." << endl << endl;

    do {
        cout << "Por favor, insira seu nome." << endl;
        cin >> nome;
        cout << nome << ", seu nome está correto?" << endl;
    } while (!verify());
    system("cls");
    setCharName(nome);
    setCharLevel(1);
    setCharLife(100);
    level = new Level(0, getCharName());
}
bool Game::loadGame() {
    cout << "Carregando jogo..." << endl;
    cout << "Deseja carregar o jogo antigo?" << endl;
    if (verify()) {
        int loadArr[4] { };
        string path1 = "C:\\ProgramData\\a_torre_jogo.save";
        string path2 = "C:\\ProgramData\\a_torre_jogo_nome.save";
        ifstream file1(path1);
        ifstream file2(path2);
        if (file1.is_open() && file2.is_open()) {
            int sizeArr = sizeof(loadArr) / sizeof(loadArr[0]);
            for (int i = 0; i < sizeArr; i++) {
                file1 >> loadArr[i];
            }
            setCharLevel(loadArr[0]);
            addCharXp(loadArr[1]);
            setCharLife(loadArr[2]);
            string nome;
            file2 >> nome;
            setCharName(nome);
            level = new Level(loadArr[3], nome);
            file1.close();
            file2.close();
            system("cls");
            Sleep(300);
            cout << "Jogo carregado com sucesso!" << endl;
            system("pause");
            system("cls");
            return true;
        }
        else {
            cerr << "Não foi possível acessar o arquivo para leitura. Tente novamente mais tarde." << endl;
            system("pause");
        }
        file1.close();
        file2.close();
    }
    system("cls");
    return false;
}
void Game::saveGame() {
    cout << "deseja realmente salvar o jogo?" << endl;
    if (verify()) {
        int saveArr[] { 
            getCharLevel(),
            getCharXp(),
            getCharLife(),
            level->getFloor() 
        };
        string path1 = "C:\\ProgramData\\a_torre_jogo.save";
        string path2 = "C:\\ProgramData\\a_torre_jogo_nome.save";
        ofstream file1(path1);
        ofstream file2(path2);
        if (file1.is_open() && file2.is_open()) {
            int sizeArr = sizeof(saveArr) / sizeof(saveArr[0]);
            for (int i = 0; i < sizeArr; i++) {
                file1 << saveArr[i] << " ";
            }
            file2 << getCharName();
            Sleep(300);
            cout << "Jogo salvo com sucesso!" << endl;
            system("pause");
            system("cls");
        }
        else {
            cerr << "Não foi possível acessar o arquivo para escrita";
            system("pause");
            exit(-2);
        }
        file1.close();
        file2.close();
    }
}
void Game::pauseGame() {
    bool retry = true;
    do {
        system("cls");
        cout << "Abrindo menu." << endl;
        Sleep(200);
        system("cls");
        cout << "Jogo pausado";
        spaceScreen();
        cout << "O que deseja fazer?\nS -> Salvar jogo || C -> Continuar jogando || Q -> Sair do jogo" << endl;
        char wtd;
        cin >> wtd;
        setSelection(wtd);
        switch (getSelection()) {
        case 'S':
            saveGame();
            break;
        case 'C':
            retry = false;
            system("cls");
            break;
        case 'Q':
            retry = false;
            this->exitGame = true;
            break;
        default:
            cout << "Opção incorreta, tente novamente";
            system("pause");
        }
    } while (retry);
}
void Game::gameFinish() {
    exitGame = true;
    cout << "Parabéns! Você encerrou!" << endl << "Por enquanto nossa torre só tem 3 andares e não há planos de expandir." << endl << endl;
    Sleep(2500);
    cout << "---------------- Criador: Thiago Moraes ---------------"<< endl <<
        "---------- Faculdade de Tecnologia, Universidade de Brasília - Brasíl ----------" << endl << endl;
    Sleep(2500);
    cout << "----- Agradeço por jogar! -----";
    Sleep(10000);
    cout << endl << endl;
}
void Game::gameOver() {
    delete monster;
    monster = nullptr;
    Sleep(3000);
    system("cls");
    Sleep(1500);
    cout << "A vida de " << getCharName() << " acabou. Sua jornada se encerrou..." << endl << endl;
    Sleep(3000);
    system("cls");
    Sleep(3000);

}
bool Game::battleUI() {
    char wtd = 'm';
    do {
        userData();
        cout << "Inimigo: " << endl << monster->getMonsterName() << " || nvl: " << monster->getMonsterLevel() <<
            " || vida: " << monster->getMonsterLife() << endl << endl;
        spaceScreen();
        cout << "O que deseja fazer?" << endl << "A -> Atacar || F -> Fugir " << endl;
        cin >> wtd;
        setSelection(wtd);
        switch (getSelection()) {
        case 'A':
            return toAttack();
        case 'F':
            return toRun();
        default:
            cout << endl << "Entrada desconhecida. Tente novamente." << endl;
            Sleep(2000);
            wtd = 'm';
        system("cls");
        }
    } while (wtd == 'm');

}
bool Game::toAttack() {
    system("cls");
    int oldlife = monster->getMonsterLife();
    cout << getCharName() << " ataca!" << endl;
    srand(time(NULL));
    if (rand() % 10 == 0) {
        monster->setMonsterLife(monster->getMonsterLife() - ((getCharAtt() * 2) - monster->getMonsterDef()));
        cout << "Ataque crítico!!" << endl;
    }
    else monster->setMonsterLife(monster->getMonsterLife() - (getCharAtt()) - monster->getMonsterDef());
    cout << "Vida do " << monster->getMonsterName() << ": " << oldlife << " -> " << monster->getMonsterLife() << endl;

    return !monster->getIsDead();
}
bool Game::toDefense() {
    cout << "Vida de " << getCharName() << ": " << getCharLife() << " -> "; 
    setCharLife(getCharLife() - (monster->getMonsterAtt() - getCharDef()));
    cout << getCharLife() << endl;

    Sleep(1500);
    return !getIsAlive();
}
bool Game::toRun(){
    system("cls");
    cout << getCharName() << " foge da batalha!" << endl;
    delete monster;
    monster = nullptr;
    return false;
}