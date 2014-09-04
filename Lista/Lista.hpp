//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista.
/*! Classe que trata das operações relacionadas a listas.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 03/09/14
*	\version 1.0
*/

#ifndef LISTA_HPP_
#define LISTA_HPP_
#define MAX 100
#include "ExcecaoListaVazia.h"
#include "ExcecaoListaCheia.h"
#include "ExcecaoDadoNaoEncontrado.h"
#include "ExcecaoPosicao.h"

template <typename T>
class Lista {
 protected:
 	//! Vetor básico.
 	/*! Vetor usado para armazenar os dados da lista. */
 	T* lista;

 	//! Identificador de posição.
 	/*! Posição do último elemento da lista. */
 	int ultimo;

 	//! Identificador de tamanho.
 	/*! Tamanho da lista. */
 	int tamanho;

 	// POR QUE O ADICIONA RETORNA UM TIPO GENÉRICO????? que doença wtf

 public:
 	//! Construtor.
    /*! Construtor básico para a classe, sem parâmetros. */
 	Lista();

 	//! Construtor com parâmetros.
 	/*! Construtor que permite a variabilidade de tamanho da lista. 
 	* \param t o número máximo de elementos no vetor.
 	* \sa Lista()
 	*/
 	explicit Lista(int t);

 	//! Método para adicionar dados à lista.
 	/*!
 	* \param dado um objeto genérico que representa o dado a ser adicionado.
 	* \sa adicionaNoInicio(), adicionaNaPosicao(), adicionaEmOrdem(),
 	* retira(), retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
 	*/
 	T adiciona(T dado);

 	//! Método para adicionar um dado diretamente no início da lista.
 	/*!
 	* \param dado um objeto genérico que representa o dado a ser adicionado.
 	* \sa adiciona(), adicionaNaPosicao(), adicionaEmOrdem(), retira(),
 	* retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
 	*/
 	T adicionaNoInicio(T dado);

 	//! Método para adicionar um dado em uma posição específica.
 	/*!
 	* \param dado um objeto genérico que representa o dado a ser adicionado.
 	* \param posicao a posição desejada na forma de número inteiro.
 	* \sa adiciona(), adicionaNoInicio(), adicionaEmOrdem(), retira(),
 	* retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
 	*/
 	T adicionaNaPosicao(T dado, int posicao);

 	//! no fucking idea
 	T adicionaEmOrdem(T dado); //precisa do professor

 	//! Método para retirar dados da lista.
 	/*! 
 	* \return um objeto genérico que era o último da lista.
 	* \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), 
 	* adicionaEmOrdem(), retiraDoInicio(), retiraDaPosicao(), 
 	* retiraEspecifico()
 	*/
 	T retira();

 	//! Método para retirar o primeiro dado da lista.
 	/*!
 	* \return um objeto genérico que era o primeiro da lista.
	* \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), 
 	* adicionaEmOrdem(), retira(), retiraDaPosicao(), retiraEspecifico()
 	*/
 	T retiraDoInicio();

 	//! Método para retirar um dado em uma posição específica.
 	/*!
 	* \param posicao a posição desejada na forma de número inteiro.
 	* \return um objeto genérico que tinha como índice a posição indicada.
 	* \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), 
 	* adicionaEmOrdem(), retiraDoInicio(), retiraEspecifico()
 	*/
 	T retiraDaPosicao(int posicao);

 	//! Método para retirar um dado específico.
 	/*!
 	* \param dado o dado a ser informado para comparação no vetor.
 	* \return o dado encontrado no vetor de acordo com a comparação.
 	* \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), 
 	* adicionaEmOrdem(), retiraDoInicio(), retiraDaPosicao(), 
 	*/
 	T retiraEspecifico(T dado);

 	//! Método que mostra se a lista está cheia.
	/*!
	* \return um boolean.
	* \sa listaVazia()
	*/
 	bool listaCheia();

 	//! Método que mostra se a lista está vazia.
	/*!
	* \return um boolean.
	* \sa listaCheia()
	*/
 	bool listaVazia();

