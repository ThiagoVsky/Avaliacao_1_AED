#include "AlunoRegular.h"


AlunoRegular::AlunoRegular(long long cpf, string nome) : Aluno(cpf, nome) {
    setTempoEstudo(9);
}
void AlunoRegular::imprime() {
    cout << "Classe " << _classe() << endl;
    cout << "Nome " << getNome() << endl;
    cout << "CPF " << getCpf() << endl;
    cout << "Matrícula " << getMatricula() << endl;
    cout << "Tempo de estudo " << getTempoEstudo() << endl;
    cout << "Situação " << getSituacao() << endl;
}
void AlunoRegular::imprime(string obs) {
    imprime();
    cout << obs << endl;
}
string AlunoRegular::_classe() {
    return "AlunoRegular";
}