//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a fila encadeada.
/*! Classe que trata das operações relacionadas a filas encadeadas. 
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 27/09/14
*	\version 1.0
*/

#ifndef FILAENC_HPP_
#define FILAENC_HPP_
#include "ListaEnc.hpp"
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"

template <typename T>
class FilaEnc : private ListaEnc<T> {
 private:
    //! Fim da fila encadeada.
    /*! Ponteiro que aponta para o último elemento da fila encadeada. */
    Elemento<T>* fim;

 public:
    //! Construtor.
	/*! Construtor para a classe, sem parâmetros. Herdado da classe-pai. */
    FilaEnc();

    //! Destrutor.
	/*! Destrutor herdado da classe-pai, que deleta todos os elementos. */
    ~FilaEnc();

    //! Método para adicionar um dado à fila encadeada.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa retira()
	*/
    void inclui(const T& dado);

    //! Método para retirar o último dado da fila encadeada.
	/*!
	* \return um objeto genérico que era o último da fila encadeada.
	* \sa inclui()
	*/
    T retira();

    //! Método de identificação do último elemento da fila encadeada.
	/*!
	* \return o último objeto adicionado à fila encadeada.
	* \sa primeiro()
	*/
    T ultimo();

    //! Método de identificação do primeiro elemento da fila encadeada.
	/*!
	* \return o primeiro objeto adicionado à fila encadeada.
	* \sa ultimo()
	*/
    T primeiro();

    //! Método que mostra se a fila está vazia.
	/*!
	* \return um boolean.
	*/
    bool filaVazia();

    //! Método para eliminar iterativamente cada elemento da fila encadeada.
    /*!
    * \sa ~FilaEnc()
    */
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
	if (novo == 0) {
		throw ExcecaoListaCheia();
	}
	if (filaVazia()) {
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
	if (this->tamanho == 1) {
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
