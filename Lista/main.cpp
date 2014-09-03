#include <iostream>
#include "Lista.hpp"

using namespace std;

int main() {
	Lista<char>* lista = new Lista<char>(10);
	lista->adiciona(2);
	lista->adiciona('a');
	cout << lista->contem('a') << endl;
	lista->retiraDoInicio();
	cout << lista->retira() << endl;
	lista->adiciona(4);
	lista->adiciona(5);
	lista->adiciona(6);
	lista->adiciona(6);
	lista->adiciona(6);
	lista->adiciona(6);
	lista->adiciona(6);
	lista->adiciona(6);
	lista->adiciona(6);
	return 0;
}