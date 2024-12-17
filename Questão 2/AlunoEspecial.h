#pragma once
#include "Aluno.h"
class AlunoEspecial : public Aluno
{
    string _classe();
public:
    void imprime();
    void imprime(string obs);
    AlunoEspecial(long long cpf, string nome);
};

