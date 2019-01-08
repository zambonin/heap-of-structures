#include "Pista.h"

Pista::Pista(int _tamanho, int _velocidadeMedia, int _intervaloCriacao,
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

void Pista::adicionaCarro(Carro *carro) {
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
  return (tempoCriacaoNeg + (rand() % (tempoCriacaoPos - 2 + 1)) + tempoAtual);
}

int Pista::tempoDeChegada(int tempoNasceu) {
  return tempoNasceu + tempoChegada;
}

int Pista::retornaCarrosQuePassaram() { return carrosQuePassaram; }

int Pista::retornaCarrosQueEntraram() { return carrosQueEntraram; }

bool Pista::estaCheia(Carro *carro) {
  return espacoOcupado + carro->getTamanho() > tamanho;
}

bool Pista::eFonte() { return fonte; }

bool Pista::eSumidouro() { return sumidouro; }
