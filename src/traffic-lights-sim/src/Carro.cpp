#include "Carro.h"

Carro::Carro() {
  tamanho = (2 + (rand() % (6 - 2 + 1))) + 3;
  probabilidade = (rand() % 100) + 1;
}

int Carro::getTamanho() {
  return tamanho;
}

int Carro::getProbabilidade() {
  return probabilidade;
}
