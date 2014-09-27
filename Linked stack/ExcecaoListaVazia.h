//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe de exceção para lista vazia.
/*! Uma classe que trata exceções quando a lista
*	não tem elementos.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 02/09/14
*	\version 1.0
*/

#ifndef EXCECAOLISTAVAZIA_H_
#define EXCECAOLISTAVAZIA_H_
#include <exception>

class ExcecaoListaVazia {
 public:
    //! Método responsável por descrever o erro relacionado à exceção.
 	/*! 
 	* \return um char*.
 	*/

	virtual const char* what() const throw() {
		return("Sua lista está vazia!");
	}
};

#endif
