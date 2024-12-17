#include <iostream>
#include <string>
#include <locale.h>

#include "classes.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	cout << "Olá, seja bem-vindo(a) ao software de cadastro de carros na concessionária" << endl <<
		"Para começar, digite o nome da sua concessionária" << endl;
	Concessionaria con;

	

	cout << "Por favor, insira quantos carros você quer cadastrar" << endl;
	con.criarVeiculo();

	con.imprimirVeiculos(con.imprimirVeiculos());

    system("pause");
}
