//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista encadeada.
/*! Classe que trata das operações relacionadas a listas encadeadas. 
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 14/09/14
*	\version 1.0
*/

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
    //! Cabeça da lista encadeada.
    /*! Elemento que descreve o primeiro nó da lista encadeada. */
	Elemento<T>* cabeca;

	//! Identificador de tamanho.
	 /*! Tamanho da lista encadeada. */
	int tamanho;

 public:
    //! Construtor.
    /*! Construtor básico para a classe, sem parâmetros. */
	ListaEnc();

	//! Destrutor.
	/*! Destrutor que deleta todos os nós. */
	~ListaEnc();

	//! Método para adicionar um dado diretamente no fim da lista encadeada.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa adicionaEmOrdem(), adicionaNaPosicao(), adicionaNoInicio(),
	* eliminaDoInicio(), retira(), retiraEspecifico(), retiraDaPosicao(),
	* retiraDoInicio()
	*/
	void adiciona(const T& dado);

	//! Método para adicionar um dado em uma posição específica
	//! de acordo com a ordem inerente da classe.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa adiciona(), adicionaNaPosicao(), adicionaNoInicio(),
	* eliminaDoInicio(), retira(), retiraEspecifico(), retiraDaPosicao(),
	* retiraDoInicio()
	*/
	void adicionaEmOrdem(const T& dado);

	//! Método para adicionar um dado em uma posição específica.
	/*!
 	* \param dado o endereço do objeto genérico a ser adicionado.
	* \param pos a posição desejada na forma de número inteiro.
	* \sa adiciona(), adicionaEmOrdem(), adicionaNoInicio(), retira(),
	* retiraDaPosicao(), retiraDoInicio(), retiraEspecifico()
	*/
	void adicionaNaPosicao(const T& dado, int pos);

	//! Método para adicionar um dado diretamente no início da lista encadeada.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), retira(),
	* retiraDaPosicao(), retiraDoInicio(), retiraEspecifico()
	*/
	void adicionaNoInicio(const T& dado);

	//! Método para eliminar o primeiro nó da lista encadeada.
	/*!
	* \param dado o endereço do objeto genérico a ser adicionado.
	* \sa ~ListaEnc()
	*/
	void eliminaDoInicio();

	//! Método para retirar dados da lista encadeada.
	/*!
	* \return um objeto genérico que era o último da lista.
	* \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), adicionaNoInicio()
	* retiraDaPosicao(), retiraDoInicio(), retiraEspecifico()
	*/
	T retira();

	//! Método para retirar um dado em uma posição específica.
 	/*!
 	* \param pos a posição desejada na forma de número inteiro.
 	* \return um objeto genérico que tinha como índice a posição indicada.
 	* \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), 
 	* adicionaNoInicio(), retira(), retiraDoInicio(), retiraEspecifico()
 	*/
	T retiraDaPosicao(int pos);

	//! Método para retirar o primeiro dado da lista.
 	/*!
 	* \return um objeto genérico que era o primeiro da lista.
	* \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), 
 	* adicionaNoInicio(), retira(), retiraDaPosicao(), retiraEspecifico()
 	*/
	T retiraDoInicio();

	//! Método para retirar um dado específico.
 	/*!
 	* \param dado o endereço do objeto genérico a ser adicionado.
 	* \return o dado encontrado no vetor de acordo com a comparação.
 	* \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), 
 	* adicionaEmOrdem(), retira(), retiraDaPosicao(), retiraDoInicio()
 	*/
	T retiraEspecifico(const T& dado);

	//! Método para identificar a presença de um dado
	//! específico na lista encadeada.
 	/*!
 	* \param dado o endereço do objeto genérico a ser comparado.
 	* \return um boolean.
 	* \sa posicao(), posicaoMem()
 	*/
	bool contem(const T& dado);

	//! Método para identificar a presença de um dado
	//! específico na lista encadeada.
 	/*!
 	* \param dado o endereço do objeto genérico a ser comparado.
 	* \return um boolean.
 	* \sa contem(), posicaoMem()
 	*/
	int posicao(const T& dado) const;

	//! Método para retornar a posição na memória de um dado
	//! especfico na lista encadeada.
	/*!
	* \param dado o endereço do objeto genérico a ser comparado.
	* \return um ponteiro relacionado ao dado específico.
	* \sa contem(), posicao()
	*/
	T* posicaoMem(const T& dado) const;

	//! Método para eliminar iterativamente cada elemento da lista encadeada.
	/*!
	* \sa ~ListaEnc()
	*/
	void destroiLista();

	//! Método que mostra se a lista está vazia.
	/*!
	* \return um boolean.
	* \sa listaCheia()
	*/
	bool listaVazia() const;

	//! Método de comparação de igualdade entre dois dados.
    /*!
	* /param dado1 o primeiro dado a ser comparado.
	* /param dado2 o segundo dado a ser comparado.
	* \sa maior(), menor()
	*/
    bool igual(T dado1, T dado2);

    //! Método de comparação de maioridade (de acordo com um critério
    //! estabelecido pela classe) entre dois dados.
    /*!
    * /param dado1 o primeiro dado a ser comparado.
    * /param dado2 o segundo dado a ser comparado.
    * \sa igual(), menor()
    */
	bool maior(T dado1, T dado2);

    //! Método de comparação de minoridade (de acordo com um critério
    //! estabelecido pela classe) entre dois dados.
	/*!
	* /param dado1 o primeiro dado a ser comparado.
	* /param dado2 o segundo dado a ser comparado.
	* \sa igual(), maior()
	*/
	bool menor(T dado1, T dado2);

	 //! Método para checagem de posição inválida solicitada no vetor.
 	/*!
 	* \param p a posição a ser validada.
 	* \return um boolean.
 	* \sa posicao(), posicaoMem()
 	*/
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
		return adicionaNoInicio(dado);
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
	if (listaVazia()) {
		throw ExcecaoListaVazia();
	}
	Elemento<T>* saiu = cabeca;
	T volta = saiu->getInfo();
	cabeca = saiu->getProximo();
	tamanho--;
	delete saiu;
	return volta;
}

template <typename T>
T ListaEnc<T>::retiraEspecifico(const T& dado) {
	if(listaVazia()) {
		throw ExcecaoListaVazia();
	}
	return retiraDaPosicao(posicao(dado) + 1);
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
	for (int i = 0; i < tamanho; i++) {
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