 	//! Método para identificar a posição de um dado específico no vetor.
 	/*!
 	* \param dado o dado a ser informado para comparação no vetor.
 	* \return a posição do dado indicado.
 	* \sa contem()
 	*/
 	int posicao(T dado);

 	//! Método para identificar a presença de um dado específico no vetor.r
 	/*!
 	* \param dado o dado a ser informado para comparação no vetor.
 	* \return um boolean.
 	* \sa posicao()
 	*/
 	bool contem(T dado);

 	bool maior(T* dado1, T* dado2); //same
 	bool menor(T* dado1, T* dado2); //same
 	bool igual(T* dado1, T* dado2); //same

 	//! Método para checagem de posição inválida solicitada no vetor.
 	/*!
 	* \param p a posição a ser validada.
 	* \return um boolean.
 	* \sa posicao()
 	*/
 	bool posicaoInvalida(int p);

 	//! Método que inicializa a lista sem elementos.
	/*!
	* \sa destroiLista()
	*/
 	void inicializaLista();

 	//! Método que destrói a lista.
 	/*!
 	* \sa inicializaLista()
 	*/
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
	return adicionaNaPosicao(dado, ultimo + 1);
}

template <typename T>
T Lista<T>::adicionaNoInicio(T dado) {
	return adicionaNaPosicao(dado, 0);
}

template <typename T>
T Lista<T>::adicionaNaPosicao(T dado, int posicao) {
	if (listaCheia()) {
		throw ExcecaoListaCheia();
	}
	if (posicaoInvalida(posicao)) {
		throw ExcecaoPosicao();
	}
	ultimo++;
	for (int i = ultimo; i > posicao; i--) {
		lista[i] = lista[i - 1];
	}
	lista[posicao] = dado;
	return dado;
}

template <typename T>
T Lista<T>::adicionaEmOrdem(T dado) {
	if(listaVazia()){
		throw ExcecaoListaVazia();
	}
	if (listaCheia()) {
		throw ExcecaoListaCheia();
	}
	int posicao = 0;
	while((posicao <= ultimo) && (maior(&dado, &lista[posicao]))){
		posicao++;
	}
	return adicionaNaPosicao(dado, posicao);
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
	if (posicaoInvalida(posicao)) {
		throw ExcecaoPosicao();
	}
	ultimo--;
	T dado = lista[posicao];
	for (int i = posicao; i <= ultimo; i++) {
		lista[posicao] = lista[posicao + 1];
	}
	return dado;
}

template <typename T>
T Lista<T>::retiraEspecifico(T dado) {
	if(listaVazia()) {
		throw ExcecaoListaVazia();
	}
	return retiraDaPosicao(posicao(dado));
}

template <typename T>
bool Lista<T>::listaCheia() {
	return (ultimo == tamanho - 1);
}

template <typename T>
bool Lista<T>::listaVazia() {
	return (ultimo == -1);
}

template <typename T>
int Lista<T>::posicao(T dado) {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	for (int i = 0; i <= ultimo; i++) {
		if (igual(&dado, &lista[i])) {
			return i;
		}
	}
	throw ExcecaoDadoNaoEncontrado();
}

template <typename T>
bool Lista<T>::contem(T dado) {
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	for (int i = 0; i <= ultimo; i++) {
		if (igual(&dado, &lista[i])) {
			return true;
		}
	}
	return false;
}

template <typename T>
bool Lista<T>::posicaoInvalida(int p) {
	return !(p <= ultimo + 1 && p >= 0);
}

template <typename T>
void Lista<T>::inicializaLista() {
	ultimo = -1;
}

template <typename T>
void Lista<T>::destroiLista() {
	ultimo = -1;
}

template <typename T>
bool Lista<T>::maior(T* dado1, T* dado2){
	return *dado2 < *dado1;	
}

template <typename T>
bool Lista<T>::igual(T* dado1, T* dado2){
	return *dado1 == *dado2;
}

template <typename T>
bool Lista<T>::menor(T* dado1, T* dado2) {
	return *dado1 < *dado2;
}


#endif
