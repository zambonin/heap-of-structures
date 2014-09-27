#ifndef LISTADUPLA_HPP_
#define LISTADUPLA_HPP_
#include "ElementoDuplo.hpp"
#include "ExcecaoDadoNaoEncontrado.h"
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"
#include "ExcecaoPosicao.h"

template<typename T>
class ListaDupla {
 private:
    ElementoDuplo<T>* cabeca;
    int tamanho;

 public:
	ListaDupla();
    ~ListaDupla();
    void adicionaNoInicioDuplo(const T& dado);
    T retiraDoInicioDuplo();
    void eliminaDoInicioDuplo();
    void adicionaNaPosicaoDuplo(const T& dado, int pos);
    int posicaoDuplo(const T& dado) const;
    T* posicaoMemDuplo(const T& dado) const;
    bool contemDuplo(const T& dado);
    T retiraDaPosicaoDuplo(int pos);
    void adicionaDuplo(const T& dado);
    T retiraDuplo();
    T retiraEspecificoDuplo(const T& dado);
    T mostra(int pos);
    void adicionaEmOrdem(const T& data);
    int verUltimo();
    bool listaVazia() const;
	bool igual(T dado1, T dado2);
	bool maior(T dado1, T dado2);
    bool menor(T dado1, T dado2);
	void destroiListaDuplo();
	bool posicaoInvalida(int p);
};

template<typename T>
ListaDupla<T>::ListaDupla() {
	cabeca = 0;
	tamanho = 0;
}

template<typename T>
ListaDupla<T>::~ListaDupla() {
	delete cabeca;
}

template<typename T>
void ListaDupla<T>::adicionaNoInicioDuplo(const T& dado) {
	ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, 0, 0);
	if (novo == 0) {
		throw ExcecaoListaCheia();
	}
	novo->setProximo(cabeca);
	novo->setAnterior(0);
	cabeca = novo;
	if(novo->getProximo() != 0) {
		novo->getProximo()->setAnterior(novo);
	}
	tamanho++;
}

template<typename T>
T ListaDupla<T>::retiraDoInicioDuplo() {
	ElementoDuplo<T>* saiu;
	T volta;
	if (listaVazia()) {
		throw ExcecaoPosicao();
	}
	saiu = cabeca;
	volta = saiu->getInfo();
	cabeca = saiu->getProximo();
	if(cabeca != 0) {
		cabeca->setAnterior(0);
	}
	tamanho--;
	delete saiu;
	return volta;
}

template<typename T>
void ListaDupla<T>::eliminaDoInicioDuplo() {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	ElementoDuplo<T>* saiu = cabeca;
	cabeca = saiu->getProximo();
	cabeca->setAnterior(0);
	tamanho--;
	delete saiu;
}

template<typename T>
void ListaDupla<T>::adicionaNaPosicaoDuplo(const T& dado, int pos) {
	if (posicaoInvalida(pos)) {
		throw ExcecaoPosicao();
	}
	if (pos == 0) {
		adicionaNoInicioDuplo(dado);
		return;
	}
	ElementoDuplo<T>* anterior = cabeca;
	ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, 0, 0);
	if (novo == 0) {
		throw ExcecaoListaCheia();
	}
	for (int i = 0; i < pos - 1; i++) {
		anterior = anterior->getProximo();
	}
	novo->setProximo(anterior->getProximo());
	if(novo->getProximo() != 0) {
		novo->getProximo()->setAnterior(novo);
	}
	anterior->setProximo(novo);
	anterior->getProximo()->setAnterior(anterior);
	tamanho++;
}

template<typename T>
int ListaDupla<T>::posicaoDuplo(const T& dado) const {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	ElementoDuplo<T>* atual = cabeca;
	for (int i = 0; i < tamanho; i++) {
		if (dado == atual->getInfo()) {
			return i;
		}
		atual = atual->getProximo();
	}
	throw ExcecaoDadoNaoEncontrado();
}

