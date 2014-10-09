#ifndef EXCECAOSINALVERMELHO_HPP_
#define EXCECAOSINALVERMELHO_HPP_
#include <exception>

class ExcecaoSinalVermelho : public std::exception {
 public:
		virtual const char* mostrarMensagem() const throw() {
			return "Exceção Sinal Vermelho: o carro chegou no semáforo mas este está vermelho!";
		}
};

#endif
