//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a fila.
/*! Classe que trata das operações relacionadas a filas.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 28/08/14
*	\version 1.0
*/

#ifndef FILA_HPP_
#define FILA_HPP_
#include "EstruturaLinear.hpp"

template<typename T>
class Fila : EstruturaLinear<T> {
 public:
    //! Construtor.
    /*! Construtor básico para a classe, sem parâmetros. */
    Fila();

    //! Construtor com parâmetros.
    /*! Construtor que permite a variabilidade de tamanho
    	da fila.
    * \param t o número máximo de elementos no vetor.
    * \sa Fila()
    */
	Fila<T>(int t);

	//! Método para adicionar dados à fila.
	/*!
	* \param dado um objeto genérico que representa o dado a ser adicionado no vetor.
	* \sa retira(), limparFila()
	*/
	void inclui(T dado);

	//! Método para retirar dados da fila.
	/*!
	* \return um objeto genérico que era o primeiro da fila.
	* \sa retira(), limparFila()
	*/
	T retira();

	//! Método que identifica o último elemento da fila.
	/*! 
	* \return um objeto genérico.
	* \sa getUltimo()
	*/
	T ultimo();

	//! Método que identifica a posição do último elemento da fila.
	/*!
	* \return um inteiro.
	* \sa ultimo()
	*/
	int getUltimo();

	//! Método que limpa a fila de quaisquer elementos.
	/*!
	* \sa inclui(), retira()
	*/
	void limparFila();

	//! Método que mostra se a fila está vazia.
	/*!
	* \return um boolean.
	* \sa filaCheia()
	*/
	bool filaVazia();

	//! Método que mostra se a fila está cheia.
	/*!
	* \return um boolean.
	* \sa filaVazia()
	*/
	bool filaCheia();

	//! Método que inicializa a fila sem elementos.
	/*!
	* \sa limparFila()
	*/
	void inicializaFila();
};

template<typename T>
Fila<T>::Fila() : EstruturaLinear<T>() {
}

template<typename T>
Fila<T>::Fila(int t) : EstruturaLinear<T>(t) {
}

template<typename T>
void Fila<T>::inclui(T dado) {
	this->adicionaDado(dado);
}

template<typename T>
T Fila<T>::retira() {
	if(this->estruturaLinearVazia()) {
		throw ExcecaoEstruturaVazia();
	}
	T dado = this->estrutura[0];
	this->fim--;
	for (int i = 0; i < this->fim+1; i++) {
		this->estrutura[i] = this->estrutura[i+1];
	}
	return dado;
}

template<typename T>
T Fila<T>::ultimo() {
	return this->final();
}

template<typename T>
int Fila<T>::getUltimo() {
	return this->getPosFinal();
}

template<typename T>
void Fila<T>::limparFila() {
	this->limparEstruturaLinear();
}

template<typename T>
bool Fila<T>::filaVazia() {
    return this->estruturaLinearVazia();
}

template<typename T>
bool Fila<T>::filaCheia() {
	return this->estruturaLinearCheia();
}

template<typename T>
void Fila<T>::inicializaFila() {
	this->fim = -1;
}

#endif
