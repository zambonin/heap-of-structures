//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe geral de estruturas lineares.
/*! Classe pai das estruturas básicas de fila e pilha,
 * que trata as operações básicas comuns às estruturas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 28/08/14
 * \version 1.1
 */

#ifndef ESTRUTURALINEAR_HPP_
#define ESTRUTURALINEAR_HPP_
#include "ExcecaoEstruturaCheia.h"
#include "ExcecaoEstruturaVazia.h"

template <typename T> class EstruturaLinear {
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
  //! Construtor com parâmetros.
  /*! Construtor que permite a variabilidade de tamanho da estrutura linear.
   * \param t o número máximo de elementos no vetor.
   */
  explicit EstruturaLinear(int t) : estrutura(new T[t]), fim(-1), tamanho(t) {}

  //! Método para adicionar dados à estrutura.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado no
   * vetor.
   * \sa retiraDado(), limparEstruturaLinear()
   */
  void adicionaDado(T dado) {
    if (estruturaLinearCheia()) {
      throw ExcecaoEstruturaCheia();
    }
    fim++;
    estrutura[fim] = dado;
  }

  //! Método para retirar dados da estrutura.
  /*!
   * \return um objeto genérico que era o final da estrutura.
   * \sa adicionaDado(), limparEstruturaLinear()
   */
  T retiraDado() {
    if (estruturaLinearVazia()) {
      throw ExcecaoEstruturaVazia();
    }
    fim--;
    return estrutura[fim + 1];
  }

  //! Método que identifica o último elemento da estrutura.
  /*!
   * \return um objeto genérico.
   * \sa getPosFinal()
   */
  T final() {
    if (estruturaLinearVazia()) {
      throw ExcecaoEstruturaVazia();
    }
    return estrutura[fim];
  }

  //! Método que identifica a posição do último elemento da estrutura.
  /*!
   * \return um inteiro.
   * \sa final()
   */
  int getPosFinal() {
    if (estruturaLinearVazia()) {
      throw ExcecaoEstruturaVazia();
    }
    return fim;
  }

  //! Método que limpa a estrutura linear.
  /*!
   * \sa adicionaDado(), retiraDado()
   */
  void limparEstruturaLinear() {
    if (estruturaLinearVazia()) {
      throw ExcecaoEstruturaVazia();
    }
    fim = -1;
  }

  //! Método que mostra se a estrutura linear está vazia.
  /*!
   * \return um boolean.
   * \sa estruturaLinearCheia()
   */
  bool estruturaLinearVazia() { return fim == -1; }

  //! Método que mostra se a estrutura linear está cheia.
  /*!
   * \return um boolean.
   * \sa estruturaLinearVazia()
   */
  bool estruturaLinearCheia() { return fim == tamanho - 1; }
};

#endif
