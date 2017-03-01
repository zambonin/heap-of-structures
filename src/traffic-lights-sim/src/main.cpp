#include "Sistema.h"

int main(int argc, char **argv) {
  srand(time(nullptr));
  if (argc != 3) {
    std::cout << "Usage: ./simulator total_time semaphore_delay" << std::endl;
    return 1;
  }
  int tempoDeExecucao = atoi(argv[1]), tempoAberturaSemaforo = atoi(argv[2]);
  if (tempoAberturaSemaforo > tempoDeExecucao) {
    std::cout << "Semaphore delay is too high!" << std::endl;
    return 1;
  }
  auto sistema = new Sistema(tempoAberturaSemaforo, tempoDeExecucao);
  sistema->iniciar();
  return 0;
}
