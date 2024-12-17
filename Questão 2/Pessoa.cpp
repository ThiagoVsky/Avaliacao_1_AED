#include "Pessoa.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Pessoa::Pessoa(long long cpf, string nome) {
    setCpf(cpf);
    setNome(nome);
    sit = ATIVO;
}
void Pessoa::setCpf(long long cpf) {
    if (cpf <= 99999999999) this->cpf = cpf;
    else this->cpf = 99999999999;
}
void Pessoa::setSituacao(bool situ) {
    if (situ) this->sit = ATIVO;
    else this->sit = INATIVO;
}
string Pessoa::getSituacao() {
    if (this->sit == ATIVO) return "ATIVO";
    else return "INATIVO";
}
void Pessoa::imprime() {
    cout << "Classe " << _classe() << endl;
    cout << "Nome " << getNome() << endl;
    cout << "CPF " << getCpf() << endl;
    cout << "Situação " << getSituacao() << endl;
}
void Pessoa::imprime(string obs) {
    imprime();
    cout << obs << endl;
}
string Pessoa::_classe() {
    return "Pessoa";
}