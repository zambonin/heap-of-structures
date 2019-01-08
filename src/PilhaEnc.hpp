//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a pilha encadeada.
/*! Classe que trata das operações relacionadas a pilhas encadeadas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 27/09/14
 * \version 1.1
 */

#ifndef PILHAENC_HPP_
#define PILHAENC_HPP_
#include "ExcecaoListaVazia.h"
#include "ListaEnc.hpp"

template <typename T> class PilhaEnc : public ListaEnc<T> {
public:
  //! Método para adicionar um dado à pilha encadeada.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \sa desempilha()
   */
  void empilha(const T &dado) { this->adicionaNoInicio(dado); }

  //! Método para retirar o último dado da pilha encadeada.
  /*!
   * \return um objeto genérico que era o último da pilha encadeada.
   * \sa empilha()
   */
  T desempilha() { return this->retiraDoInicio(); }

  //! Método de identificação do último elemento da pilha encadeada.
  /*!
   * \return o último objeto adicionado à pilha encadeada.
   */
  T topo() {
    if (PilhaVazia()) {
      throw ExcecaoListaVazia();
    }
    return this->cabeca->getInfo();
  }

  //! Método para eliminar iterativamente cada elemento da pilha encadeada.
  /*!
   * \sa ~PilhaEnc()
   */
  void limparPilha() { this->destroiLista(); }

  //! Método que mostra se a pilha está vazia.
  /*!
   * \return um boolean.
   */
  bool PilhaVazia() { return this->listaVazia(); }
};

#endif