template<typename T>
T* ListaDupla<T>::posicaoMemDuplo(const T& dado) const {
	 if (listaVazia()) {
        throw ExcecaoListaVazia();
    }
    int posicao = posicaoDuplo(dado);
    ElementoDuplo<T>* atual = cabeca;
    for (int i = 1; i < posicao; i++) {
        atual = atual->getProximo();
    }
    return atual->getInfo();
}

template<typename T>
bool ListaDupla<T>::contemDuplo(const T& dado) {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	ElementoDuplo<T>* atual = cabeca;
	for (int i = 0; i < tamanho; i++) {
		if (igual(dado, atual->getInfo())) {
			return true;
		}
		atual = atual->getProximo();
	}
    return false;
}

template<typename T>
T ListaDupla<T>::retiraDaPosicaoDuplo(int pos) {
	if (posicaoInvalida(pos)) {
		throw ExcecaoPosicao();
	}
	if (pos == 0) {
		return retiraDoInicioDuplo();
	}
	ElementoDuplo<T>* anterior = cabeca;
	for (int i = 0; i < pos - 2; i++) {
		anterior = anterior->getProximo();
	}
	ElementoDuplo<T>* eliminar = anterior->getProximo();
    T volta = eliminar->getInfo();
	anterior->setProximo(eliminar->getProximo());
	if(eliminar->getProximo() != 0) {
		eliminar->getProximo()->setAnterior(anterior);
	}
	tamanho--;
	delete eliminar;
	return volta;
}

template<typename T>
void ListaDupla<T>::adicionaDuplo(const T& dado) {
	this->adicionaNaPosicaoDuplo(dado, tamanho);
}

template<typename T>
T ListaDupla<T>::retiraDuplo() {
	return this->retiraDaPosicaoDuplo(tamanho);
}

template<typename T>
T ListaDupla<T>::retiraEspecificoDuplo(const T& dado) {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
    return this->retiraDaPosicaoDuplo(posicaoDuplo(dado) + 1);
}

template<typename T>
T ListaDupla<T>::mostra(int pos) {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	ElementoDuplo<T>* mostra = cabeca;
	for (int i = 0; i < tamanho - 1; i++) {
		mostra = mostra->getProximo();
	}
	return mostra->getInfo();
}

template<typename T>
void ListaDupla<T>::adicionaEmOrdem(const T& data) {
	if (listaVazia()) {
		return adicionaNoInicioDuplo(data);
	}
	ElementoDuplo<T>* atual = cabeca;
	int posicao = 1;
	while (atual->getProximo() != 0 && maior(data, atual->getInfo())) {
		atual = atual->getProximo();
		posicao++;
	}
	if (maior(data, atual->getInfo())) {
		return adicionaNaPosicaoDuplo(data, posicao + 1);
	}
	adicionaNaPosicaoDuplo(data, posicao);
}

template<typename T>
int ListaDupla<T>::verUltimo() {
	return tamanho;
}

template<typename T>
bool ListaDupla<T>::listaVazia() const {
	return tamanho == 0;
}

template<typename T>
bool ListaDupla<T>::igual(T dado1, T dado2) {
	return dado1 == dado2;
}

template<typename T>
bool ListaDupla<T>::maior(T dado1, T dado2) {
	return dado1 > dado2;
}

template<typename T>
bool ListaDupla<T>::menor(T dado1, T dado2) {
	return dado1 < dado2;
}

template<typename T>
void ListaDupla<T>::destroiListaDuplo() {
	ElementoDuplo<T>* atual;
	while (cabeca) {
		atual = cabeca;
		cabeca = cabeca->getProximo();
		delete atual;
	}
	tamanho = 0;
}

template <typename T>
bool ListaDupla<T>::posicaoInvalida(int p) {
	return (p >= tamanho + 1 || p < 0);
}

#endif
