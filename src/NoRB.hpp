//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária red-black.
/*! Classe que trata das operações relacionadas a árvores red-black.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 14/11/14
 * \version 1.1
 */

#ifndef NORB_HPP_
#define NORB_HPP_
#include "NoBinario.hpp"

template <typename T> class NoRB {
private:
  //! Dado de um nó da árvore red-black.
  /*! Tipo genérico que armazena o conteúdo do nó da árvore red-black. */
  T dado;

  //! Raiz da árvore.
  /*! Nó que descreve a raiz da árvore red-black. */
  NoRB<T> *raiz;

  //! Filho à esquerda de um nó.
  /*! Nó que descreve o filho à esquerda em relação ao nó atual. */
  NoRB<T> *esq;

  //! Filho à direita de um nó.
  /*! Nó que descreve o filho à direita em relação ao nó atual. */
  NoRB<T> *dir;

  //! Denota a cor do nodo.
  /*! Boolean para representar a cor do nodo (true para rubro). */
  bool cor;

public:
  //! Construtor.
  /*! Construtor que cria um nó preto com conteúdo novo e dois filhos nulos. */
  explicit NoRB(T dado)
      : dado(dado), raiz(nullptr), esq(nullptr), dir(nullptr), cor(false) {}

  //! Método que rotaciona uma série de nodos à direita.
  /*!
   * \param nodo a raiz da subárvore a ser rotacionada.
   * \return nodo que representa a nova raiz.
   * \sa roda_esq()
   */
  NoRB<T> *roda_dir(NoRB<T> *nodo) {
    NoRB<T> *pai = nodo->pai;
    bool lado = pai->esq != nodo;
    NoRB<T> *aux = nodo->esq;
    aux->pai = pai;
    nodo->esq = aux->dir;
    nodo->esq->pai = nodo;
    aux->dir = nodo;
    aux->dir->pai = aux;
    lado ? pai->dir = aux : pai->esq = aux;
    return aux;
  }

  //! Método que rotaciona uma série de nodos à esquerda.
  /*!
   * \param nodo a raiz da subárvore a ser rotacionada.
   * \return nodo que representa a nova raiz.
   * \sa roda_dir()
   */
  NoRB<T> *roda_esq(NoRB<T> *nodo) {
    NoRB<T> *pai = nodo->pai;
    bool lado = pai->esq != nodo;
    NoRB<T> *aux = nodo->dir;
    aux->pai = pai;
    nodo->dir = aux->esq;
    nodo->dir->pai = nodo;
    aux->esq = nodo;
    aux->esq->pai = aux;
    lado ? pai->dir = aux : pai->esq = aux;
    return aux;
  }

  //! Método que insere um nodo na árvore.
  /*!
   * \param raiz a raiz da subárvore red-black.
   * \param dado o endereço do objeto genérico a ser inserido.
   * \param nodo o nodo a ser inserido.
   * \sa passo_CE_esq(), passo_CE_dir()
   */
  void insere_RB(NoRB<T> *raiz, const T &dado, NoRB<T> *nodo) {
    NoBinario<T>::inserir(dado, nodo);
    nodo->cor = true;
    NoRB<T> *atual = nodo;
    NoRB<T> *pai, avo;
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

  //! Método para realizar a correção e elevação à esquerda.
  /*!
   * \param atual nodo a ser corrigido e elevado.
   * \param pai nodo pai do atual, ou seja, um nível acima.
   * \param avo nodo pai do pai, ou seja, dois níveis acima do atual.
   * \sa insere_RB(), passo_CE_dir()
   */
  void passo_CE_esq(NoRB<T> *atual, NoRB<T> *pai, NoRB<T> *avo) {
    NoRB<T> *tio = avo->dir;
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

  //! Método para realizar a correção e elevação à direita.
  /*!
   * \param atual nodo a ser corrigido e elevado.
   * \param pai nodo pai do atual, ou seja, um nível acima.
   * \param avo nodo pai do pai, ou seja, dois níveis acima do atual.
   * \sa insere_RB(), passo_CE_esq()
   */
  void passo_CE_dir(NoRB<T> *atual, NoRB<T> *pai, NoRB<T> *avo) {
    NoRB<T> *tio = avo->dir;
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

  //! Método para realizar a correção e elevação da deleção.
  /*!
   * \param nodo o nodo a ser corrigido.
   * \param raiz a raiz da árvore red-black.
   * \return o nodo corrigido.
   * \sa passo_CED_esq(), passo_CED_dir()
   */
  NoRB<T> *passo_CED(NoRB<T> *nodo, NoRB<T> *raiz) {
    while (nodo != raiz) {
      if (nodo == nodo->pai->esq) {
        nodo = passo_CED_esq(nodo, raiz);
      } else {
        nodo = passo_CED_dir(nodo, raiz);
      }
    }
    return nodo;
  }

  //! Método para realizar a correção e elevação da deleção à esquerda.
  /*!
   * \param nodo o nodo a ser corrigido.
   * \param raiz a raiz da árvore red-black.
   * \return o nodo corrigido.
   * \sa passo_CED(), passo_CED_dir()
   */
  NoRB<T> *passo_CED_esq(NoRB<T> *nodo, NoRB<T> *raiz) {
    NoRB<T> *aux = nodo->pai->dir;
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

  //! Método para realizar a correção e elevação da deleção à direita.
  /*!
   * \param nodo o nodo a ser corrigido.
   * \param raiz a raiz da árvore red-black.
   * \return o nodo corrigido.
   * \sa passo_CED(), passo_CED_esq()
   */
  NoRB<T> *passo_CED_dir(NoRB<T> *nodo, NoRB<T> *raiz) {
    NoRB<T> *aux = nodo->pai->esq;
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
};

#endif
