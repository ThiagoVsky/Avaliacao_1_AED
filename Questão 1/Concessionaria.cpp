#include <string>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "classes.h"

void Concessionaria::loopCriarVeiculo(int n) {	
	if (n > 0) {
		srand(time(0) * ( n + ( n * n )) + n % 5); // equa��o para distribuir melhor o c�lculo de aleatoriedade baseado no tempo.
		veiculos.push_back(
			Veiculo(
				static_cast<MARCA>(rand() % 8),
				static_cast<MODELO>(rand() % 13),
				static_cast<COR>(rand() % 3),
				(rand() % 4000) + 800, //peso de 800 a 4800
				(rand() % 30) + 1995)); // ano de 1995 a 2025
		n--;
		loopCriarVeiculo(n);
	}
}

Concessionaria::Concessionaria() {
	string n;
	cin >> n;
	setNome(n);
	cout << "Concession�ria de nome " << n << " criada!" << endl << "Quantidade m�xima de ve�culos: " << 3050 << endl;
}

void Concessionaria::criarVeiculo(MARCA marca, MODELO modelo, COR cor, int peso) {
	veiculos.push_back(Veiculo(marca, modelo, cor, peso));
}

void Concessionaria::criarVeiculo() {
	int n, max = 3000;
	cin >> n;
	if (n <= 0) {
		cout << "Precisa ser um n�mero maior que zero." << endl;
		n = 1;
	}
	else if (n > max) {
		cout << "O n�mero m�ximo de ve�culos que cabem nessa concession�ria � " << max << ". Vamos evitar um stack overflow!" << endl;
		n = max;
	}
	
	loopCriarVeiculo(n);
	cout << n << " Ve�culos criados com sucesso." << endl;
}

string Concessionaria::imprimirVeiculos() {
	cout << "Imprimindo lista de ve�culos." << endl << endl;
	int i = 0;
	string imp;
	for (Veiculo v : getVeiculos()) {
		i++;
		imp = imp + "Carro " + to_string(i) + ": " + v.getVeiculo() + "\n";
	}

	cout << imp;
	return imp;
}
void Concessionaria::imprimirVeiculos(string imp) {
	string path = "C:\\ProgramData\\";
	//cout << "digite o local que o arquivo deve ser salvo. Deixe em branco para salvar no local padr�o" << endl;
	//cin >> path1;
	ofstream arquivo(path + getNome() + ".txt");
	arquivo << imp << endl;
	arquivo.close();
	cout << "impresso na pasta " << path << endl;
}
