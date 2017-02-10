//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve o sistema de tráfego.
/*! Classe que gerencia todos os semáforos, pistas e carros.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.0
 */

#ifndef SISTEMA_HPP_
#define SISTEMA_HPP_
#include "Linked/ListaCirc.hpp"
#include "ListaDeEventos.hpp"
#include "Semaforo.hpp"
#include <iostream>

class Sistema {
 public:
  //! Lista circular de semáforos.
  /*! Descreve a lista de semáforos gerenciada pelo sistema. */
  ListaCirc<Semaforo*>* semaforos;

  //! Lista circular de pistas.
  /*! Descreve a lista de pistas geral gerenciada pelo sistema. */
  ListaCirc<Pista*>* pistas;

  //! Lista encadeada de eventos.
  /*! Descreve a lista de eventos gerenciada pelo sistema. */
  ListaDeEventos* listaEventos;

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
  int carrosQuePassaram;

  //! Contador de carros que entraram no sistema.
  /*! Descreve o número de carros total que foram criados
   * por qualquer pista.
   */
  int carrosQueEntraram;

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
  void executarCarroChegouNoSemaforo(Evento* eventoAtual);

  //! Determina o semáforo a ser utilizado por uma pista no programa.
  /*!
   * \param pista o ponteiro da pista a ser utilizada.
   * \return o ponteiro do semáforo a ser utilizado.
   */
  Semaforo* procurarPorSemaforo(Pista* pista);

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

Sistema::Sistema(int _tempoSemaforo, int _tempoDeExecucao) {
  this->semaforos = new ListaCirc<Semaforo*>();
  this->pistas = new ListaCirc<Pista*>();
  this->listaEventos = new ListaDeEventos();
  tempoAtual = 0;
  tempoSemaforo = _tempoSemaforo;
  tempoDeExecucao = _tempoDeExecucao;
  instanciar();
}

void Sistema::instanciar() {
  Pista* n1sul = new Pista(500, 60, 5, 20);
  Pista* n1norte = new Pista(500, 60, 0, 0);
  Pista* n2sul = new Pista(500, 40, 5, 20);
  Pista* n2norte = new Pista(500, 40, 0, 0);
  Pista* o1oeste = new Pista(2000, 80, 0, 0);
  Pista* o1leste = new Pista(2000, 80, 2, 10);
  Pista* s1sul = new Pista(500, 60, 0, 0);
  Pista* s1norte = new Pista(500, 60, 7, 30);
  Pista* s2sul = new Pista(500, 40, 0, 0);
  Pista* s2norte = new Pista(500, 40, 15, 60);
  Pista* l1leste = new Pista(400, 30, 0, 0);
  Pista* l1oeste = new Pista(400, 30, 2, 10);
  Pista* c1oeste = new Pista(300, 60, 0, 1);
  Pista* c1leste = new Pista(300, 60, 0, 1);

  pistas->adiciona(n1sul);
  pistas->adiciona(n1norte);
  pistas->adiciona(n2sul);
  pistas->adiciona(n2norte);
  pistas->adiciona(o1oeste);
  pistas->adiciona(o1leste);
  pistas->adiciona(s1sul);
  pistas->adiciona(s1norte);
  pistas->adiciona(s2sul);
  pistas->adiciona(s2norte);
  pistas->adiciona(l1leste);
  pistas->adiciona(l1oeste);
  pistas->adiciona(c1oeste);
  pistas->adiciona(c1leste);

  Pista* vetorPista1[4] = {o1leste, c1leste, n1norte, s1sul};
  int probPista1[3] = {80, 10, 10};
  Semaforo* so1leste =
      new Semaforo(true, vetorPista1, probPista1, tempoSemaforo);

  Pista* vetorPista2[4] = {c1leste, l1leste, n2norte, s2sul};
  int probPista2[3] = {40, 30, 30};
  Semaforo* sc1leste =
      new Semaforo(true, vetorPista2, probPista2, tempoSemaforo);

  Pista* vetorPista3[4] = {c1oeste, o1oeste, s1sul, n1norte};
  int probPista3[3] = {40, 30, 30};
  Semaforo* sc1oeste =
      new Semaforo(false, vetorPista3, probPista3, tempoSemaforo);

  Pista* vetorPista4[4] = {s1norte, n1norte, o1oeste, c1leste};
  int probPista4[3] = {10, 10, 80};
  Semaforo* ss1norte =
      new Semaforo(false, vetorPista4, probPista4, tempoSemaforo);

  Pista* vetorPista5[4] = {s2norte, n2norte, c1oeste, l1leste};
  int probPista5[3] = {30, 30, 40};
  Semaforo* ss2norte =
      new Semaforo(false, vetorPista5, probPista5, tempoSemaforo);

  Pista* vetorPista6[4] = {n1sul, s1sul, c1leste, o1oeste};
  int probPista6[3] = {10, 80, 10};
  Semaforo* sn1sul =
      new Semaforo(false, vetorPista6, probPista6, tempoSemaforo);

  Pista* vetorPista7[4] = {n2sul, s2sul, l1oeste, c1oeste};
  int probPista7[3] = {30, 40, 30};
  Semaforo* sn2sul =
      new Semaforo(false, vetorPista7, probPista7, tempoSemaforo);

  Pista* vetorPista8[4] = {l1oeste, c1oeste, s2sul, n2norte};
  int probPista8[3] = {30, 30, 40};
  Semaforo* sl1oeste =
      new Semaforo(false, vetorPista8, probPista8, tempoSemaforo);

  semaforos->adiciona(sn1sul);
  semaforos->adiciona(sn2sul);
  semaforos->adiciona(sc1oeste);
  semaforos->adiciona(sl1oeste);
  semaforos->adiciona(ss1norte);
  semaforos->adiciona(ss2norte);
  semaforos->adiciona(so1leste);
  semaforos->adiciona(sc1leste);
}

void Sistema::iniciar() {
  gerarEventosCarro();
  gerarEventosChegadaSemaforo();
  gerarEventosAberturaSemaforos();
  executarEventos();
}

void Sistema::gerarEventosCarro() {
  Pista* pistaAtual;
  int tempoInterno;
  int tempoProximoEvento;
  Evento* evento;
  for (int i = 0; i < pistas->getTamanho(); i++) {
    pistaAtual = pistas->mostra(i);
    if (pistaAtual->eFonte()) {
      tempoInterno = tempoAtual;
      while (tempoInterno < tempoDeExecucao) {
        tempoProximoEvento = pistaAtual->calculeProximoEvento(tempoInterno);
        if (tempoProximoEvento <= tempoDeExecucao) {
          evento = new Evento(tempoProximoEvento, new Carro(), pistaAtual, 0);
          listaEventos->adicionaEmOrdem(evento);
          tempoInterno = tempoProximoEvento;
        } else {
          break;
        }
      }
    }
  }
}

void Sistema::gerarEventosChegadaSemaforo() {
  Pista* atual;
  Semaforo* semaforo;
  Evento* evento;
  int tempoChegada, tempoProximoEvento;
  int tamanhoOriginal = listaEventos->getTamanho();
  for (int i = 0; i < tamanhoOriginal; i++) {
    if (listaEventos->retornaDado(i)->getTipo() == 0) {
      tempoChegada = listaEventos->retornaDado(i)->getTempo();
      atual = (Pista*)listaEventos->retornaDado(i)->getRelacionado();
      semaforo = procurarPorSemaforo(atual);
      tempoProximoEvento = atual->tempoDeChegada(tempoChegada);
      if (tempoProximoEvento <= tempoDeExecucao) {
        evento = new Evento(tempoProximoEvento, semaforo, 0, 2);
        listaEventos->adicionaEmOrdem(evento);
      }
    }
  }
}

void Sistema::gerarEventosAberturaSemaforos() {
  Semaforo* atual;
  Semaforo* proximo;
  Evento* evento;
  Evento* evento2;
  int tempoInterno, tempoProximoEvento;
  for (int i = 0; i < semaforos->getTamanho(); i += 2) {
    tempoInterno = tempoAtual;
    while (tempoInterno < tempoDeExecucao) {
      atual = semaforos->mostra(i);
      proximo = semaforos->mostra(i + 1);
      tempoProximoEvento = atual->calculeProximoEvento(tempoInterno);
      if (tempoProximoEvento <= tempoDeExecucao) {
        evento = new Evento(tempoProximoEvento, atual, 0, 1);
        evento2 = new Evento(tempoProximoEvento, proximo, 0, 1);
        listaEventos->adicionaEmOrdem(evento);
        listaEventos->adicionaEmOrdem(evento2);
      }
      tempoInterno = tempoProximoEvento;
    }
  }
}

void Sistema::executarCarroChegouNoSemaforo(Evento* eventoAtual) {
  Evento* evento;
  Semaforo* semaforo = (Semaforo*)eventoAtual->getObjeto();
  tempoAtual = eventoAtual->getTempo();
  int tempoProximoEvento = -1;
  try {
    Pista* proximaPista = semaforo->passaCarro();
    if (proximaPista == semaforo->retornaPistaLocal()) {
      if (tempoAtual < semaforo->retornarTempoQueVaiAbrir()) {
        tempoProximoEvento = tempoAtual + 1;
        evento = new Evento(tempoProximoEvento, semaforo, 0, 2);
      } else {
        tempoProximoEvento = semaforo->retornarTempoQueVaiAbrir() + 1;
        evento = new Evento(tempoProximoEvento, semaforo, 0, 2);
      }
    } else {
      if (proximaPista->eSumidouro()) {
        tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
        evento = new Evento(tempoProximoEvento, proximaPista, 0, 3);
      } else {
        Semaforo* semaforo = procurarPorSemaforo(proximaPista);
        tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
        evento = new Evento(tempoProximoEvento, semaforo, 0, 2);
      }
    }
  } catch (std::exception& e) {
    tempoProximoEvento = semaforo->retornarTempoQueVaiAbrir() + 1;
    evento = new Evento(tempoProximoEvento, semaforo, 0, 2);
  }
  if (tempoProximoEvento != -1 && tempoProximoEvento <= tempoDeExecucao) {
    listaEventos->adicionaEmOrdem(evento);
  }
}

Semaforo* Sistema::procurarPorSemaforo(Pista* pista) {
  for (int i = 0; i < semaforos->getTamanho(); i++) {
    Semaforo* atual = semaforos->mostra(i);
    if (atual->retornaPistaLocal() == pista) {
      return atual;
    }
  }
  return 0;
}

void Sistema::executarEventos() {
  for (int i = 0; i < listaEventos->getTamanho(); i++) {
    Evento* eventoAtual = listaEventos->retornaDado(i);
    if (tempoAtual >= tempoDeExecucao) {
      break;
    }
    switch (eventoAtual->getTipo()) {
      case 0: {
        Pista* pista = (Pista*)eventoAtual->getRelacionado();
        Carro* carro = (Carro*)eventoAtual->getObjeto();
        pista->adicionaCarro(carro);
        tempoAtual = eventoAtual->getTempo();
        break;
      }
      case 1: {
        Semaforo* semaforo = (Semaforo*)eventoAtual->getObjeto();
        semaforo->trocarAberto(tempoAtual);
        tempoAtual = eventoAtual->getTempo();
        break;
      }
      case 2: {
        executarCarroChegouNoSemaforo(eventoAtual);
        break;
      }
      case 3: {
        Pista* pista = (Pista*)eventoAtual->getObjeto();
        pista->removeCarro();
        tempoAtual = eventoAtual->getTempo();
        break;
      }
      default: {
        std::cout << "Nunca deve chegar aqui se tudo estiver correndo certo."
                  << std::endl;
      }
    }
    listaEventos->retiraEspecifico(eventoAtual);
  }
  finalizarPrograma();
}

void Sistema::contarCarros() {
  for (int i = 0; i < pistas->getTamanho(); i++) {
    Pista* pista = pistas->mostra(i);
    if (pista->eFonte()) {
      carrosQueEntraram = carrosQueEntraram + pista->retornaCarrosQueEntraram();
    } else {
      if (pista->eSumidouro()) {
        carrosQuePassaram =
            carrosQuePassaram + pista->retornaCarrosQuePassaram();
      }
    }
  }
}

void Sistema::finalizarPrograma() {
  contarCarros();
  std::cout << carrosQueEntraram << " carros entraram no sistema." << std::endl;
  std::cout << carrosQuePassaram << " carros passaram pelo sistema."
            << std::endl;
  std::cout << "Vazão: "
            << (((float)carrosQuePassaram) * 100) / ((float)carrosQueEntraram)
            << "%." << std::endl;
  std::cout << "Ratio: "
            << ((float)carrosQuePassaram * 100) / ((float)tempoDeExecucao)
            << " carros por segundo" << std::endl;
}

#endif
