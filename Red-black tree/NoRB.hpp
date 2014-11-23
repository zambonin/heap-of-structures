//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária red-black.
/*! Classe que trata das operações relacionadas a árvores red-black. 
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 14/11/14
* \version 1.0
*/

#ifndef NORB_HPP_
#define NORB_HPP_
#include "NoBinario.hpp"

template <typename T>
class NoRB {
 private:
 	T dado;
 	NoRB<T>* raiz;
 	NoRB<T>* esq;
 	NoRB<T>* dir;
 	bool cor; //false para preto, true para rubro
    
 public:
 	NoRB(T data);
 	NoRB<T>* roda_dir(NoRB<T>* nodo);
 	NoRB<T>* roda_esq(NoRB<T>* nodo);
 	void insere_RB(NoRB<T>* raiz, const T& dado, NoRB<T>* nodo);
 	void passo_CE_esq(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo);
 	void passo_CE_dir(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo);
 	NoRB<T>* passo_CED(NoRB<T>* nodo, NoRB<T>* raiz);
 	NoRB<T>* passo_CED_esq(NoRB<T>* nodo, NoRB<T>* raiz);
 	NoRB<T>* passo_CED_dir(NoRB<T>* nodo, NoRB<T>* raiz);
};

template <typename T>
NoRB<T>::NoRB(T data) {
	dado = data;
	raiz = 0;
	esq = 0;
	dir = 0;
	cor = false;
}

template <typename T>
NoRB<T>* NoRB<T>::roda_dir(NoRB<T>* nodo) {
	NoRB<T>* pai = nodo->pai;
	bool lado; //false para esquerda, true para direita
	if (pai->esq == nodo) {
		lado = false;
	} else {
		lado = true;
	}
	NoRB<T>* aux = nodo->esq;
	aux->pai = pai;
	nodo->esq = aux->dir;
	nodo->esq->pai = nodo;
	aux->dir = nodo;
	aux->dir->pai = aux;
	if (!lado) {
		pai->esq = aux;
	} else {
		pai->dir = aux;
	}
	return aux;
}

template <typename T>
NoRB<T>* NoRB<T>::roda_esq(NoRB<T>* nodo) {
	NoRB<T>* pai = nodo->pai;
	bool lado; //false para esquerda, true para direita
	if (pai->esq == nodo) {
		lado = false;
	} else {
		lado = true;
	}
	NoRB<T>* aux = nodo->dir;
	aux->pai = pai;
	nodo->dir = aux->esq;
	nodo->dir->pai = nodo;
	aux->esq = nodo;
	aux->esq->pai = aux;
	if (!lado) {
		pai->esq = aux;
	} else {
		pai->dir = aux;
	}
	return aux;
}

template <typename T>
void NoRB<T>::insere_RB(NoRB<T>* raiz, const T& dado, NoRB<T>* nodo) {
	NoBinario<T>::inserir(dado, nodo);
	nodo->cor = true;
	NoRB<T>* atual = nodo;
	NoRB<T>* pai, avo;
	while (atual != raiz && atual->pai->cor) {
		pai = atual->pai;
		avo = pai->pai;
		if (avo->esq == pai) {
			passo_CE_esq(atual, pai, avo);
		} else {
			passo_CE_dir(atual, pai, avo);
		}
	}
	raiz->cor = false;
}

template <typename T>
void NoRB<T>::passo_CE_esq(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo) {
	NoRB<T>* tio = avo->dir;
	if (tio->cor) {
		pai->cor = false;
		avo->cor = true;
		tio->cor = false;
		atual = avo;
	} else {
		if (pai->dir == atual) {
			roda_esq(pai);
			atual = atual->esq;
		}
		pai->cor = false;
		avo->cor = true;
		roda_dir(avo);
	}
}

template <typename T>
void NoRB<T>::passo_CE_dir(NoRB<T>* atual, NoRB<T>* pai, NoRB<T>* avo) {
	NoRB<T>* tio = avo->dir;
	if (tio->cor) {
		pai->cor = false;
		avo->cor = true;
		tio->cor = false;
		atual = avo;
	} else {
		if (pai->esq == atual) {
			roda_dir(pai);
			atual = atual->dir;
		}
		pai->cor = false;
		avo->cor = true;
		roda_esq(avo);
	}
}

template <typename T>
NoRB<T>* NoRB<T>::passo_CED(NoRB<T>* nodo, NoRB<T>* raiz) {
	while (nodo != raiz) {
		if (nodo == nodo->pai->esq) {
			nodo = passo_CED_esq(nodo, raiz);
		} else {
			nodo = passo_CED_dir(nodo, raiz);
		}
	}
	return nodo;
}

template <typename T>
NoRB<T>* NoRB<T>::passo_CED_esq(NoRB<T>* nodo, NoRB<T>* raiz) {
	NoRB<T>* aux = nodo->pai->dir;
	if (aux->cor) {
		aux->cor = false;
		nodo->pai->cor = true;
		roda_esq(nodo->pai);
		aux = nodo->pai->dir;
	}
	if (!aux->esq->cor && !aux->dir->cor) {
		aux->cor = true;
		nodo = nodo->pai;
	} else {
		if (!aux->dir->cor) {
			aux->esq->cor = false;
			aux->cor = true;
		} else {
			aux->cor = nodo->pai->cor;
			nodo->pai->cor = false;
			aux->dir->cor = false;
			roda_esq(nodo->pai);
			nodo = raiz;
		}
	}
	return raiz;
}

template <typename T>
NoRB<T>* NoRB<T>::passo_CED_dir(NoRB<T>* nodo, NoRB<T>* raiz) {
	NoRB<T>* aux = nodo->pai->esq;
	if (aux->cor) {
		aux->cor = false;
		nodo->pai->cor = true;
		roda_dir(nodo->pai);
		aux = nodo->pai->esq;
	}
	if (!aux->esq->cor && !aux->dir->cor) {
		aux->cor = true;
		nodo = nodo->pai;
	} else {
		if (!aux->esq->cor) {
			aux->dir->cor = false;
			aux->cor = true;
		} else {
			aux->cor = nodo->pai->cor;
			nodo->pai->cor = false;
			aux->esq->cor = false;
			roda_dir(nodo->pai);
			nodo = raiz;
		}
	}
	return raiz;
}

#endif
