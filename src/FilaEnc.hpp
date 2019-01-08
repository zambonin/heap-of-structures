//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a fila encadeada.
/*! Classe que trata das operações relacionadas a filas encadeadas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 27/09/14
 * \version 1.1
 */

#ifndef FILAENC_HPP_
#define FILAENC_HPP_
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"
#include "ListaEnc.hpp"

template <typename T> class FilaEnc : public ListaEnc<T> {
private:
  //! Fim da fila encadeada.
  /*! Ponteiro que aponta para o último elemento da fila encadeada. */
  Elemento<T> *fim;

public:
  //! Construtor.
  /*! Construtor para a classe, sem parâmetros. Herdado da classe-pai. */
  FilaEnc() : ListaEnc<T>(), fim(nullptr) {}

  //! Método para adicionar um dado à fila encadeada.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \sa retira()
   */
  void inclui(const T &dado) {
    auto novo = new Elemento<T>(dado, nullptr);
    if (novo == nullptr) {
      throw ExcecaoListaCheia();
    }
    if (filaVazia()) {
      this->cabeca = novo;
    } else {
      fim->setProximo(novo);
    }
    novo->setProximo(0);
    fim = novo;
    this->tamanho++;
  }

  //! Método para retirar o último dado da fila encadeada.
  /*!
   * \return um objeto genérico que era o último da fila encadeada.
   * \sa inclui()
   */
  T retira() {
    if (filaVazia()) {
      throw ExcecaoListaVazia();
    }
    Elemento<T> *sai = this->cabeca;
    T volta = sai->getInfo();
    this->cabeca = sai->getProximo();
    if (this->tamanho == 1) {
      fim = 0;
    }
    this->tamanho--;
    delete sai;
    return volta;
  }

  //! Método de identificação do último elemento da fila encadeada.
  /*!
   * \return o último objeto adicionado à fila encadeada.
   * \sa primeiro()
   */
  T ultimo() {
    if (filaVazia()) {
      throw ExcecaoListaVazia();
    }
    return fim->getInfo();
  }

  //! Método de identificação do primeiro elemento da fila encadeada.
  /*!
   * \return o primeiro objeto adicionado à fila encadeada.
   * \sa ultimo()
   */
  T primeiro() { return this->retornaDado(0); }

  //! Método que mostra se a fila está vazia.
  /*!
   * \return um boolean.
   */
  bool filaVazia() { return this->listaVazia(); }

  //! Método para eliminar iterativamente cada elemento da fila encadeada.
  /*!
   * \sa ~FilaEnc()
   */
  void limparFila() { this->destroiLista(); }
};

#endif
