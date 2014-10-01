//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista encadeada circular.
/*! Classe que trata das operações relacionadas a listas circulares. 
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 30/09/14
* \version 1.0
*/
#ifndef LISTACIRC_HPP_
#define LISTACIRC_HPP_
#include "Elemento.hpp"
#include "ListaEnc.hpp"

template<typename T>
class ListaCirc : public ListaEnc<T> {
 public:
  //! Construtor.
  /*! Construtor básico para a classe, sem parâmetros. */
  ListaCirc();

  //! Método para adicionar um dado diretamente no fim da lista circular.
  /*!
  * \param dado o endereço do objeto genérico a ser adicionado.
  * \sa adicionaEmOrdem(), adicionaNaPosicao(), adicionaNoInicio(),
  * eliminaDoInicio(), retira(), retiraEspecifico(), retiraDaPosicao(),
  * retiraDoInicio()
  */
  void adiciona(const T& dado);

  //! Método para adicionar um dado em uma posição específica
  //! de acordo com a ordem inerente da classe.
  /*!
  * \param data o endereço do objeto genérico a ser adicionado.
  * \sa adiciona(), adicionaNaPosicao(), adicionaNoInicio(),
  * eliminaDoInicio(), retira(), retiraEspecifico(), retiraDaPosicao(),
  * retiraDoInicio()
  */
  void adicionaEmOrdem(const T& data);

  //! Método para adicionar um dado em uma posição específica.
  /*!
  * \param dado o endereço do objeto genérico a ser adicionado.
  * \param pos a posição desejada na forma de número inteiro.
  * \sa adiciona(), adicionaEmOrdem(), adicionaNoInicio(), retira(),
  * retiraDaPosicao(), retiraDoInicio(), retiraEspecifico()
  */
  void adicionaNaPosicao(const T& dado, int pos);

  //! Método para adicionar um dado diretamente no início da lista circular.
  /*!
  * \param dado o endereço do objeto genérico a ser adicionado.
  * \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), retira(),
  * retiraDaPosicao(), retiraDoInicio(), retiraEspecifico()
  */
  void adicionaNoInicio(const T& dado);

  //! Método para eliminar o primeiro nó da lista circular.
  /*!
  * \param dado o endereço do objeto genérico a ser adicionado.
  * \sa ~ListaEnc()
  */
  void eliminaDoInicio();

  //! Método para retirar dados da lista circular.
  /*!
  * \return um objeto genérico que era o último da lista.
  * \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), adicionaNoInicio()
  * retiraDaPosicao(), retiraDoInicio(), retiraEspecifico()
  */
  T retira();

  //! Método para retirar um dado em uma posição específica.
  /*!
  * \param pos a posição desejada na forma de número inteiro.
  * \return um objeto genérico que tinha como índice a posição indicada.
  * \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), 
  * adicionaNoInicio(), retira(), retiraDoInicio(), retiraEspecifico()
  */
  T retiraDaPosicao(int pos);

  //! Método para retirar o primeiro dado da lista.
  /*!
  * \return um objeto genérico que era o primeiro da lista.
  * \sa adiciona(), adicionaEmOrdem(), adicionaNaPosicao(), 
  * adicionaNoInicio(), retira(), retiraDaPosicao(), retiraEspecifico()
  */
  T retiraDoInicio();

  //! Método para retirar um dado específico.
  /*!
  * \param dado o endereço do objeto genérico a ser adicionado.
  * \return o dado encontrado no vetor de acordo com a comparação.
  * \sa adiciona(), adicionaNoInicio(), adicionaNaPosicao(), 
  * adicionaEmOrdem(), retira(), retiraDaPosicao(), retiraDoInicio()
  */
  T retiraEspecifico(const T& dado);

  //! Método para identificar a presença de um dado
  //! específico na lista circular.
  /*!
  * \param dado o endereço do objeto genérico a ser comparado.
  * \return um boolean.
  * \sa posicao(), posicaoMem()
  */
  bool contem(const T& dado);

  //! Método para identificar a presença de um dado
  //! específico na lista circular.
  /*!
  * \param dado o endereço do objeto genérico a ser comparado.
  * \return um boolean.
  * \sa contem(), posicaoMem()
  */
  int posicao(const T& dado) const;

  //! Método para retornar a posição na memória de um dado
  //! especfico na lista circular.
  /*!
  * \param dado o endereço do objeto genérico a ser comparado.
  * \return um ponteiro relacionado ao dado específico.
  * \sa contem(), posicao()
  */
  T* posicaoMem(const T& dado) const;

  //! Método para retornar a informação contida na posição
  //! da lista circular.
  /*!
  * \param pos a posição do dado na lista circular.
  * \return um dado genérico.
  * \sa posicaoMemDuplo()
  */
  T mostra(int pos);

  //! Método para retornar a posição do último elemento na lista.
  /*!
  * \return a posição do último elemento na lista.
  */
  int verUltimo();
};

template<typename T>
ListaCirc<T>::ListaCirc() {
    Elemento<T>* sentinela = new Elemento<T>(0, 0);
    this->cabeca = sentinela;
    sentinela->setProximo(this->cabeca);
    this->tamanho = 0;
}

