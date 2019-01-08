//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve o sistema de tráfego.
/*! Classe que gerencia todos os semáforos, pistas e carros.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.1
 */

#ifndef SISTEMA_H_
#define SISTEMA_H_
#include "Evento.h"
#include "ListaCirc.hpp"
#include "Semaforo.h"
#include <iostream>

class Sistema {
public:
  //! Lista circular de semáforos.
  /*! Descreve a lista de semáforos gerenciada pelo sistema. */
  ListaCirc<Semaforo *> *semaforos{};

  //! Lista circular de pistas.
  /*! Descreve a lista de pistas geral gerenciada pelo sistema. */
  ListaCirc<Pista *> *pistas{};

  //! Lista encadeada de eventos.
  /*! Descreve a lista de eventos gerenciada pelo sistema. */
  ListaDeEventos *listaEventos;

  //! Identificador de tempo atual.
  /*! Descreve o tempo do evento atual no sistema. */
  int tempoAtual;

  //! Identificador de tempo do evento do semáforo.
  /*! Descreve o tempo do evento do semáforo no sistema. */
  int tempoSemaforo;

  //! Identificador de tempo de execução do sistema.
  /*! Descreve o tempo total que o programa será executado. */
  int tempoDeExecucao;

  //! Contador de carros que passaram por semáforos.
  /*! Descreve o número de carros que passaram por qualquer
   * semáforo do sistema.
   */
  int carrosQuePassaram{};

  //! Contador de carros que entraram no sistema.
  /*! Descreve o número de carros total que foram criados
   * por qualquer pista.
   */
  int carrosQueEntraram{};

  //! Construtor.
  /*! Construtor do sistema que leva o tempo de abertura do semáforo e o tempo
   * de execução total do programa.
   */
  Sistema(int _tempoSemaforo, int _tempoDeExecucao);

  //! Método que cria todas as pistas e semáforos de acordo com os dados
  //! fornecidos.
  /*!
   * \sa iniciar()
   */
  void instanciar();

  //! Método que gerencia a inicialização dos eventos do sistema inteiro.
  /*!
   * \sa gerarEventosCarro(), gerarEventosChegadaSemaforo(),
   * gerarEventosAberturaSemaforos()
   */
  void iniciar();

  //! Método que gera aleatoriamente os tempos e cria
  //! os eventos respectivos com relação ao objeto "carro".
  /*!
   * \sa gerarEventosChegadaSemaforo(), gerarEventosAberturaSemaforos()
   */
  void gerarEventosCarro();

  //! Método que gera aleatoriamente os tempos e cria
  //! os eventos respectivos com relação à chegada do carro no semáforo.
  /*!
   * \sa gerarEventosCarro(), gerarEventosAberturaSemaforos()
   */
  void gerarEventosChegadaSemaforo();

  //! Método que gera aleatoriamente os tempos e cria
  //! os eventos respectivos com relação à abertura dos semáforos.
  /*!
   * \sa gerarEventosCarro(), gerarEventosChegadaSemaforo()
   */
  void gerarEventosAberturaSemaforos();

  //! Determina o próximo evento do carro quando ele chega no semáforo.
  /*!
   * \param eventoAtual o evento que é usado para determinar o próximo evento.
   */
  void executarCarroChegouNoSemaforo(Evento *eventoAtual);

  //! Determina o semáforo a ser utilizado por uma pista no programa.
  /*!
   * \param pista o ponteiro da pista a ser utilizada.
   * \return o ponteiro do semáforo a ser utilizado.
   */
  Semaforo *procurarPorSemaforo(Pista *pista);

  //! Executa todos os eventos criados ao longo do programa.
  /*!
   * \sa iniciar()
   */
  void executarEventos();

  //! Método que executa a contagem dos carros para apresentação no console.
  /*!
   * \sa finalizarPrograma()
   */
  void contarCarros();

  //! Método que escreve na tela informações consideradas necessárias para o
  //! entendimento da saída do programa.
  /*!
   * \sa contarCarros()
   */
  void finalizarPrograma();
};

#endif
