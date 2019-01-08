//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária AVL.
/*! Classe que trata das operações relacionadas a árvores AVL.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 14/11/14
 * \version 1.1
 */

#ifndef NOAVL_HPP_
#define NOAVL_HPP_
#include "ExcecaoDadoNaoEncontrado.h"

template <typename T> class NoAVL {
private:
  //! Dado de um nó da árvore AVL.
  /*! Tipo genérico que armazena o conteúdo do nó da árvore AVL. */
  T dado;

  //! Filho à esquerda de um nó.
  /*! Nó que descreve o filho à esquerda em relação ao nó atual. */
  NoAVL<T> *esquerda;

  //! Filho à direita de um nó.
  /*! Nó que descreve o filho à direita em relação ao nó atual. */
  NoAVL<T> *direita;

  //! Altura da árvore.
  /*! Inteiro que armazena a altura total da árvore AVL. */
  int altura;

public:
  //! Construtor.
  /*! Construtor que cria um nó com conteúdo novo e dois filhos nulos. */
  explicit NoAVL(T dado)
      : dado(dado), esquerda(nullptr), direita(nullptr), altura(1) {}

  //! Método para retornar a altura de certo nodo.
  /*!
   * \param nodo o nodo a ser buscado.
   * \return um inteiro.
   * \sa arrumarAltura(), fator()
   */
  int height(NoAVL<T> *nodo) { return nodo ? nodo->altura : 0; }

  //! Método para retornar o fator de balanceamento de certo nodo.
  /*!
   * \param nodo o nodo a ser buscado.
   * \return um inteiro.
   * \sa arrumarAltura(), height()
   */
  int fator(NoAVL<T> *nodo) {
    return height(nodo->direita) - height(nodo->esquerda);
  }

  //! Método para consertar o atributo `altura`.
  /*!
   * \param nodo o nodo a ser consertado.
   * \sa fator(), height()
   */
  void arrumarAltura(NoAVL<T> *nodo) {
    int hL = height(nodo->esquerda);
    int hR = height(nodo->direita);
    nodo->altura = (hL > hR ? hL : hR) + 1;
  }

  //! Método que rotaciona uma série de nodos à direita.
  /*!
   * \param raiz a raiz da subárvore a ser rotacionada.
   * \return nodo que representa a nova raiz.
   * \sa rotacao_esquerda(), rotacao_dupla_esquerda(), rotacao_dupla_direita()
   */
  NoAVL<T> *rotacao_direita(NoAVL<T> *raiz) {
    NoAVL<T> *auxiliar = raiz->esquerda;
    raiz->esquerda = 0;
    auxiliar->direita = raiz;
    raiz = auxiliar;
    arrumarAltura(raiz);
    arrumarAltura(auxiliar);
    return raiz;
  }

  //! Método que rotaciona uma série de nodos à esquerda.
  /*!
   * \param raiz a raiz da subárvore a ser rotacionada.
   * \return nodo que representa a nova raiz.
   * \sa rotacao_direita(), rotacao_dupla_esquerda(), rotacao_dupla_direita()
   */
  NoAVL<T> *rotacao_esquerda(NoAVL<T> *raiz) {
    NoAVL<T> *auxiliar = raiz->direita;
    raiz->direita = 0;
    auxiliar->esquerda = raiz;
    raiz = auxiliar;
    arrumarAltura(raiz);
    arrumarAltura(auxiliar);
    return raiz;
  }

  //! Método que rotaciona duplamente uma série de nodos à direita.
  /*!
   * \param raiz a raiz da subárvore a ser rotacionada.
   * \return nodo que representa a nova raiz.
   * \sa rotacao_esquerda(), rotacao_direita(), rotacao_dupla_esquerda()
   */
  NoAVL<T> *rotacao_dupla_direita(NoAVL<T> *raiz) {
    raiz->direita = rotacao_esquerda(raiz->direita);
    return rotacao_direita(raiz);
  }

  //! Método que rotaciona duplamente uma série de nodos à esquerda.
  /*!
   * \param raiz a raiz da subárvore a ser rotacionada.
   * \return nodo que representa a nova raiz.
   * \sa rotacao_esquerda(), rotacao_direita(), rotacao_dupla_direita()
   */
  NoAVL<T> *rotacao_dupla_esquerda(NoAVL<T> *raiz) {
    raiz->esquerda = rotacao_direita(raiz->esquerda);
    return rotacao_esquerda(raiz);
  }

  //! Método que balanceia uma série de nodos.
  /*!
   * \param raiz a raiz da subárvore a ser balanceada.
   * \return nodo que representa a nova raiz.
   * \sa inserir(), remover(), removerMinimo()
   */
  NoAVL<T> *balancear(NoAVL<T> *raiz) {
    arrumarAltura(raiz);
    if (fator(raiz) == 2) {
      if (fator(raiz->direita) < 0) {
        raiz->direita = rotacao_direita(raiz->direita);
      }
      raiz = rotacao_esquerda(raiz);
    } else if (fator(raiz) == -2) {
      if (fator(raiz->esquerda) > 0) {
        raiz->esquerda = rotacao_esquerda(raiz->esquerda);
      }
      raiz = rotacao_direita(raiz);
    }
    return raiz;
  }

  //! Método que retorna o nodo mais à esquerda de uma subárvore.
  /*!
   * \param nodo a raiz da subárvore a ser percorrida.
   * \return um nodo mínimo à esquerda.
   * \sa remover()
   */
  NoAVL<T> *minimo(NoAVL<T> *nodo) {
    return nodo->esquerda ? minimo(nodo->esquerda) : nodo;
  }

  //! Método que remove o nodo mais à esquerda de uma subárvore.
  /*!
   * \param nodo a raiz da subárvore a ser modificada.
   * \return a nova subárvore balanceada.
   * \sa balancear(), remover()
   */
  NoAVL<T> *removerMinimo(NoAVL<T> *nodo) {
    if (nodo->esquerda == nullptr) {
      return nodo->direita;
    }
    nodo->esquerda = removerMinimo(nodo->esquerda);
    return balancear(nodo);
  }

  //! Método que insere um nodo na árvore.
  /*!
   * \param dado o endereço do objeto genérico a ser inserido.
   * \param nodo a raiz da subárvore a ser manipulada.
   * \return a nova subárvore balanceada.
   * \sa balancear()
   */
  NoAVL<T> *inserir(const T &dado, NoAVL<T> *nodo) {
    if (nodo == nullptr) {
      return nodo = new NoAVL<T>(dado);
    }
    if (dado < nodo->dado) {
      nodo->esquerda = inserir(dado, nodo->esquerda);
    } else {
      nodo->direita = inserir(dado, nodo->direita);
    }
    nodo = balancear(nodo);
    return nodo;
  }

  //! Método que remove um nodo da árvore.
  /*!
   * \param dado o endereço do objeto genérico a ser inserido.
   * \param nodo a raiz da subárvore a ser manipulada.
   * \return a nova subárvore balanceada.
   * \sa balancear(), removerMinimo()
   */
  NoAVL<T> *remover(const T &dado, NoAVL<T> *nodo) {
    if (!nodo) {
      throw ExcecaoDadoNaoEncontrado();
    }
    if (dado < nodo->dado) {
      nodo->esquerda = remover(dado, nodo->esquerda);
    } else if (dado > nodo->dado) {
      nodo->direita = remover(dado, nodo->direita);
    } else {
      NoAVL<T> *esq = nodo->esquerda;
      NoAVL<T> *dir = nodo->direita;
      delete nodo;
      if (!dir) {
        return esq;
      }
      NoAVL<T> *min = minimo(dir);
      min->direita = removerMinimo(dir);
      min->esquerda = esq;
      return balancear(min);
    }
    return balancear(nodo);
  }
};

#endif
