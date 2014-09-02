#ifndef LISTA_HPP_
#define LISTA_HPP_
#include "ExcecaoListaVazia.h"
#include "ExcecaoListaCheia.h"
#include "ExcecaoPosicao.h"
#define MAX 100

class Lista {
 public:
 	T* lista;
 	int tamanho;
 	int ultimo;

 	Lista();
 	Lista(int t);
 	T adiciona(T dado);
 	T adicionaNoInicio(T dado);
 	T adicionaNaPosicao(T dado, int posicao);
 	T adicionaEmOrdem(T dado);
 	T retira();
 	T retiraDoInicio();
 	T retiraDaPosicao(int posicao);
 	T retiraEspecifico(T dado);
 	bool listaCheia();
 	bool listaVazia();
 	int posicao(T dado);
 	bool contem(T dado);
 	bool maior(T dado1, T dado2);
 	bool menor(T dado1, T dado2);
 	bool igual(T dado1, T dado2);
 	void inicializaLista();
 	void destroiLista();
};

template <typename T>
Lista<T>::Lista() {
	ultimo = -1;
	lista = new T[MAX];
	tamanho = MAX;
}

template <typename T>
Lista<T>::Lista(int t) {
	ultimo = -1;
	lista = new T[t];
	tamanho = t;
}

template <typename T>
T Lista<T>::adiciona(T dado) {
	return adicionaNaPosicao(dado, ultimo);
}

template <typename T>
T Lista<T>::adicionaNoInicio(T dado) {
	return adicionaNaPosicao(0);
}

template <typename T>
T Lista<T>::adicionaNaPosicao(T dado, int posicao) {
	if (listaCheia()) {
		throw ExcecaoListaCheia();
	}
	if (posicaoValida(posicao)) {
		throw ExcecaoPosicao();
	}
	ultimo++;
	for (int i = posicao; i < ultimo; i++) {
		lista[posicao] = lista[posicao + 1];
	}
	T dado = lista[posicao];
	return dado;
}

template <typename T>
T Lista<T>::retira() {
	return retiraDaPosicao(ultimo);
}

template <typename T>
T Lista<T>::retiraDoInicio() {
	return retiraDaPosicao(0);
}

template <typename T>
T Lista<T>::retiraDaPosicao(int posicao) {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	if (posicaoValida(posicao)) {
		throw ExcecaoPosicao();
	}
	ultimo--;
	T dado = lista[posicao];
	for (int i = posicao; i < ultimo; i++) {
		lista[posicao] = lista[posicao - 1];
	}
	return dado;
}

template <typename T>
bool Lista<T>::listaCheia() {
	return (ultimo = tamanho - 1);
}

template <typename T>
bool Lista<T>::listaVazia() {
	return (ultimo == -1);
}

template <typename T>
bool Lista<T>::posicaoValida(int p) {
	return (p > ultimo + 1 || p < 0);
}

template <typename T>
void Lista<T>::inicializaLista() {
	ultimo = -1;
}

template <typename T>
void Lista<T>::destroiLista() {
	ultimo = -1;
}

#endif
