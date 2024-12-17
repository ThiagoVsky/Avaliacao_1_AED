#pragma once
#include "Pessoa.h"
class Professor : public Pessoa
{
    int siape, tempoServico;
    string _classe();
public:
    Professor(long long cpf, string nome);
    void setSiape(long siape);
    long getSiape();
    void setTempoServico(int tempo);
    int getTempoServico();
    void imprime();
    void imprime(string obs);

};