template<typename T>
void ListaCirc<T>::adiciona(const T& dado) {
    return adicionaNaPosicao(dado, this->tamanho);
}

template<typename T>
void ListaCirc<T>::adicionaEmOrdem(const T& data) {
  if (ListaEnc<T>::listaVazia()) {
    return adicionaNoInicio(data);
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  int posicao = 1;
  while (atual->getProximo() != 0 &&
        ListaEnc<T>::maior(data, atual->getInfo())) {
    atual = atual->getProximo();
    posicao++;
  }
  if (ListaEnc<T>::maior(data, atual->getInfo())) {
    return adicionaNaPosicao(data, posicao + 1);
  }
  adicionaNaPosicao(data, posicao);
}

template<typename T>
void ListaCirc<T>::adicionaNaPosicao(const T& dado, int pos) {
  if (ListaEnc<T>::posicaoInvalida(pos)) {
    throw ExcecaoPosicao();
  }
  if (pos == 0) {
    adicionaNoInicio(dado);
    return;
  }
  Elemento<T>* anterior = this->cabeca->getProximo();
  Elemento<T>* novo = new Elemento<T>(dado, 0);
  if (novo == 0) {
    throw ExcecaoListaCheia();
  }
  for (int i = 1; i < pos; i++) {
    anterior = anterior->getProximo();
  }
  novo->setProximo(anterior->getProximo());
  anterior->setProximo(novo);
  this->tamanho++;
}

template<typename T>
void ListaCirc<T>::adicionaNoInicio(const T& dado) {
  Elemento<T>* novo = new Elemento<T>(dado, 0);
  if (novo == 0) {
    throw ExcecaoListaCheia();
  }
  novo->setProximo(this->cabeca->getProximo());
  this->cabeca->setProximo(novo);
  this->tamanho++;
}

template<typename T>
void ListaCirc<T>::eliminaDoInicio() {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoListaVazia();
  }
  Elemento<T>* saiu = this->cabeca->getProximo();
  this->cabeca->setProximo(saiu->getProximo());
  this->tamanho--;
  delete saiu;
}

template<typename T>
T ListaCirc<T>::retira() {
    return retiraDaPosicao(this->tamanho);
}

template<typename T>
T ListaCirc<T>::retiraDaPosicao(int pos) {
  if (ListaEnc<T>::posicaoInvalida(pos)) {
    throw ExcecaoPosicao();
  }
  if (pos == 0) {
    return retiraDoInicio();
  }
  Elemento<T>* anterior = this->cabeca->getProximo();
  for (int i = 1; i < pos - 1; i++) {
    anterior = anterior->getProximo();
  }
  Elemento<T>* eliminar = anterior->getProximo();
  T volta = eliminar->getInfo();
  anterior->setProximo(eliminar->getProximo());
  this->tamanho--;
  delete eliminar;
  return volta;
}

template<typename T>
T ListaCirc<T>::retiraDoInicio() {
  Elemento<T>* saiu;
  T volta;
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoPosicao();
  }
  saiu = this->cabeca->getProximo();
  volta = saiu->getInfo();
  this->cabeca->setProximo(saiu->getProximo());
  this->tamanho--;
  delete saiu;
  return volta;
}

template<typename T>
T ListaCirc<T>::retiraEspecifico(const T& dado) {
    if (ListaEnc<T>::listaVazia()) {
        throw ExcecaoListaVazia();
    }
  return retiraDaPosicao(posicao(dado) + 1);
}

template<typename T>
bool ListaCirc<T>::contem(const T& dado) {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoListaVazia();
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  for (int i = 0; i < this->tamanho; i++) {
    if (ListaEnc<T>::igual(dado, atual->getInfo())) {
      return true;
    }
    atual = atual->getProximo();
  }
    return false;
}

template<typename T>
int ListaCirc<T>::posicao(const T& dado) const {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoListaVazia();
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  for (int i = 0; i < this->tamanho; i++) {
    if (dado == atual->getInfo()) {
      return i;
    }
    atual = atual->getProximo();
  }
  throw ExcecaoDadoNaoEncontrado();
}

template<typename T>
T* ListaCirc<T>::posicaoMem(const T& dado) const {
    if (ListaEnc<T>::listaVazia()) {
        throw ExcecaoListaVazia();
    }
    int posicao = this->posicao(dado);
    Elemento<T>* atual = this->cabeca->getProximo();
    for (int i = 1; i < posicao; i++) {
        atual = atual->getProximo();
    }
    T volta = atual->getInfo();
    T* retorno = &volta;
    return retorno;
}

template<typename T>
T ListaCirc<T>::mostra(int pos) {
  if (ListaEnc<T>::listaVazia()) {
    throw ExcecaoListaVazia();
  }
  Elemento<T>* atual = this->cabeca->getProximo();
  for (int i = 0; i < pos; i++) {
    atual = atual->getProximo();
  }
  return atual->getInfo();
}

template<typename T>
int ListaCirc<T>::verUltimo() {
  return this->tamanho;
}

#endif
