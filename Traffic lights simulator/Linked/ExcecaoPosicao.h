//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe de exceção para posições inválidas em estruturas.
/*! Uma classe que trata exceções quando a lista 
*	tenta manipular um elemento em uma posição inexistente.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 03/09/14
*	\version 1.0
*/

#ifndef EXCECAOPOSICAO_H_
#define EXCECAOPOSICAO_H_
#include <exception>

class ExcecaoPosicao {
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
