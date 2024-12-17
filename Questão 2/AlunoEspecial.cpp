#include "AlunoEspecial.h"

AlunoEspecial::AlunoEspecial(long long cpf, string nome): Aluno(cpf, nome) {
    setTempoEstudo(5);
}
void AlunoEspecial::imprime() {
    cout << "Classe " << _classe() << endl;
    cout << "Nome " << getNome() << endl;
    cout << "CPF " << getCpf() << endl;
    cout << "Matrícula " << getMatricula() << endl;
    cout << "Tempo de estudo " << getTempoEstudo() << endl;
    cout << "Situação " << getSituacao() << endl;
}
void AlunoEspecial::imprime(string obs) {
    imprime();
    cout << obs << endl;
}
string AlunoEspecial::_classe() {
    return "AlunoEspecial";
}