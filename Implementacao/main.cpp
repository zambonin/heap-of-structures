#include <iostream>
#include <stdlib.h>
#include "Sistema.hpp"

int main() {
	system("clear");
	srand(time(0));
	int tempoDeExecucao, tempoAberturaSemaforo;
	std::cout << "Informe o tempo de execução em segundos: " << std::endl;
	std::cin >> tempoDeExecucao;
	std::cout << "Informe o tempo de abertura do semáforo em segundos: " << std::endl;
	std::cin >> tempoAberturaSemaforo;
	Sistema *sistema = new Sistema(tempoAberturaSemaforo, tempoDeExecucao);
	return sistema->iniciar();
}