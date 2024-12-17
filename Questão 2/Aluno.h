#pragma once
#include "Pessoa.h"

using namespace std;

class Aluno : public Pessoa
{
    int matricula, tempoEstudo;
public:
    string _classe();
    Aluno(long long cpf, string nome);
    void setMatricula(long matricula);
    long getMatricula();
    void setTempoEstudo(int tempo);
    int getTempoEstudo();
    void imprime();
    void imprime(string obs);
};

