#pragma once
#include <iostream>
enum situacao {
    ATIVO,
    INATIVO
};
static int i = 10;
using namespace std;
class Pessoa
{
    situacao sit; // coloquei a vari�vel de situa��o aqui para reutilizar c�digo
    long long cpf;
    string nome;
public:
    string _classe();
    Pessoa(long long cpf, string nome);
    void setCpf(long long cpf);
    long long getCpf() { return this->cpf; }
    void setNome(string nome) { this->nome = nome; }
    string getNome() { return this->nome; }
    void setSituacao(bool situ);
    string getSituacao();
    void imprime();
    void imprime(string obs);
};

