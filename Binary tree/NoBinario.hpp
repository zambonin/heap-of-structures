//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária de busca com percursos.
/*! Classe que trata das operações relacionadas a árvores binárias. 
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 09/11/14
* \version 1.0
*/

#ifndef NOBINARIO_HPP_
#define NOBINARIO_HPP_
#include <vector>
#include <cstdio>

template<typename T>
class NoBinario {
 private:
    //! Dado de um nó da árvore binária.
    /*! Tipo genérico que armazena o conteúdo do nó da árvore binária. */
	T* dado;

	//! Filho à esquerda de um nó.
	/*! Nó que descreve o filho à esquerda em relação ao nó atual. */
	NoBinario<T>* esquerda;

	//! Filho à direita de um nó.
	/*! Nó que descreve o filho à direita em relação ao nó atual. */
	NoBinario<T>* direita;

	//! Vetor de elementos da árvore.
	/*! Estrutura vetorial que armazena todos os nós de uma árvore. */
	std::vector<NoBinario<T> > elementos;

	//! Método que verifica se o balanceamento na inserção está correto.
	/*!
	* \param arv a árvore a ser verificada.
	* \return o ponteiro da árvore modificada.
	* \sa balanco_remove()
	*/
	virtual NoBinario<T>* balanco_insere(NoBinario<T>* arv) {
		return arv;
	}

	//! Método que verifica se o balanceamento na remoção está correto.
	/*!
	* \param arv a árvore a ser verificada.
	* \return o ponteiro da árvore modificada.
	* \sa balanco_insere()
	*/
	virtual NoBinario<T>* balanco_remove(NoBinario<T>* arv) {
		return arv;
	}

 public:
    //! Construtor.
    /*! Construtor que cria um nó com conteúdo novo e dois filhos nulos. */
	NoBinario<T>(const T& dado): dado(new T(dado)), esquerda(0), direita(0) {}

	//! Destrutor.
	//! Destrutor que deleta todos os nós. */
	virtual ~NoBinario<T>() {}

	//! Método para retornar o conteúdo do nó especificado.
	/*!
	* \return o ponteiro de um tipo genérico.
	* \sa getElementos()
	*/
	T* getDado();

	//! Método para retornar o conteúdo da árvore inteira.
	/*!
	* \return o ponteiro da árvore de tipos genéricos.
	* \sa getDado()
	*/ 
	NoBinario<T>* getElementos();

	//! Método para buscar um elemento na árvore.
	/*!
	* \param dado o endereço do objeto genérico a ser buscado.
	* \param arv o ponteiro da árvore a ser varrida.
	* \return o ponteiro do dado genérico buscado.
	*/
	T* busca(const T& dado, NoBinario<T>* arv);

	//! Método para inserção de um elemento na árvore.
	/*!
	* \param dado o endereço do objeto genérico a ser inserido.
	* \param arv o ponteiro da árvore a ser manipulada.
	* \return o ponteiro da árvore de tipos genéricos.
	* \sa remover()
	*/
	NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv);

	//! Método para deleção de um elemento na árvore.
	/*!
	* \param dado o endereço do objeto genérico a ser excluído.
	* \param arv o ponteiro da árvore a ser manipulada.
	* \return o ponteiro da árvore de tipos genéricos.
	* \sa inserir()
	*/
	NoBinario<T>* remover(const T& dado, NoBinario<T>* arv);

	//! Método que define o menor valor em uma árvore.
	/*!
	* \param nodo o ponteiro da árvore a ser manipulada.
	* \return a folha mais à esquerda.
	*/
	NoBinario<T>* minimo(NoBinario<T>* nodo);

	//! Método de percorrimento, visitando a raiz antes das subárvores.
	/*!
	* \param nodo o ponteiro da árvore a ser percorrida.
	* \sa emOrdem(), posOrdem()
	*/
	void preOrdem(NoBinario<T>* nodo);

	//! Método de percorrimento, visitando primeiro a subárvore da
	//! esquerda, depois a raiz e por fim a subárvore da direita.
	/*!
	* \param nodo o ponteiro da árvore a ser percorrida.
	* \sa preOrdem(), posOrdem()
	*/
	void emOrdem(NoBinario<T>* nodo);

	//! Método de percorrimento, visitando a raiz depois das subárvores.
	/*!
	* \param nodo o ponteiro da árvore a ser percorrida.
	* \sa preOrdem(), emOrdem()
	*/
	void posOrdem(NoBinario<T>* nodo);
};

template <typename T>
T* NoBinario<T>::getDado() {
	return dado;
}

template <typename T>
NoBinario<T>* NoBinario<T>::getElementos() {
	return elementos.data();
}

template <typename T>
T* NoBinario<T>::busca(const T& dado, NoBinario<T>* arv) {
	while (arv != 0 && arv->getDado() != dado) {
		if (arv->getDado() < dado) {
			arv = arv->direita;
		} else {
			arv = arv->esquerda;
		}
	}
	return arv->getDado();
}

template <typename T>
NoBinario<T>* NoBinario<T>::inserir(const T& dado, NoBinario<T>* arv) {
	NoBinario<T>* novo = new NoBinario<T>(dado);
	if (dado < *arv->getDado()) {
		if (arv->esquerda == 0) {
			arv->esquerda = novo;
		} else {
			arv = inserir(dado, arv->esquerda);
		}
	} else {
		if (arv->direita == 0) {
			arv->direita = novo;
		} else {
			arv = inserir(dado, arv->direita);
		}
	}
	return arv;
}

template <typename T>
NoBinario<T>* NoBinario<T>::remover(const T& dado, NoBinario<T>* arv) {
	if (arv == 0) {
		return arv;
	}
	if (dado < arv->getDado()) {
		arv->esquerda = remover(dado, arv->esquerda);
		return arv;
	}
	if (dado > arv->getDado()) {
		arv->direita = remover(dado, arv->direita);
		return arv;
	}
	NoBinario<T>* temp, filho;
	if (arv->direita != 0 && arv->esquerda != 0) {
		temp = minimo(arv->direita);
		arv->getDado() = temp->getDado();
		arv->direita = remover(dado, arv->direita);
		return arv;
	} else {
		temp = arv;
		if (arv->direita != 0) {
			filho = arv->direita;
			return filho;
		}
		if (arv->esquerda != 0) {
			filho = arv->esquerda;
			return filho;
		}
		delete arv;
		return 0;
	}
}

template <typename T>
NoBinario<T>* NoBinario<T>::minimo(NoBinario<T>* nodo) {
	if (nodo == 0) {
		return 0;
	}
	NoBinario<T>* min = nodo;
	while (min->esquerda) {
		min = min->esquerda;
	}
	return min;
}

template <typename T>
void NoBinario<T>::preOrdem(NoBinario<T>* nodo) {
	if (nodo != 0) {
        elementos.push_back(*nodo);
		preOrdem(nodo->esquerda);
		preOrdem(nodo->direita);
	}
}

template <typename T>
void NoBinario<T>::emOrdem(NoBinario<T>* nodo) {
	if (nodo != 0) {
		emOrdem(nodo->esquerda);
		elementos.push_back(*nodo);
		emOrdem(nodo->direita);
	}
}

template <typename T>
void NoBinario<T>::posOrdem(NoBinario<T>* nodo) {
	if (nodo != 0) {
		posOrdem(nodo->esquerda);
		posOrdem(nodo->direita);
		elementos.push_back(*nodo);
	}
}

#endif
