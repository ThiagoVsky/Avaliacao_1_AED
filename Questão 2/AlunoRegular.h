#pragma once
#include "Aluno.h"
class AlunoRegular : public Aluno
{
    string _classe();
public:
    void imprime();
    void imprime(string obs);
    AlunoRegular(long long cpf, string nome);
};