#include <Semaforo.h>

Semaforo::Semaforo(bool _aberto, Pista *arranjo[], int *_probabilidades,
                   int _tempoIntervalo) {
  pistas = new Lista<Pista *>(3);
  probabilidades = _probabilidades;
  tempoIntervalo = _tempoIntervalo;
  tempoQueVaiAbrir = 0;
  aberto = _aberto;
  pistaLocal = arranjo[0];
  for (int i = 1; i < 4; i++) {
    pistas->adiciona(arranjo[i]);
  }
}

Pista *Semaforo::passaCarro() {
  Carro *carro = pistaLocal->primeiro();
  int pistaEscolhida = calculaProbabilidade(carro);
  Pista *proxima = pistas->retornaDado(pistaEscolhida);
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

int Semaforo::calculaProbabilidade(Carro *carro) {
  int *prob = probabilidades;
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

int Semaforo::retornaIntervalo() { return tempoIntervalo; }

Pista *Semaforo::retornaPistaLocal() { return pistaLocal; }

int Semaforo::retornarTempoQueVaiAbrir() { return tempoQueVaiAbrir; }
