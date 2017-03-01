//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a pilha.
/*! Classe que trata das operações relacionadas a pilhas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 28/08/14
 * \version 1.1
 */

#ifndef PILHA_HPP_
#define PILHA_HPP_
#include "EstruturaLinear.hpp"

template <typename T>
class Pilha : public EstruturaLinear<T> {
 public:
  //! Método para adicionar dados à pilha.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado no
   * vetor.
   * \sa desempilha(), limparPilha()
   */
  void empilha(T dado) {
    this->adicionaDado(dado);
  }

  //! Método para retirar dados da pilha.
  /*!
   * \return um objeto genérico que era o topo da pilha.
   * \sa empilha(), limparPilha()
   */
  T desempilha() {
    return this->retiraDado();
  }

  //! Método que identifica o último elemento da pilha.
  /*!
   * \return um objeto genérico.
   * \sa getPosTopo()
   */
  T topo() {
    return this->final();
  }

  //! Método que identifica a posição do último elemento da pilha.
  /*!
   * \return um inteiro.
   * \sa topo()
   */
  int getPosTopo() {
    return this->getPosFinal();
  }

  //! Método que limpa a pilha de quaisquer elementos.
  /*!
   * \sa empilha(), desempilha()
   */
  void limparPilha() {
    this->limparEstruturaLinear();
  }

  //! Método que mostra se a pilha está vazia.
  /*!
   * \return um boolean.
   * \sa pilhaCheia()
   */
  bool PilhaVazia() {
    return this->estruturaLinearCheia();
  }

  //! Método que mostra se a pilha está cheia.
  /*!
   * \return um boolean.
   * \sa pilhaVazia()
   */
  bool PilhaCheia() {
    return this->estruturaLinearVazia();
  }
};

#endif
