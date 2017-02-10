#include <Sistema.h>

Sistema::Sistema(int _tempoSemaforo, int _tempoDeExecucao)
  : tempoSemaforo(_tempoSemaforo), tempoDeExecucao(_tempoDeExecucao) {
  this->semaforos = new ListaCirc<Semaforo*>();
  this->pistas = new ListaCirc<Pista*>();
  this->listaEventos = new ListaDeEventos();
  tempoAtual = 0;
  instanciar();
}

void Sistema::instanciar() {
  auto n1sul = new Pista(500, 60, 5, 20);
  auto n1norte = new Pista(500, 60, 0, 0);
  auto n2sul = new Pista(500, 40, 5, 20);
  auto n2norte = new Pista(500, 40, 0, 0);
  auto o1oeste = new Pista(2000, 80, 0, 0);
  auto o1leste = new Pista(2000, 80, 2, 10);
  auto s1sul = new Pista(500, 60, 0, 0);
  auto s1norte = new Pista(500, 60, 7, 30);
  auto s2sul = new Pista(500, 40, 0, 0);
  auto s2norte = new Pista(500, 40, 15, 60);
  auto l1leste = new Pista(400, 30, 0, 0);
  auto l1oeste = new Pista(400, 30, 2, 10);
  auto c1oeste = new Pista(300, 60, 0, 1);
  auto c1leste = new Pista(300, 60, 0, 1);

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
  auto so1leste = new Semaforo(true, static_cast<Pista**>(vetorPista1),
                               static_cast<int*>(probPista1), tempoSemaforo);

  Pista* vetorPista2[4] = {c1leste, l1leste, n2norte, s2sul};
  int probPista2[3] = {40, 30, 30};
  auto sc1leste = new Semaforo(true, static_cast<Pista**>(vetorPista2),
                               static_cast<int*>(probPista2), tempoSemaforo);

  Pista* vetorPista3[4] = {c1oeste, o1oeste, s1sul, n1norte};
  int probPista3[3] = {40, 30, 30};
  auto sc1oeste = new Semaforo(false, static_cast<Pista**>(vetorPista3),
                               static_cast<int*>(probPista3), tempoSemaforo);

  Pista* vetorPista4[4] = {s1norte, n1norte, o1oeste, c1leste};
  int probPista4[3] = {10, 10, 80};
  auto ss1norte = new Semaforo(false, static_cast<Pista**>(vetorPista4),
                               static_cast<int*>(probPista4), tempoSemaforo);

  Pista* vetorPista5[4] = {s2norte, n2norte, c1oeste, l1leste};
  int probPista5[3] = {30, 30, 40};
  auto ss2norte = new Semaforo(false, static_cast<Pista**>(vetorPista5),
                               static_cast<int*>(probPista5), tempoSemaforo);

  Pista* vetorPista6[4] = {n1sul, s1sul, c1leste, o1oeste};
  int probPista6[3] = {10, 80, 10};
  auto sn1sul = new Semaforo(false, static_cast<Pista**>(vetorPista6),
                             static_cast<int*>(probPista6), tempoSemaforo);

  Pista* vetorPista7[4] = {n2sul, s2sul, l1oeste, c1oeste};
  int probPista7[3] = {30, 40, 30};
  auto sn2sul = new Semaforo(false, static_cast<Pista**>(vetorPista7),
                             static_cast<int*>(probPista7), tempoSemaforo);

  Pista* vetorPista8[4] = {l1oeste, c1oeste, s2sul, n2norte};
  int probPista8[3] = {30, 30, 40};
  auto sl1oeste = new Semaforo(false, static_cast<Pista**>(vetorPista8),
                               static_cast<int*>(probPista8), tempoSemaforo);

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
      atual = static_cast<Pista*>(
        listaEventos->retornaDado(i)->getRelacionado());
      semaforo = procurarPorSemaforo(atual);
      tempoProximoEvento = atual->tempoDeChegada(tempoChegada);
      if (tempoProximoEvento <= tempoDeExecucao) {
        evento = new Evento(tempoProximoEvento, semaforo, nullptr, 2);
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
        evento = new Evento(tempoProximoEvento, atual, nullptr, 1);
        evento2 = new Evento(tempoProximoEvento, proximo, nullptr, 1);
        listaEventos->adicionaEmOrdem(evento);
        listaEventos->adicionaEmOrdem(evento2);
      }
      tempoInterno = tempoProximoEvento;
    }
  }
}

void Sistema::executarCarroChegouNoSemaforo(Evento* eventoAtual) {
  Evento* evento;
  Semaforo* semaforo = static_cast<Semaforo*>(eventoAtual->getObjeto());
  tempoAtual = eventoAtual->getTempo();
  int tempoProximoEvento = -1;
  try {
    Pista* proximaPista = semaforo->passaCarro();
    if (proximaPista == semaforo->retornaPistaLocal()) {
      if (tempoAtual < semaforo->retornarTempoQueVaiAbrir()) {
        tempoProximoEvento = tempoAtual + 1;
        evento = new Evento(tempoProximoEvento, semaforo, nullptr, 2);
      } else {
        tempoProximoEvento = semaforo->retornarTempoQueVaiAbrir() + 1;
        evento = new Evento(tempoProximoEvento, semaforo, nullptr, 2);
      }
    } else {
      if (proximaPista->eSumidouro()) {
        tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
        evento = new Evento(tempoProximoEvento, proximaPista, nullptr, 3);
      } else {
        Semaforo* semaforo = procurarPorSemaforo(proximaPista);
        tempoProximoEvento = proximaPista->tempoDeChegada(tempoAtual);
        evento = new Evento(tempoProximoEvento, semaforo, nullptr, 2);
      }
    }
  } catch (std::exception const &e) {
    tempoProximoEvento = semaforo->retornarTempoQueVaiAbrir() + 1;
    evento = new Evento(tempoProximoEvento, semaforo, nullptr, 2);
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
  return nullptr;
}

void Sistema::executarEventos() {
  for (int i = 0; i < listaEventos->getTamanho(); i++) {
    Evento* eventoAtual = listaEventos->retornaDado(i);
    if (tempoAtual >= tempoDeExecucao) {
      break;
    }
    switch (eventoAtual->getTipo()) {
      case 0: {
        Pista* pista = static_cast<Pista*>(eventoAtual->getRelacionado());
        Carro* carro = static_cast<Carro*>(eventoAtual->getObjeto());
        pista->adicionaCarro(carro);
        tempoAtual = eventoAtual->getTempo();
        break;
      }
      case 1: {
        Semaforo* semaforo = static_cast<Semaforo*>(eventoAtual->getObjeto());
        semaforo->trocarAberto(tempoAtual);
        tempoAtual = eventoAtual->getTempo();
        break;
      }
      case 2: {
        executarCarroChegouNoSemaforo(eventoAtual);
        break;
      }
      case 3: {
        Pista* pista = static_cast<Pista*>(eventoAtual->getObjeto());
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

float percent(int a, int b) {
  return static_cast<float>(a) * 100 / static_cast<float>(b);
}

void Sistema::finalizarPrograma() {
  contarCarros();
  std::cout << carrosQueEntraram << " carros entraram no sistema." << std::endl;
  std::cout << carrosQuePassaram << " carros passaram pelo sistema."
            << std::endl;
  std::cout << "Vazão: "
            << percent(carrosQuePassaram, carrosQueEntraram)
            << "%." << std::endl;
  std::cout << "Ratio: "
            << percent(carrosQuePassaram, tempoDeExecucao)
            << " carros por segundo" << std::endl;
}
