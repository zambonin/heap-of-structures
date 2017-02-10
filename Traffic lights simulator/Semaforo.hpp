//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve o objeto "semáforo".
/*! Classe que gerencia os semáforos, parte essencial no controle de pistas.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.0
 */

#ifndef SEMAFORO_HPP_
#define SEMAFORO_HPP_
#include "ExcecaoSinalVermelho.hpp"
#include "Pista.hpp"
#include "Vector/Lista.hpp"

class Semaforo {
 private:
  //! Lista de vetor de pistas.
  /*! Descreve a lista que contém as pistas em um determinado semáforo. */
  Lista<Pista*>* pistas;

  //! Identificador de pista local.
  /*! Apresenta para qual pista o semáforo está aberto no evento. */
  Pista* pistaLocal;

  //! Identificador de intervalo de abertura de semáforo.
  /*! Descreve o período em que o semáforo ficará aberto. */
  int tempoIntervalo;

  //! Vetor que armazena as probabilidades de troca de pista. */
  /*! Descreve numericamente as probabilidades de troca de pista em um dado
   * semáforo.
   */
  int* probabilidades;

  //! Identifica o próximo evento que o semáforo abrirá.
  /*! Descreve numericamente o tempo do próximo evento em que o semáforo vai
   * abrir.
   */
  int tempoQueVaiAbrir;

  //! Identifica o estado de abertura do semáforo.
  /*! Descreve se o semáforo está aberto ou fechado. */
  bool aberto;

 public:
  //! Construtor.
  /*! Construtor do objeto que leva todos os atributos descritos
   * acima para frisar a variabilidade do semáforo.
   */
  Semaforo(bool _aberto, Pista* arranjo[], int* _probabilidades,
           int _tempoIntervalo);

  //! Método que troca o carro de pista.
  /*!
   * \return a pista para qual o carro foi trocado.
   */
  Pista* passaCarro();

  //! Método que troca o estado de semáforo.
  /*!
   * \param tempoAtual o tempo do evento que denota o estado do semáforo.
   */
  void trocarAberto(int tempoAtual);

  //! Método que calcula o próximo evento do semáforo.
  /*!
   * \param tempoAtual o tempo do evento que denota o estado do semáforo.
   * \return um inteiro.
   */
  int calculeProximoEvento(int tempoAtual);

  //! Método que calcula a probabilidade do carro trocar de pista.
  /*!
   * \param carro o carro que possui as probabilidades.
   * \return um inteiro.
   */
  int calculaProbabilidade(Carro* carro);

  //! Método que retorna o intervalo de abertura do semáforo.
  /*!
   * \return um inteiro.
   * \sa retornaPistaLocal(), retornarTempoQueVaiAbrir()
   */
  int retornaIntervalo();

  //! Método que retorna a pista que está aberta para passagem.
  /*!
   * \return a pista que está aberta.
   * \sa retornaIntervalo(), retornaTempoQueVaiAbrir()
   */
  Pista* retornaPistaLocal();

  //! Método que retorna o tempo do próximo evento de abertura.
  /*!
   * \return um inteiro.
   * \sa retornaIntervalo(), retornaPistaLocal()
   */
  int retornarTempoQueVaiAbrir();
};

Semaforo::Semaforo(bool _aberto, Pista* arranjo[], int* _probabilidades,
                   int _tempoIntervalo) {
  pistas = new Lista<Pista*>(3);
  probabilidades = _probabilidades;
  tempoIntervalo = _tempoIntervalo;
  tempoQueVaiAbrir = 0;
  aberto = _aberto;
  pistaLocal = arranjo[0];
  for (int i = 1; i < 4; i++) {
    pistas->adiciona(arranjo[i]);
  }
}

Pista* Semaforo::passaCarro() {
  Carro* carro = pistaLocal->primeiro();
  int pistaEscolhida = calculaProbabilidade(carro);
  Pista* proxima = pistas->retornaDado(pistaEscolhida);
  if (!aberto) {
    throw ExcecaoSinalVermelho();
  }
  if (!proxima->estaCheia(carro)) {
    pistaLocal->removeCarro();
    proxima->adicionaCarro(carro);
    return proxima;
  }
  proxima = pistaLocal;
  return proxima;
}

void Semaforo::trocarAberto(int tempoAtual) {
  if (aberto) {
    calculeProximoEvento(tempoAtual);
  }
  aberto = !aberto;
}

int Semaforo::calculeProximoEvento(int tempoAtual) {
  return (tempoAtual + tempoIntervalo);
}

int Semaforo::calculaProbabilidade(Carro* carro) {
  int* prob = probabilidades;
  int numPistas = pistas->getTamanho();
  int probabilidadeDoCarro = carro->getProbabilidade();
  int valorComp[numPistas];
  valorComp[0] = prob[0];
  for (int i = 1; i < numPistas; i++) {
    valorComp[i] = valorComp[i - 1] + prob[i];
  }
  for (int i = 0; i < numPistas; i++) {
    if (probabilidadeDoCarro <= valorComp[i]) {
      return i;
    }
  }
  return -1;
}

int Semaforo::retornaIntervalo() {
  return tempoIntervalo;
}

Pista* Semaforo::retornaPistaLocal() {
  return pistaLocal;
}

int Semaforo::retornarTempoQueVaiAbrir() {
  return tempoQueVaiAbrir;
}

#endif
