#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "Linked/FilaEnc.hpp"
#include "Carro.hpp"
#include <cstdio>

class Pista : public FilaEnc<Carro*> {
private: 
	int tamanho, carrosPassaram, carrosEntraram,
	espacoOcupado, vMedia, atividade, tempoChegada,
	tempoCriacaoPos, tempoCriacaoNeg;
	bool fonte, sumidouro;

public:
	Pista(int _tamanho, int _vMedia, int _intervaloCriacao, int _tempoCriacao) : FilaEnc<Carro*>() {
		tamanho = _tamanho;
		espacoOcupado = 0;
		carrosPassaram = 0;
		carrosEntraram = 0;
		vMedia = _vMedia;
		tempoChegada = tamanho / _vMedia;
		tempoCriacaoPos = _tempoCriacao + _intervaloCriacao;
		tempoCriacaoNeg = _tempoCriacao - _intervaloCriacao;
		if (_intervaloCriacao == 0) {
		    if (_tempoCriacao == 0) {
		        fonte = false;
		        sumidouro = true;
		    } else if (_tempoCriacao == 1) {
		        fonte = false;
		        sumidouro = false;
		    }
		} else {
		    fonte = true;
		    sumidouro = false;
		}
	}

	void adicionaCarro(Carro* carro) {
		int _espacoOcupado = espacoOcupado + carro->getTamanho();
		if (_espacoOcupado <= tamanho) {
			this->inclui(carro);
			espacoOcupado = _espacoOcupado;	
			carrosEntraram++;
 		}
	}

	void removeCarro() {
		this->retira();
		carrosPassaram++;
	}

	int calculeProximoEvento(int tempoAtual) {
		return (tempoCriacaoNeg + (rand() % (int) (tempoCriacaoPos - 2 + 1)) + tempoAtual);
	}

	int tempoDeChegada(int tempoNasceu) {
		return tempoNasceu + tempoChegada;
	}
	
	bool estaCheia(Carro* carro) {
		return espacoOcupado + carro->getTamanho() > tamanho;
	}

	int getAtividade() {
		return atividade;
	}

	bool isFonte() {
		return fonte;
	}

	bool isSumidouro() {
		return sumidouro;
	}

	int retornaCarrosQuePassaram() {
		return carrosPassaram;
	}

	int retornaCarrosQueEntraram() {
		return carrosEntraram;
	}
};

#endif
