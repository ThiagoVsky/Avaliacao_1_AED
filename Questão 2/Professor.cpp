#include "Professor.h"

Professor::Professor(long long cpf, string nome) : Pessoa(cpf, nome){
    setSiape(rand() % i);
    i = i *2;
}
void Professor::setSiape(long siape) { this->siape = siape; }
long Professor::getSiape() { return this->siape; }
void Professor::setTempoServico(int tempo) { this->tempoServico = tempo; }
int Professor::getTempoServico() { return this->tempoServico; }

string Professor::_classe() {
    return "Professor";
}
void Professor::imprime() {
    cout << "Classe " << _classe() << endl;
    cout << "Nome " << getNome() << endl;
    cout << "CPF " << getCpf() << endl;
    cout << "SIAPE " << getSiape() << endl;
    cout << "Tempo de serviço " << getTempoServico() << endl;
    cout << "Situação " << getSituacao() << endl;
}
void Professor::imprime(string obs) {
    imprime();
    cout << obs << endl;
}