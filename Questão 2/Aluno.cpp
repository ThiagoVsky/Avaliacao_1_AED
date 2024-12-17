#include "Aluno.h"

Aluno::Aluno(long long cpf, string nome) : Pessoa(cpf, nome) {
    srand(time(0) * i);
    setMatricula((rand() % 8999999) + 1000000);
    i = i * 2;
}
void Aluno::setMatricula(long matricula) { this->matricula = matricula; }
long Aluno::getMatricula() { return this->matricula; }
void Aluno::setTempoEstudo(int tempo) { this->tempoEstudo = tempo; }
int Aluno::getTempoEstudo() { return this->tempoEstudo; }

string Aluno::_classe() {
    return "Aluno";
}

void Aluno::imprime() {
    cout << "Classe " << _classe() << endl;
    cout << "Nome " << getNome() << endl;
    cout << "CPF " << getCpf() << endl;
    cout << "Matrícula " << getMatricula() << endl;
    cout << "Tempo de estudo " << getTempoEstudo() << endl;
    cout << "Situação " << getSituacao() << endl;
}
void Aluno::imprime(string obs) {
    imprime();
    cout << obs << endl;
}