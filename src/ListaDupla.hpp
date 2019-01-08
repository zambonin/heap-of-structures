//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista encadeada dupla.
/*! Classe que trata das operações relacionadas a listas encadeadas duplas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 27/09/14
 * \version 1.1
 */

#ifndef LISTADUPLA_HPP_
#define LISTADUPLA_HPP_
#include "ElementoDuplo.hpp"
#include "ExcecaoDadoNaoEncontrado.h"
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"
#include "ExcecaoPosicao.h"

template <typename T> class ListaDupla {
protected:
  //! Cabeça da lista encadeada dupla.
  /*! Elemento que descreve o primeiro nó da lista encadeada dupla. */
  ElementoDuplo<T> *cabeca;

  //! Identificador de tamanho.
  /*! Tamanho da lista encadeada dupla. */
  int tamanho;

public:
  //! Construtor.
  /*! Construtor básico para a classe, sem parâmetros. */
  ListaDupla() : cabeca(nullptr), tamanho(0) {}

  //! Destrutor.
  /*! Destrutor que deleta todos os nós. */
  virtual ~ListaDupla() { destroiListaDuplo(); }

  //! Método para adicionar um dado no fim da lista encadeada dupla.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \sa adicionaEmOrdem(), adicionaNaPosicaoDuplo(), adicionaNoInicioDuplo(),
   * eliminaDoInicioDuplo(), retiraDuplo(), retiraEspecificoDuplo(),
   * retiraDaPosicaoDuplo(), retiraDoInicioDuplo()
   */
  virtual void adicionaDuplo(const T &dado) {
    return this->adicionaNaPosicaoDuplo(dado, tamanho);
  }

  //! Método para adicionar um dado em uma posição específica
  //! de acordo com a ordem inerente da classe.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \sa adicionaDuplo(), adicionaNaPosicaoDuplo(), adicionaNoInicioDuplo(),
   * retiraDuplo(), retiraEspecificoDuplo(), retiraDaPosicaoDuplo(),
   * retiraDoInicioDuplo()
   */
  void adicionaEmOrdem(const T &data) {
    if (listaVazia()) {
      return adicionaNoInicioDuplo(data);
    }
    ElementoDuplo<T> *atual = cabeca;
    int posicao = 1;
    while (atual->getProximo() && maior(data, atual->getInfo())) {
      atual = atual->getProximo();
      posicao++;
    }
    if (maior(data, atual->getInfo())) {
      return adicionaNaPosicaoDuplo(data, posicao + 1);
    }
    adicionaNaPosicaoDuplo(data, posicao);
  }

  //! Método para adicionar um dado em uma posição específica.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \param pos a posição desejada na forma de número inteiro.
   * \sa adicionaDuplo(), adicionaEmOrdem(), adicionaNoInicioDuplo(),
   * retiraDuplo(), retiraDaPosicaoDuplo(), retiraDoInicioDuplo(),
   * retiraEspecificoDuplo()
   */
  void adicionaNaPosicaoDuplo(const T &dado, int pos) {
    if (posicaoInvalida(pos)) {
      throw ExcecaoPosicao();
    }
    if (pos == 0) {
      adicionaNoInicioDuplo(dado);
      return;
    }
    auto anterior = cabeca;
    auto novo = new ElementoDuplo<T>(dado, nullptr, nullptr);
    if (novo == nullptr) {
      throw ExcecaoListaCheia();
    }
    for (int i = 0; i < pos - 1; i++) {
      anterior = anterior->getProximo();
    }
    novo->setProximo(anterior->getProximo());
    if (novo->getProximo()) {
      novo->getProximo()->setAnterior(novo);
    }
    anterior->setProximo(novo);
    anterior->getProximo()->setAnterior(anterior);
    tamanho++;
  }

  //! Método para adicionar um dado no início da lista encadeada dupla.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \sa adicionaDuplo(), adicionaEmOrdem(), adicionaNaPosicaoDuplo(),
   * retiraDuplo(), retiraDaPosicaoDuplo(), retiraDoInicioDuplo(),
   * retiraEspecificoDuplo()
   */
  virtual void adicionaNoInicioDuplo(const T &dado) {
    auto novo = new ElementoDuplo<T>(dado, nullptr, nullptr);
    if (novo == nullptr) {
      throw ExcecaoListaCheia();
    }
    novo->setProximo(cabeca);
    novo->setAnterior(0);
    cabeca = novo;
    if (novo->getProximo()) {
      novo->getProximo()->setAnterior(novo);
    }
    tamanho++;
  }

  //! Método para eliminar o primeiro nó da lista encadeada dupla.
  /*!
   * \sa ~ListaDupla()
   */
  virtual void eliminaDoInicioDuplo() {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    ElementoDuplo<T> *saiu = cabeca;
    cabeca = saiu->getProximo();
    cabeca->setAnterior(0);
    tamanho--;
    delete saiu;
  }

  //! Método para retirar dados da lista encadeada dupla.
  /*!
   * \return um objeto genérico que era o último da lista.
   * \sa adicionaDuplo(), adicionaEmOrdem(), adicionaNaPosicaoDuplo(),
   * adicionaNoInicioDuplo(), retiraDaPosicaoDuplo(), retiraDoInicioDuplo(),
   * retiraEspecificoDuplo()
   */
  T retiraDuplo() { return this->retiraDaPosicaoDuplo(tamanho); }

  //! Método para retirar um dado em uma posição específica.
  /*!
   * \param pos a posição desejada na forma de número inteiro.
   * \return um objeto genérico que tinha como índice a posição indicada.
   * \sa adicionaDuplo(), adicionaEmOrdem(), adicionaNaPosicaoDuplo(),
   * adicionaNoInicioDuplo(), retiraDuplo(), retiraDoInicioDuplo(),
   * retiraEspecificoDuplo()
   */
  T retiraDaPosicaoDuplo(int pos) {
    if (posicaoInvalida(pos)) {
      throw ExcecaoPosicao();
    }
    if (pos == 0) {
      return retiraDoInicioDuplo();
    }
    ElementoDuplo<T> *anterior = cabeca;
    for (int i = 0; i < pos - 2; i++) {
      anterior = anterior->getProximo();
    }
    ElementoDuplo<T> *eliminar = anterior->getProximo();
    T volta = eliminar->getInfo();
    anterior->setProximo(eliminar->getProximo());
    if (eliminar->getProximo()) {
      eliminar->getProximo()->setAnterior(anterior);
    }
    tamanho--;
    delete eliminar;
    return volta;
  }

  //! Método para retirar o primeiro dado da lista.
  /*!
   * \return um objeto genérico que era o primeiro da lista.
   * \sa adicionaDuplo(), adicionaEmOrdem(), adicionaNaPosicaoDuplo(),
   * adicionaNoInicioDuplo(), retiraDuplo(), retiraDaPosicaoDuplo(),
   * retiraEspecificoDuplo()
   */
  virtual T retiraDoInicioDuplo() {
    ElementoDuplo<T> *saiu;
    T volta;
    if (listaVazia()) {
      throw ExcecaoPosicao();
    }
    saiu = cabeca;
    volta = saiu->getInfo();
    cabeca = saiu->getProximo();
    if (cabeca) {
      cabeca->setAnterior(0);
    }
    tamanho--;
    delete saiu;
    return volta;
  }

  //! Método para retirar um dado específico.
  /*!
   * \param dado o endereço do objeto genérico a ser adicionado.
   * \return o dado encontrado no vetor de acordo com a comparação.
   * \sa adicionaDuplo(), adicionaNoInicioDuplo(), adicionaNaPosicaoDuplo(),
   * adicionaEmOrdem(), retiraDuplo(), retiraDaPosicaoDuplo(),
   * retiraDoInicioDuplo()
   */
  T retiraEspecificoDuplo(const T &dado) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    return this->retiraDaPosicaoDuplo(posicaoDuplo(dado) + 1);
  }

  //! Método para identificar a presença de um dado
  //! específico na lista encadeada dupla.
  /*!
   * \param dado o endereço do objeto genérico a ser comparado.
   * \return um boolean.
   * \sa posicaoDuplo(), posicaoMemDuplo()
   */
  bool contemDuplo(const T &dado) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    ElementoDuplo<T> *atual = cabeca;
    for (int i = 0; i < tamanho; i++) {
      if (igual(dado, atual->getInfo())) {
        return true;
      }
      atual = atual->getProximo();
    }
    return false;
  }

  //! Método para identificar a presença de um dado
  //! específico na lista encadeada dupla.
  /*!
   * \param dado o endereço do objeto genérico a ser comparado.
   * \return um boolean.
   * \sa contemDuplo(), posicaoMemDuplo()
   */
  int posicaoDuplo(const T &dado) const {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    ElementoDuplo<T> *atual = cabeca;
    for (int i = 0; i < tamanho; i++) {
      if (dado == atual->getInfo()) {
        return i;
      }
      atual = atual->getProximo();
    }
    throw ExcecaoDadoNaoEncontrado();
  }

  //! Método para retornar a posição na memória de um dado
  //! específico na lista encadeada dupla.
  /*!
   * \param dado o endereço do objeto genérico a ser comparado.
   * \return um ponteiro relacionado ao dado específico.
   * \sa contemDuplo(), posicaoDuplo()
   */
  T *posicaoMemDuplo(const T &dado) const {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    int posicao = posicaoDuplo(dado);
    ElementoDuplo<T> *atual = cabeca;
    for (int i = 1; i < posicao; i++) {
      atual = atual->getProximo();
    }
    return atual->getInfo();
  }

  //! Método para retornar a informação contida na posição
  //! da lista encadeada dupla.
  /*!
   * \param pos a posição do dado na lista encadeada dupla.
   * \return um dado genérico.
   * \sa posicaoMemDuplo()
   */
  T mostra(int pos) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    ElementoDuplo<T> *mostra = cabeca;
    for (int i = 0; i < pos - 1; i++) {
      mostra = mostra->getProximo();
    }
    return mostra->getInfo();
  }

  //! Método para retornar a posição do último elemento na lista.
  /*!
   * \return a posição do último elemento na lista.
   */
  int verUltimo() { return tamanho; }

  //! Método para eliminar iterativamente cada elemento da lista encadeada.
  /*!
   * \sa ~ListaDupla()
   */
  virtual void destroiListaDuplo() {
    ElementoDuplo<T> *atual;
    for (int i = 0; i < tamanho; i++) {
      atual = cabeca;
      cabeca = cabeca->getProximo();
      delete atual;
    }
    tamanho = 0;
  }

  //! Método que mostra se a lista está vazia.
  /*!
   * \return um boolean.
   */
  bool listaVazia() const { return tamanho == 0; }

  //! Método de comparação de igualdade entre dois dados.
  /*!
   * \param dado1 o primeiro dado a ser comparado.
   * \param dado2 o segundo dado a ser comparado.
   * \sa maior(), menor()
   */
  bool igual(T dado1, T dado2) { return dado1 == dado2; }

  //! Método de comparação de maioridade (de acordo com um critério
  //! estabelecido pela classe) entre dois dados.
  /*!
   * \param dado1 o primeiro dado a ser comparado.
   * \param dado2 o segundo dado a ser comparado.
   * \sa igual(), menor()
   */
  bool maior(T dado1, T dado2) { return dado1 > dado2; }

  //! Método de comparação de minoridade (de acordo com um critério
  //! estabelecido pela classe) entre dois dados.
  /*!
   * \param dado1 o primeiro dado a ser comparado.
   * \param dado2 o segundo dado a ser comparado.
   * \sa igual(), maior()
   */
  bool menor(T dado1, T dado2) { return dado1 < dado2; }

  //! Método para checagem de posição inválida solicitada no vetor.
  /*!
   * \param p a posição a ser validada.
   * \return um boolean.
   * \sa posicaoDuplo(), posicaoMemDuplo()
   */
  bool posicaoInvalida(int p) { return p >= tamanho + 1 || p < 0; }
};

#endif
