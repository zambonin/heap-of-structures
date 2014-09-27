//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
#ifndef LISTAENC_HPP_
#define LISTAENC_HPP_
#include "Elemento.hpp"
#include "ExcecaoDadoNaoEncontrado.h"
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"
#include "ExcecaoPosicao.h"

template<typename T>
class ListaEnc {
 protected:
	Elemento<T>* cabeca;
	int tamanho;

 public:
	ListaEnc();
	~ListaEnc();
	void adiciona(const T& dado);
	void adicionaEmOrdem(const T& dado);
	void adicionaNaPosicao(const T& dado, int pos);
	void adicionaNoInicio(const T& dado);
	void eliminaDoInicio();
	T retira();
	T retiraEspecifico(const T& dado);
	T retiraDaPosicao(int pos);
	T retiraDoInicio();
	bool contem(const T& dado);
	int posicao(const T& dado) const;
	T* posicaoMem(const T& dado) const;
	void destroiLista();
	bool listaVazia() const;
	bool igual(T dado1, T dado2);
	bool maior(T dado1, T dado2);
	bool menor(T dado1, T dado2);
	bool posicaoInvalida(int p);
};

template <typename T>
ListaEnc<T>::ListaEnc() {
	tamanho = 0;
	cabeca = 0;
}

template <typename T>
ListaEnc<T>::~ListaEnc() {
	destroiLista();
}

template <typename T>
void ListaEnc<T>::adiciona(const T& dado) {
    return adicionaNaPosicao(dado, tamanho);
}

template <typename T>
void ListaEnc<T>::adicionaEmOrdem(const T& dado) {
	if (listaVazia()) {
		return adicionaNoInicio(dado);
	}
	Elemento<T>* atual = cabeca;
	int posicao = 1;
	while (atual->getProximo() != 0 && maior(dado, atual->getInfo())) {
		atual = atual->getProximo();
		posicao++;
	}
	if (maior(dado, atual->getInfo())) {
		return adicionaNaPosicao(dado, posicao + 1);
	}
	adicionaNaPosicao(dado, posicao);
}

template <typename T>
void ListaEnc<T>::adicionaNaPosicao(const T& dado, int posicao) {
	if (posicaoInvalida(posicao)) {
		throw ExcecaoPosicao();
	}
	if (posicao == 0) {
		adicionaNoInicio(dado);
		return;
	}
	Elemento<T>* novo = new Elemento<T>(dado, 0);
	if (novo == 0) {
		throw ExcecaoListaCheia();
	}
	Elemento<T>* anterior = cabeca;
	for (int i = 0; i < posicao - 1; i++) {
		anterior = anterior->getProximo();
	}
	novo->setProximo(anterior->getProximo());
	anterior->setProximo(novo);
	tamanho++;
}

template <typename T>
void ListaEnc<T>::adicionaNoInicio(const T& dado) {
	Elemento<T>* novo = new Elemento<T>(dado, 0);
	if (novo == 0) {
		throw ExcecaoListaCheia();
	}
	novo->setProximo(cabeca);
	cabeca = novo;
	tamanho++;
}

template <typename T>
void ListaEnc<T>::eliminaDoInicio() {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	Elemento<T>* saiu = cabeca;
	cabeca = saiu->getProximo();
	tamanho--;
	delete saiu;
}

template <typename T>
T ListaEnc<T>::retira() {
	return retiraDaPosicao(tamanho);
}

template <typename T>
T ListaEnc<T>::retiraEspecifico(const T& dado) {
	if(listaVazia()) {
		throw ExcecaoListaVazia();
	}
	return retiraDaPosicao(posicao(dado) + 1);
}

template <typename T>
T ListaEnc<T>::retiraDaPosicao(int posicao) {
	if (posicaoInvalida(posicao)) {
		throw ExcecaoPosicao();
	}
	if (posicao == 0) {
		return retiraDoInicio();
	}
	Elemento<T>* anterior = cabeca;
	for (int i = 0; i < posicao - 2; i++) {
		anterior = anterior->getProximo();
	}
	Elemento<T>* eliminar = anterior->getProximo();
    T volta = eliminar->getInfo();
	anterior->setProximo(eliminar->getProximo());
	tamanho--;
	delete eliminar;
	return volta;
}

template <typename T>
T ListaEnc<T>::retiraDoInicio() {
	Elemento<T>* saiu;
	T volta;
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	saiu = cabeca;
	volta = saiu->getInfo();
	cabeca = saiu->getProximo();
	tamanho--;
	delete saiu;
	return volta;
}

template <typename T>
bool ListaEnc<T>::contem(const T& dado) {
    if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	Elemento<T>* atual = cabeca;
	for (int i = 0; i < tamanho; i++) {
		if (igual(dado, atual->getInfo())) {
			return true;
		}
		atual = atual->getProximo();
	}
    return false;
}

template <typename T>
int ListaEnc<T>::posicao(const T& dado) const {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	Elemento<T>* atual = cabeca;
	for (int i = 0; i < tamanho; i++) {
		if (dado == atual->getInfo()) {
			return i;
		}
		atual = atual->getProximo();
	}
	throw ExcecaoDadoNaoEncontrado();
}

template <typename T>
T* ListaEnc<T>::posicaoMem(const T& dado) const {
    if (listaVazia()) {
        throw ExcecaoListaVazia();
    }
    int posicao = posicao(dado);
    Elemento<T>* atual = cabeca;
    for (int i = 0; i < posicao; i++) {
        atual = atual->getProximo();
    }
    return atual->getInfo();
}

template <typename T>
void ListaEnc<T>::destroiLista() {
	Elemento<T>* atual;
	while (cabeca) {
		atual = cabeca;
		cabeca = cabeca->getProximo();
		delete atual;
	}
	tamanho = 0;
}

template <typename T>
bool ListaEnc<T>::listaVazia() const {
	return tamanho == 0;
}

template <typename T>
bool ListaEnc<T>::igual(T dado1, T dado2) {
	return dado1 == dado2;
}

template <typename T>
bool ListaEnc<T>::maior(T dado1, T dado2) {
	return dado2 < dado1;
}

template <typename T>
bool ListaEnc<T>::menor(T dado1, T dado2) {
	return dado1 < dado2;
}

template <typename T>
bool ListaEnc<T>::posicaoInvalida(int p) {
	return (p >= tamanho + 1 || p < 0);
}

#endif
