//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a pista.
/*! Classe que gerencia uma fila encadeada de carros.
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 09/10/14
* \version 1.0
*/

#ifndef PISTA_HPP_
#define PISTA_HPP_
#include "Carro.hpp"
#include "Linked/FilaEnc.hpp"
#include <cstdio>

class Pista : public FilaEnc<Carro*> {
 private:
  //! Identificador de tamanho.
  /*! Descreve o tamanho da fila encadeada de carros. */
  int tamanho;

  //! Contador de carros que passaram por semáforos.
  /*! Descreve a quantidade de carros que trocaram de pista. */
  int carrosQuePassaram;

  //! Contador de carros que entraram no sistema.
  /*! Descreve a quantidade de carros que foram criados. */
  int carrosQueEntraram;

  //! Identificador de espaço ocupado.
  /*! Descreve o espaço ocupado por carros na pista. */
  int espacoOcupado;

  //! Identificador de velocidade média.
  /*! Descreve a velocidade média da pista. */
  int velocidadeMedia;

  //! Identificador de tempo de chegada.
  /*! Descreve o tempo necessário para chegar ao final da pista. */
  int tempoChegada;

  //! Identificador de tempo de criação positivo.
  /*! Descreve o máximo tempo do evento para ser criado um carro na pista. */
  int tempoCriacaoPos;

  //! Identificador de tempo de criação negativo.
  /*! Descreve o mínimo tempo do evento para ser criado um carro na pista. */
  int tempoCriacaoNeg;

  //! Identificador de pista fonte.
  /*! Descreve a habilidade de criação de carros da pista. */
  bool fonte;

  //! Identificador de pista sumidouro.
  /*! Descreve a habilidade de deleção de carros da pista. */
  bool sumidouro;

 public:
  //! Construtor.
  /*! Define as características intrínsecas da pista, fornecidas previamente. */
  Pista(int _tamanho,
        int _velocidadeMedia,
        int _intervaloCriacao,
        int _tempoCriacao);

  // Método que adiciona um carro na fila encadeada.
  /*!
  * \param carro o ponteiro do carro a ser adicionado.
  * \sa removeCarro()
  */
  void adicionaCarro(Carro* carro);

  //! Método que remove um carro da fila encadeada.
  /*!
  * \sa adicionaCarro()
  */
  void removeCarro();

  //! Método que calcula o próximo evento da pista.
  /*!
  * \param tempoAtual descreve o tempo do evento atual, necessário para o
  * cálculo.
  * \return um inteiro.
  * \sa tempoDeChegada()
  */
  int calculeProximoEvento(int tempoAtual);

  //! Método que calcula o tempo de chegada necessário para o carro completar
  //! seu trajeto.
  /*!
  * \param tempoNasceu tempo do evento que o carro foi criado.
  * \return um inteiro.
  * \sa calculeProximoEvento()
  */
  int tempoDeChegada(int tempoNasceu);

  //! Método que retorna quantos carros passaram por semáforos.
  /*!
  * \return um inteiro.
  * \sa retornaCarrosQueEntraram()
  */
  int retornaCarrosQuePassaram();

  //! Método que retorna quantos carros foram criados pelo sistema.
  /*!
  * \return um inteiro.
  * \sa retornaCarrosQuePassaram()
  */
  int retornaCarrosQueEntraram();

  //! Método que verifica se a pista está cheia.
  /*!
  * \param carro o objeto a ser adicionado ao tamanho atual da pista.
  * \return um boolean.
  */
  bool estaCheia(Carro* carro);

  //! Método que retorna se a pista cria carros.
  /*!
  * \return um boolean.
  * \sa eSumidouro()
  */
  bool eFonte();

  //! Método que retorna se a pista deleta carros.
  /*!
  * \return um boolean.
  * \sa eFonte()
  */
  bool eSumidouro();
};

Pista::Pista(int _tamanho,
             int _velocidadeMedia,
             int _intervaloCriacao,
             int _tempoCriacao) {
  tamanho = _tamanho;
  espacoOcupado = 0;
  carrosQuePassaram = 0;
  carrosQueEntraram = 0;
  velocidadeMedia = _velocidadeMedia;
  tempoChegada = tamanho / _velocidadeMedia;
  tempoCriacaoPos = _tempoCriacao + _intervaloCriacao;
  tempoCriacaoNeg = _tempoCriacao - _intervaloCriacao;
  if (_intervaloCriacao == 0) {
    if (_tempoCriacao == 0) {
      fonte = false;
      sumidouro = true;
    } else if (_tempoCriacao == 1) {
      fonte = false;
      sumidouro = false;
    }
  } else {
    fonte = true;
    sumidouro = false;
  }
}

void Pista::adicionaCarro(Carro* carro) {
  int _espacoOcupado = espacoOcupado + carro->getTamanho();
  if (_espacoOcupado <= tamanho) {
    this->inclui(carro);
    espacoOcupado = _espacoOcupado;
    carrosQueEntraram++;
  }
}

void Pista::removeCarro() {
  this->retira();
  carrosQuePassaram++;
}

int Pista::calculeProximoEvento(int tempoAtual) {
  return (tempoCriacaoNeg + (rand() % (int)(tempoCriacaoPos - 2 + 1)) +
          tempoAtual);
}

int Pista::tempoDeChegada(int tempoNasceu) {
  return tempoNasceu + tempoChegada;
}

int Pista::retornaCarrosQuePassaram() {
  return carrosQuePassaram;
}

int Pista::retornaCarrosQueEntraram() {
  return carrosQueEntraram;
}

bool Pista::estaCheia(Carro* carro) {
  return espacoOcupado + carro->getTamanho() > tamanho;
}

bool Pista::eFonte() {
  return fonte;
}

bool Pista::eSumidouro() {
  return sumidouro;
}

#endif
