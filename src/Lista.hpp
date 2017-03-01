//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista.
/*! Classe que trata das operações relacionadas a listas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.1
 */

#ifndef LISTA_HPP_
#define LISTA_HPP_
#include "ExcecaoDadoNaoEncontrado.h"
#include "ExcecaoListaCheia.h"
#include "ExcecaoListaVazia.h"
#include "ExcecaoPosicao.h"

template <typename T>
class Lista {
 public:
  //! Vetor básico.
  /*! Vetor usado para armazenar os dados da lista. */
  T* lista;

  //! Identificador de posição.
  /*! Posição do último elemento da lista. */
  int ultimo;

  //! Identificador de tamanho.
  /*! Tamanho da lista. */
  int tamanho;

 public:
  //! Construtor com parâmetros.
  /*! Construtor que permite a variabilidade de tamanho da lista.
   * \param t o número máximo de elementos no vetor.
   */
  explicit Lista(int tam)
    : lista(new T[tam]), ultimo(-1), tamanho(tam) {}

  //! Método para adicionar dados à lista.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado.
   * \sa adicionaNoInicio(), adicionaNaPosicao(), adicionaEmOrdem(),
   * retira(), retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
   */
  void adiciona(T dado) {
    return adicionaNaPosicao(dado, ultimo + 1);
  }

  //! Método para adicionar um dado diretamente no início da lista.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado.
   * \sa adiciona(), adicionaNaPosicao(), adicionaEmOrdem(), retira(),
   * retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
   */
  void adicionaNoInicio(T dado) {
    return adicionaNaPosicao(dado, 0);
  }

  //! Método para adicionar um dado em uma posição específica.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado.
   * \param posicao a posição desejada na forma de número inteiro.
   * \sa adiciona(), adicionaNoInicio(), adicionaEmOrdem(), retira(),
   * retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
   */
  void adicionaNaPosicao(T dado, int posicao) {
    if (listaCheia()) {
      throw ExcecaoListaCheia();
    }
    if (posicaoInvalida(posicao)) {
      throw ExcecaoPosicao();
    }
    ultimo++;
    for (int i = ultimo; i > posicao; i--) {
      lista[i] = lista[i - 1];
    }
    lista[posicao] = dado;
  }

  //! Método para adicionar um dado em uma posição específica
  //! de acordo com a ordem inerente da classe.
  /*!
   * \param dado um objeto genérico que representa o dado a ser adicionado.
   * \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), retira(),
   * retiraDoInicio(), retiraDaPosicao(), retiraEspecifico()
   */
  void adicionaEmOrdem(T dado) {
    if (listaCheia()) {
      throw ExcecaoListaCheia();
    }
    int posicao = 0;
    while ((posicao <= ultimo) && (maior(dado, lista[posicao]))) {
      posicao++;
    }
    adicionaNaPosicao(dado, posicao);
  }

  //! Método para retirar dados da lista.
  /*!
   * \return um objeto genérico que era o último da lista.
   * \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(),
   * adicionaEmOrdem(), retiraDoInicio(), retiraDaPosicao(),
   * retiraEspecifico()
   */
  T retira() {
    return retiraDaPosicao(ultimo);
  }

  //! Método para retirar o primeiro dado da lista.
  /*!
   * \return um objeto genérico que era o primeiro da lista.
   * \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(),
   * adicionaEmOrdem(), retira(), retiraDaPosicao(), retiraEspecifico()
   */
  T retiraDoInicio() {
    return retiraDaPosicao(0);
  }

