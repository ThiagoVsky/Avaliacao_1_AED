#include <string>
#include <iostream>

#include "classes.h"

Veiculo::Veiculo(MARCA marca, MODELO modelo, COR cor, int peso) {
	setVeiculo(marca, modelo, cor, peso, 2024);
};

Veiculo::Veiculo(MARCA marca, MODELO modelo, COR cor, int peso, int ano) {
	setVeiculo(marca, modelo, cor, peso, ano);
};

void Veiculo::setVeiculo(MARCA marca, MODELO modelo, COR cor, int peso, int ano) {
	setMarca(marca);
	setModelo(modelo);
	setCor(cor);
	setAno(ano);
	setPeso(peso);
}

void Veiculo::imprimirVeiculo() {
	cout << getVeiculo() << endl;
}

string Veiculo::getVeiculo() {
	return	getMarca() + " modelo " +
			getModelo() + " de cor " +
			getCor() + ", peso " +
			to_string(getPeso()) + " e ano " +
			to_string(getAno());
}

string Veiculo::getMarca() {

	switch (static_cast<int>(this->marca)) {
		case BYD: return "BYD";
		case VOLKSWAGEN: return "Volksvagen";
		case HAVAL: return "Haval";
		case FIAT: return "Fiat";
		case BMW: return "BMW";
		case GURGEL: return "Gurgel";
		case BUGRE: return "Bugre";
		case LADA: return "Lada";
	}
}

string Veiculo::getModelo() {
	switch (static_cast<int>(this->modelo)) {
		case ABA: return "Aba";
		case BEBA: return "Beba";
		case CIBA: return "Ciba";
		case DOBA: return "Doba";
		case EBA: return "Eba";
		case FABA: return "Faba";
		case GABA: return "Gaba";
		case HABA: return "Haba";
		case IABA: return "Iaba";
		case JABA: return "jaba";
		case KABA: return "Kaba";
		case LABA: return "Laba";
		case MAMBA: return "Mamba";
	}
}

string Veiculo::getCor() {
	switch (static_cast<int>(this->cor)) {
	case PRETO: return "preto";
	case PRATA: return "prata";
	case BRANCO: return "branco";
	}
}