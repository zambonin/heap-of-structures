#ifndef SEMAFORO_HPP_
#define SEMAFORO_HPP_
#include "ExcecaoSinalVermelho.hpp"
#include "Vector/Lista.hpp"
#include "Pista.hpp"

class Semaforo {
 private:
	Lista<Pista*>* pistas;
	Pista* pistaLocal;
	int tempoIntervalo;
	int *probabilidades;
	int tempoQueVaiAbrir; 
	bool aberto;
	
 public:
	Semaforo(bool _aberto, Pista* arranjo[], int *_probabilidades, int _tempoIntervalo) {
		pistas = new Lista<Pista*>(3);
		probabilidades = _probabilidades;
		tempoIntervalo = _tempoIntervalo;
		tempoQueVaiAbrir = 0;
		aberto = _aberto;
		pistaLocal = arranjo[0];
		for (int i = 1; i < 4; i++) {
		    pistas->adiciona(arranjo[i]);
		}
	}

	Pista* passaCarro() {
		Carro* carro = pistaLocal->primeiro();
		int pistaEscolhida = calculaProbabilidade(carro);
		Pista* proxima = pistas->retornaDado(pistaEscolhida);
		if(!aberto) {
		    throw ExcecaoSinalVermelho();
		}
		if (!proxima->estaCheia(carro)) {
			pistaLocal->removeCarro();
			proxima->adicionaCarro(carro);
			return proxima;
		} 
		proxima = pistaLocal;
		return proxima;
	}

	void trocarAberto(int tempoAtual) {
		if (aberto) {
			calculeProximoEvento(tempoAtual);
		}
	    aberto = !aberto;
	}

	int calculeProximoEvento(int tempoAtual) {
		return (tempoAtual + tempoIntervalo);
	}

	int calculaProbabilidade(Carro* c) {
		int *prob = probabilidades;
		int numPistas = pistas->getTamanho();
		int probabilidadeDoCarro = c->getProbabilidade();
		int valorComp[numPistas];
		valorComp[0] = prob[0];					
		for (int i = 1; i < numPistas; i++) {
			valorComp[i] = valorComp[i - 1] + prob[i];
		}
		for (int i = 0; i < numPistas; i++) {
			if (probabilidadeDoCarro <= valorComp[i]) {
				return i;
			}
		}
		return -1;
	}

	int retornaIntervalo() {
		return tempoIntervalo;
	}

	Pista* retornaPistaLocal() {
		return pistaLocal;
	}

	int retornarTempoQueVaiAbrir() {
		return tempoQueVaiAbrir;
	}
};

#endif