  //! Método para retirar um dado em uma posição específica.
  /*!
   * \param posicao a posição desejada na forma de número inteiro.
   * \return um objeto genérico que tinha como índice a posição indicada.
   * \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(),
   * adicionaEmOrdem(), retiraDoInicio(), retiraEspecifico()
   */
  T retiraDaPosicao(int posicao) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    if (posicaoInvalida(posicao)) {
      throw ExcecaoPosicao();
    }
    ultimo--;
    T dado = lista[posicao];
    for (int i = posicao; i <= ultimo; i++) {
      lista[posicao] = lista[posicao + 1];
    }
    return dado;
  }

  //! Método para retirar um dado específico.
  /*!
   * \param dado o dado a ser informado para comparação no vetor.
   * \return o dado encontrado no vetor de acordo com a comparação.
   * \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(),
   * adicionaEmOrdem(), retiraDoInicio(), retiraDaPosicao(),
   */
  T retiraEspecifico(T dado) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    return retiraDaPosicao(posicao(dado));
  }

  //! Método para identificar a posição de um dado específico no vetor.
  /*!
   * \param dado o dado a ser informado para comparação no vetor.
   * \return a posição do dado indicado.
   * \sa contem(), retornaDado()
   */
  int posicao(T dado) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    for (int i = 0; i <= ultimo; i++) {
      if (igual(dado, lista[i])) {
        return i;
      }
    }
    throw ExcecaoDadoNaoEncontrado();
  }

  //! Método para identificar a presença de um dado específico no vetor.
  /*!
   * \param dado o dado a ser informado para comparação no vetor.
   * \return um boolean.
   * \sa posicao(), retornaDado()
   */
  bool contem(T dado) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    for (int i = 0; i <= ultimo; i++) {
      if (igual(dado, lista[i])) {
        return true;
      }
    }
    return false;
  }

  //! Método para retornar o dado do elemento de acordo com uma posição.
  /*!
   * \param posicao a posição específica do elemento a ser encontrado.
   * \return o dado encontrado no vetor de acordo com a comparação.
   * \sa contem(), posicao()
   */
  T retornaDado(int posicao) {
    if (listaVazia()) {
      throw ExcecaoListaVazia();
    }
    return lista[posicao];
  }

  //! Método de comparação de igualdade entre dois dados.
  /*!
   * /param dado1 o primeiro dado a ser comparado.
   * /param dado2 o segundo dado a ser comparado.
   * \sa maior(), menor()
   */
  bool igual(T dado1, T dado2) {
    return dado1 == dado2;
  }

  //! Método de comparação de maioridade (de acordo com um critério
  //! estabelecido pela classe) entre dois dados.
  /*!
   * /param dado1 o primeiro dado a ser comparado.
   * /param dado2 o segundo dado a ser comparado.
   * \sa igual(), menor()
   */
  bool maior(T dado1, T dado2) {
    return dado2 < dado1;
  }

  //! Método de comparação de minoridade (de acordo com um critério
  //! estabelecido pela classe) entre dois dados.
  /*!
   * /param dado1 o primeiro dado a ser comparado.
   * /param dado2 o segundo dado a ser comparado.
   * \sa igual(), maior()
   */
  bool menor(T dado1, T dado2) {
    return dado1 < dado2;
  }

  //! Método que mostra se a lista está cheia.
  /*!
   * \return um boolean.
   * \sa listaVazia()
   */
  bool listaCheia() {
    return ultimo == tamanho - 1;
  }

  //! Método que mostra se a lista está vazia.
  /*!
   * \return um boolean.
   * \sa listaCheia()
   */
  bool listaVazia() {
    return ultimo == -1;
  }

  //! Método que destrói a lista.
  /*!
   * \sa inicializaLista()
   */
  void destroiLista() {
    ultimo = -1;
  }

  //! Método para checagem de posição inválida solicitada no vetor.
  /*!
   * \param p a posição a ser validada.
   * \return um boolean.
   * \sa posicao()
   */
  bool posicaoInvalida(int p) {
    return !(p <= ultimo + 1 || p >= 0);
  }

  //! Método para retornar o tamanho da lista de vetor.
  /*!
   * \return um inteiro.
   */
  int getTamanho() {
    return tamanho;
  }
};

#endif
