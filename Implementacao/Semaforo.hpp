#ifndef SEMAFORO_HPP_
#define SEMAFORO_HPP_
#include "ExcecaoSinalVermelho.hpp"
#include "Vector/Lista.hpp"
#include "Pista.hpp"
#include <iostream>
#include <cstdio>

class Semaforo {
 private:
	Lista<Pista*>* pistas;
	Pista* pistaLocal;
	int tempoIntervalo;
	int *probabilidades;
	int tempoQueVaiAbrir; 
	bool aberto;
 public:

	Semaforo(bool _estaAberto, Pista* arranjo[], int *_probabilidades, int _tempoIntervalo) {
		pistas = new Lista<Pista*>(3);
		probabilidades = _probabilidades;
		tempoIntervalo = _tempoIntervalo;
		tempoQueVaiAbrir = 0;
		aberto = _estaAberto;
		pistaLocal = arranjo[0];
		pistas->adiciona(arranjo[1]);
		pistas->adiciona(arranjo[2]);
		pistas->adiciona(arranjo[3]);
	}

	Pista* passaCarro() {
		Carro* c = pistaLocal->primeiro();
		int pistaEscolhida = calculaProbabilidade(c);
		Pista* proxima = pistas->retornaDado(pistaEscolhida);
		if(isAberto()) {
			if (!proxima->estaCheia(c)) {
				pistaLocal->removeCarro();
				proxima->adicionaCarro(c);
				return proxima;
			} else {
				proxima = pistaLocal;
			}
		} else {
			throw ExcecaoSinalVermelho;
		}
		return proxima;
	}

	void trocarAberto(int tempoAtual) {
		if (aberto) {
			aberto = false;
			calculeProximoEvento(tempoAtual);
		} else {
			aberto = true;
		}
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

	bool isAberto() {
		return aberto;
	}

	Pista* retornaPistaLocal() {
		return pistaLocal;
	}

	int retornarTempoQueVaiAbrir() {
		return tempoQueVaiAbrir;
	}
};

#endif
