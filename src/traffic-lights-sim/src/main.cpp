#include "Sistema.h"

int main(int /*argc*/, char **argv) {
  srand(time(nullptr));
  int tempoDeExecucao = atoi(argv[1]), tempoAberturaSemaforo = atoi(argv[2]);
  if (tempoAberturaSemaforo > tempoDeExecucao) {
    return 1;
  }
  auto sistema = new Sistema(tempoAberturaSemaforo, tempoDeExecucao);
  sistema->iniciar();
  return 0;
}
