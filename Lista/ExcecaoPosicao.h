#ifndef EXCECAOPOSICAO_H_
#define EXCECAOPOSICAO_H_
#include <exception>

using namespace std;

class ExcecaoPosicao : public exception {
 public:
    //! Método responsável por descrever o erro relacionado à exceção.
 	/*! 
 	* \return um char*.
 	*/

	virtual const char* what() const throw() {
		return("Sua lista não contém essa posição!");
	}
};

#endif
