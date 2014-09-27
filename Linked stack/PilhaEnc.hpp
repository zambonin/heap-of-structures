//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a pilha encadeada.
/*! Classe que trata das operações relacionadas a pilhas encadeadas. 
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 27/09/14
*	\version 1.0
*/

#ifndef PILHAENC_HPP_
#define PILHAENC_HPP_
#include "ListaEnc.hpp"
#include "ExcecaoListaVazia.h"

template<typename T>
class PilhaEnc : private ListaEnc<T> {
 public:
	//! Construtor.
	/*! Construtor para a classe, sem parâmetros. Herdado da classe-pai. */
	PilhaEnc();

	//! Destrutor.
	/*! Destrutor herdado da classe-pai, que deleta todos os elementos. */
	~PilhaEnc();

	//! Método para adicionar um dado à pilha encadeada.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa desempilha()
	*/
	void empilha(const T& dado);

	//! Método para retirar o último dado da pilha encadeada.
	/*!
	* \return um objeto genérico que era o último da pilha encadeada.
	* \sa empilha()
	*/
	T desempilha();

	//! Método de identificação do último elemento da pilha encadeada.
	/*!
	* \return o último objeto adicionado à pilha encadeada.
	*/
    T topo();

    //! Método para eliminar iterativamente cada elemento da pilha encadeada.
    /*!
    * \sa ~PilhaEnc()
    */	
    void limparPilha();

    //! Método que mostra se a pilha está vazia.
	/*!
	* \return um boolean.
	*/
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
