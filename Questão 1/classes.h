#ifndef A
#define A

#include <string>
#include <list>

using namespace std;
enum MARCA {
	BYD,
	VOLKSWAGEN,
	HAVAL,
	FIAT,
	BMW,
	GURGEL,
	BUGRE,
	LADA
};

enum MODELO {
	ABA,
	BEBA,
	CIBA,
	DOBA,
	EBA,
	FABA,
	GABA,
	HABA,
	IABA,
	JABA,
	KABA,
	LABA,
	MAMBA
};

enum COR {
	PRETO,
	PRATA,
	BRANCO
};

class Veiculo {
	int peso, ano;
	COR cor;
	MARCA marca;
	MODELO modelo;
	void setVeiculo(MARCA marca, MODELO modelo, COR cor, int peso, int ano);

public:
	int getPeso(){ return this->peso; }
	void setPeso(int p){ if(p > 100 && p < 36000) this->peso = p; } 
	int getAno(){ return this->ano;	}
	void setAno(int a){ if(a <= 2025 && a >= 1880) this->ano = a; }
	string getCor();
	void setCor(COR cor) { this->cor = cor; }
	string getMarca();
	void setMarca(MARCA m){ this->marca = m; }
	string getModelo();
	void setModelo(MODELO m) { this->modelo = m; }
	
	Veiculo (MARCA marca, MODELO modelo, COR cor, int peso);
	Veiculo (MARCA marca, MODELO modelo, COR cor, int peso, int ano);
	void imprimirVeiculo();
	string getVeiculo();
	
};

class Concessionaria {
	string nome;
	list<Veiculo> veiculos{};
	void loopCriarVeiculo(int n);

public:
	void setNome(string n) { this->nome = n; }
	string getNome() { return this->nome; }
	void setVeiculos(list<Veiculo> v) { this->veiculos = v; }
	list<Veiculo> getVeiculos() { return this->veiculos; }
		
	Concessionaria();
	void criarVeiculo(MARCA marca, MODELO modelo, COR cor, int peso);
	void criarVeiculo();
	string imprimirVeiculos();
	void imprimirVeiculos(string imp);
};

#endif