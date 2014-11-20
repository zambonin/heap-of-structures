//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária AVL.
/*! Classe que trata das operações relacionadas a árvores AVL. 
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 14/11/14
* \version 1.0
*/

#ifndef NOAVL_HPP_
#define NOAVL_HPP_
#include "NoBinario.hpp"
#include "ExcecaoAVL.h"

template <typename T>
class NoAVL : NoBinario<T> {
 private:
 	T* dado;
	NoAVL<T>* esquerda;
	NoAVL<T>* direita;
 	int altura;

 public:
	NoAVL<T>(const T& dado): dado(new T(dado)), esquerda(0), direita(0) { altura = 0; }
  	NoAVL<T>* simp_roda_esq(NoAVL<T>* sub);
  	NoAVL<T>* simp_roda_dir(NoAVL<T>* sub);
  	NoAVL<T>* dup_roda_esq(NoAVL<T>* sub);
  	NoAVL<T>* dup_roda_dir(NoAVL<T>* sub);
  	int fator(NoAVL<T>* nodo);
  	NoAVL<T>* inserir(const T& dado, NoAVL<T>* nodo);
  	NoAVL<T>* remover(const T& dado, NoAVL<T>* nodo);
}; 

template <typename T>
NoAVL<T>* NoAVL<T>::simp_roda_esq(NoAVL<T>* sub) {
	NoAVL<T>* sub2 = sub->esquerda;
	sub->esquerda = sub2->direita;
	sub->direita = sub2;
	int a = sub->esquerda->altura >= sub->direita->altura ? sub->esquerda->altura : sub->direita->altura;
	sub->altura++;
	a = sub2->esquerda->direita >= sub2->direita->altura ? sub2->esquerda->altura : sub->altura;
	sub2->altura++;
	return sub2;
}

template <typename T>
NoAVL<T>* NoAVL<T>::simp_roda_dir(NoAVL<T>* sub) {
	NoAVL<T>* sub2 = sub->direita;
	sub->direita = sub2->esquerda;
	sub->esquerda = sub2;
	int a = sub->esquerda->altura >= sub->direita->altura ? sub->esquerda->altura : sub->direita->altura;
	sub->altura++;
	a = sub2->esquerda->altura >= sub2->direita->altura ? sub2->direita->altura : sub->altura;
	sub2->altura++;
	return sub2;
}

template <typename T>
NoAVL<T>* NoAVL<T>::dup_roda_esq(NoAVL<T>* sub) {
	sub->esquerda = simp_roda_dir(sub->esquerda);
	return simp_roda_esq(sub);
}

template <typename T>
NoAVL<T>* NoAVL<T>::dup_roda_dir(NoAVL<T>* sub) {
	sub->direita = simp_roda_esq(sub->direita);
	return simp_roda_dir(sub);
}

template <typename T>
int NoAVL<T>::fator(NoAVL<T>* nodo) {
	return !nodo ? 0 : nodo->esquerda->altura - nodo->direita->altura;
}

template <typename T>
NoAVL<T>* NoAVL<T>::inserir(const T& dado, NoAVL<T>* nodo) {
	if (!nodo) {
		return nodo = new NoAVL<T>(dado);
	}
	else if (dado < nodo->getDado()) {
		nodo->esquerda = inserir(nodo->esquerda, dado);
		if (fator(nodo) == 2) {
			if (fator(nodo->esquerda) == -1) {
				nodo->esquerda = simp_roda_esq(nodo->esquerda);
			}
			nodo = simp_roda_dir(nodo);
		}
	}
	else if (dado > nodo->getDado()) {
		nodo->direita = inserir(nodo->direita, dado);
		if (fator(nodo) == -2) {
			if (fator(nodo->direita) == 1) {
				nodo->direita = simp_roda_dir(nodo->direita);
			}
			nodo = simp_roda_esq(nodo);
		}
	} else {
		throw ExcecaoAVL();
	}
	nodo->altura = std::max(nodo->esquerda->altura, nodo->direita->altura) + 1;
	return nodo;
}

template <typename T>
NoAVL<T>* NoAVL<T>::remover(const T& dado, NoAVL<T>* nodo) {
	if (!nodo) {
		throw ExcecaoAVL();
	}
	else if (dado < nodo->getDado()) {
		nodo->esquerda = inserir(nodo->esquerda, dado);
		if (fator(nodo) == 2) {
			if (fator(nodo->esquerda) == -1) {
				nodo->esquerda = simp_roda_esq(nodo->esquerda);
			}
			nodo = simp_roda_dir(nodo);
		}
	}
	else if (dado > nodo->getDado()) {
		nodo->direita = inserir(nodo->direita, dado);
		if (fator(nodo) == -2) {
			if (fator(nodo->direita) == 1) {
				nodo->direita = simp_roda_dir(nodo->direita);
			}
			nodo = simp_roda_esq(nodo);
		}
	} else {
		if (!(nodo->esquerda) && !(nodo->direita)) {
			delete nodo;
			return 0;
		}
		if (!(nodo->esquerda)) {
			NoAVL<T>* aux = nodo->direita;
			delete nodo;
			return aux;
		}
		if (!(nodo->direita)) {
			NoAVL<T>* aux = nodo->esquerda;
			delete nodo;
			return aux;
		}
		NoAVL<T>* aux = nodo->direita;
		while (aux->esquerda) {
			aux = aux->esquerda;
		}
		std::swap(nodo->getDado(), aux->getDado());
		nodo->direita = remover(nodo->direita, dado);
	}
	nodo->altura = std::max(nodo->esquerda->altura, nodo->direita->altura) + 1;
	return nodo;
}

#endif
