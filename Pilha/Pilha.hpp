//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a pilha.
/*! Classe que trata das operações relacionadas a pilhas.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 28/08/14
*	\version 1.0
*/

#ifndef PILHA_HPP_
#define PILHA_HPP_
#include "EstruturaLinear.hpp"

template<typename T>
class Pilha : EstruturaLinear<T> {
 public:
    //! Construtor.
    /*! Construtor básico para a classe, sem parâmetros. */
    Pilha();

    //! Construtor com parâmetros.
    /*! Construtor que permite a variabilidade de tamanho
    	da pilha.
    * \param t o número máximo de elementos no vetor.
    * \sa Pilha()
    */
	explicit Pilha(int t);

	//! Método para adicionar dados à pilha.
	/*!
	* \param dado um objeto genérico que representa o dado a ser adicionado no vetor.
	* \sa desempilha(), limparPilha()
	*/
	void empilha(T dado);

	//! Método para retirar dados da pilha.
	/*!
	* \return um objeto genérico que era o topo da pilha.
	* \sa empilha(), limparPilha()
	*/
	T desempilha();

	//! Método que identifica o último elemento da pilha.
	/*! 
	* \return um objeto genérico.
	* \sa getPosTopo()
	*/
	T topo();

	//! Método que identifica a posição do último elemento da pilha.
	/*!
	* \return um inteiro.
	* \sa topo()
	*/
	int getPosTopo();

	//! Método que limpa a pilha de quaisquer elementos.
	/*!
	* \sa empilha(), desempilha()
	*/
	void limparPilha();

	//! Método que mostra se a pilha está vazia.
	/*!
	* \return um boolean.
	* \sa pilhaCheia()
	*/
	bool PilhaVazia();

	//! Método que mostra se a pilha está cheia.
	/*!
	* \return um boolean.
	* \sa pilhaVazia()
	*/
	bool PilhaCheia();
};

template<typename T>
Pilha<T>::Pilha() : EstruturaLinear<T>() {
}

template<typename T>
Pilha<T>::Pilha(int t) : EstruturaLinear<T>(t) {
}

template<typename T>
void Pilha<T>::empilha(T dado) {
	this->adicionaDado(dado);
}

template<typename T>
T Pilha<T>::desempilha() {
	return this->retiraDado();
}

template<typename T>
T Pilha<T>::topo() {
	return this->final();
}

template<typename T>
int Pilha<T>::getPosTopo() {
	return this->getPosFinal();
}

template<typename T>
void Pilha<T>::limparPilha() {
	this->limparEstruturaLinear();
}

template<typename T>
bool Pilha<T>::PilhaCheia() {
	return this->estruturaLinearCheia();
}

template<typename T>
bool Pilha<T>::PilhaVazia() {
    return this->estruturaLinearVazia();
}

#endif
