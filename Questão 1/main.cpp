#include <iostream>
#include <string>
#include <locale.h>

#include "classes.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	cout << "Ol�, seja bem-vindo(a) ao software de cadastro de carros na concession�ria" << endl <<
		"Para come�ar, digite o nome da sua concession�ria" << endl;
	Concessionaria con;

	

	cout << "Por favor, insira quantos carros voc� quer cadastrar" << endl;
	con.criarVeiculo();

	con.imprimirVeiculos(con.imprimirVeiculos());

    system("pause");
}
