//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe geral de estruturas lineares.
/*! Classe pai das estruturas básicas de fila e pilha, 
* 	que trata as operações básicas comuns às estruturas.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 28/08/14
*	\version 1.0
*/

#ifndef ESTRUTURALINEAR_HPP_
#define ESTRUTURALINEAR_HPP_
#define MAX 100
#include "ExcecaoEstruturaCheia.h"
#include "ExcecaoEstruturaVazia.h"

template <typename T>
class EstruturaLinear {
 protected:
    //! Vetor básico.
    /*! Vetor usado para armazenar os dados da estrutura linear. */
    T *estrutura;

    //! Identificador de posição.
    /*! Posição do último elemento da estrutura linear. */
	int fim;

	//! Identificador de tamanho.
	/*! Tamanho da estrutura linear. */
	int tamanho;

 public:
    //! Construtor.
    /*! Construtor básico para a classe, sem parâmetros. */
    EstruturaLinear();

    //! Construtor com parâmetros.
    /*! Construtor que permite a variabilidade de tamanho
    	da estrutura linear.
    * \param t o número máximo de elementos no vetor.
    * \sa EstruturaLinear()
    */
    EstruturaLinear(int t);

    //! Método para adicionar dados à estrutura.
    /*! 
	* \param dado um objeto genérico que representa o dado a ser adicionado no vetor.
	* \sa retiraDado(), limparEstruturaLinear()
    */
	void adicionaDado(T dado);

	//! Método para retirar dados da estrutura.
	/*!
	* \return um objeto genérico que era o final da estrutura.
	* \sa adicionaDado(), limparEstruturaLinear()
	*/
	T retiraDado();

	//! Método que identifica o último elemento da estrutura.
	/*! 
	* \return um objeto genérico.
	* \sa getPosFinal()
	*/
	T final();

	//! Método que identifica a posição do último elemento da estrutura.
	/*!
	* \return um inteiro.
	* \sa final()
	*/
	int getPosFinal();

	//! Método que limpa a estrutura linear.
	/*!
	* \sa adicionaDado(), retiraDado()
	*/ 
	void limparEstruturaLinear();

	//! Método que mostra se a estrutura linear está vazia.
	/*!
	* \return um boolean.
	* \sa estruturaLinearCheia()
	*/
	bool estruturaLinearVazia();

	//! Método que mostra se a estrutura linear está cheia.
	/*!
	* \return um boolean.
	* \sa estruturaLinearVazia()
	*/
	bool estruturaLinearCheia();
};

template <typename T>
EstruturaLinear<T>::EstruturaLinear() {
    fim = -1;
    estrutura = new T[MAX];
    tamanho = MAX;
}

template <typename T>
EstruturaLinear<T>::EstruturaLinear(int t) {
	fim = -1;
	estrutura = new T[t];
	tamanho = t;
}

template <typename T>
void EstruturaLinear<T>::adicionaDado(T dado) {
	if (estruturaLinearCheia()) {
		throw ExcecaoEstruturaCheia();
	}
	fim++;
	estrutura[fim] = dado;
}

template <typename T>
T EstruturaLinear<T>::retiraDado() {
	if (estruturaLinearVazia()) {
		throw ExcecaoEstruturaVazia();
	}
	fim--;
	return estrutura[fim + 1];
}

template<typename T>
T EstruturaLinear<T>::final() {
	if (estruturaLinearVazia()) {
		throw ExcecaoEstruturaVazia();
	}
	return estrutura[fim];
}

template <typename T>
int EstruturaLinear<T>::getPosFinal() {
    if (estruturaLinearVazia()) {
		throw ExcecaoEstruturaVazia();
	}
    return fim;
}

template <typename T>
void EstruturaLinear<T>::limparEstruturaLinear() {
    if (estruturaLinearVazia()) {
		throw ExcecaoEstruturaVazia();
	}
	fim = -1;
}

template <typename T>
bool EstruturaLinear<T>::estruturaLinearVazia() {
	return (fim == -1);
}

template <typename T>
bool EstruturaLinear<T>::estruturaLinearCheia() {
	return (fim == tamanho - 1);
}

#endif
