#ifndef FILAENC_HPP_
#define FILAENC_HPP_
#include "ListaEnc.hpp"
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"

template <typename T>
class FilaEnc : ListaEnc<T> {
 private:
    Elemento<T>* fim;

 public:
    FilaEnc<T>();
    ~FilaEnc();
    void inclui(const T& dado);
    T retira();
    T ultimo();
    T primeiro();
    bool filaVazia();
    void limparFila();
};

template<typename T>
FilaEnc<T>::FilaEnc() : ListaEnc<T>() {
    fim = 0;
}

template<typename T>
FilaEnc<T>::~FilaEnc() {
    ListaEnc<T>::~ListaEnc();
}

template<typename T>
void FilaEnc<T>::inclui(const T& dado) {
	Elemento<T>* novo = new Elemento<T>(dado, 0);
	if(novo == 0) {
		throw ExcecaoListaCheia();
	}
	if(filaVazia()) {
		this->cabeca = novo;
	} else {
		fim->setProximo(novo);
	}
	novo->setProximo(0);
	fim = novo;
	this->tamanho++;
}

template<typename T>
T FilaEnc<T>::retira() {
	if (filaVazia()) {
		throw ExcecaoListaVazia();
	}
	Elemento<T>* sai = this->cabeca;
	T volta = sai->getInfo();
	this->cabeca = sai->getProximo();
	if(this->tamanho == 1) {
		fim = 0;
	}
	this->tamanho--;
	delete sai;
	return volta;
}

template<typename T>
T FilaEnc<T>::ultimo() {
    if (filaVazia()) {
		throw ExcecaoListaVazia();
	}
	return fim->getInfo();
}

template<typename T>
T FilaEnc<T>::primeiro() {
	if (filaVazia()) {
		throw ExcecaoListaVazia();
	}
	return this->cabeca->getInfo();
}

template<typename T>
void FilaEnc<T>::limparFila() {
    this->destroiLista();
}

template<typename T>
bool FilaEnc<T>::filaVazia() {
	return this->listaVazia();
}

#endif
