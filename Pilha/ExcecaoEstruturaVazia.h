//! Classe de exceção para estrutura vazia.
/*! Uma classe que trata exceções quando a estrutura linear
*	não tem elementos.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 28/08/14
*	\version 1.0
*/

#ifndef EXCECAOESTRUTURAVAZIA_H_
#define EXCECAOESTRUTURAVAZIA_H_
#include <exception>

using namespace std;

class ExcecaoEstruturaVazia : public exception {
 public:
    //! Método responsável por descrever o erro relacionado à exceção.
 	/*! 
 	* \return um char*.
 	*/

	virtual const char* what() const throw() {
		return("Sua estrutura linear está vazia!");
	}
};

#endif
