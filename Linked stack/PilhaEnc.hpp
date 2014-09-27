#ifndef PILHAENC_HPP_
#define PILHAENC_HPP_
#include "ListaEnc.hpp"
#include "ExcecaoListaVazia.h"

template<typename T>
class PilhaEnc : private ListaEnc<T> {
 public:
	PilhaEnc();
	~PilhaEnc();
	void empilha(const T& dado);
	T desempilha();
    T topo();
    void limparPilha();
    bool PilhaVazia();
};

template<typename T>
PilhaEnc<T>::PilhaEnc() : ListaEnc<T>() {
}

template<typename T>
PilhaEnc<T>::~PilhaEnc() {
	ListaEnc<T>::~ListaEnc();
}

template<typename T>
void PilhaEnc<T>::empilha(const T& dado) {
	this->adicionaNoInicio(dado);
}

template<typename T>
T PilhaEnc<T>::desempilha() {
	return this->retiraDoInicio();
}

template<typename T>
T PilhaEnc<T>::topo() {
	if (PilhaVazia()) {
		throw ExcecaoListaVazia();
	}
	return this->cabeca->getInfo();
}

template<typename T>
void PilhaEnc<T>::limparPilha() {
	this->destroiLista();
}

template<typename T>
bool PilhaEnc<T>::PilhaVazia() {
	return this->listaVazia();
}

#endif
