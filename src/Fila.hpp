//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a fila.
/*! Classe que trata das operações relacionadas a filas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 28/08/14
 * \version 1.1
 */

#ifndef FILA_HPP_
#define FILA_HPP_
#include "EstruturaLinear.hpp"

template <typename T> class Fila : public EstruturaLinear<T> {
public:
  //! Método para adicionar dados à fila.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado no
   * vetor.
   * \sa retira(), limparFila()
   */
  void inclui(T dado) { this->adicionaDado(dado); }

  //! Método para retirar dados da fila.
  /*!
   * \return um objeto genérico que era o primeiro da fila.
   * \sa retira(), limparFila()
   */
  T retira() {
    if (this->estruturaLinearVazia()) {
      throw ExcecaoEstruturaVazia();
    }
    T dado = this->estrutura[0];
    this->fim--;
    for (int i = 0; i < this->fim + 1; i++) {
      this->estrutura[i] = this->estrutura[i + 1];
    }
    return dado;
  }

  //! Método que identifica o último elemento da fila.
  /*!
   * \return um objeto genérico.
   * \sa getUltimo()
   */
  T ultimo() { return this->getPosFinal(); }

  //! Método que identifica a posição do último elemento da fila.
  /*!
   * \return um inteiro.
   * \sa ultimo()
   */
  int getUltimo() { return this->final(); }

  //! Método que limpa a fila de quaisquer elementos.
  /*!
   * \sa inclui(), retira()
   */
  void limparFila() { this->limparEstruturaLinear(); }

  //! Método que mostra se a fila está vazia.
  /*!
   * \return um boolean.
   * \sa filaCheia()
   */
  bool filaVazia() { return this->estruturaLinearVazia(); }

  //! Método que mostra se a fila está cheia.
  /*!
   * \return um boolean.
   * \sa filaVazia()
   */
  bool filaCheia() { return this->estruturaLinearCheia(); }

  //! Método que inicializa a fila sem elementos.
  /*!
   * \sa limparFila()
   */
  void inicializaFila() { this->fim = -1; }
};

#endif
