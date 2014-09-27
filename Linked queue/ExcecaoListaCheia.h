//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe de exceção para lista cheia.
/*! Uma classe que trata exceções quando a lista
*	está com seu número máximo de elementos.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 02/09/14
*	\version 1.0
*/

#ifndef EXCECAOLISTACHEIA_H_
#define EXCECAOLISTACHEIA_H_
#include <exception>

class ExcecaoListaCheia {
 public:
    //! Método responsável por descrever o erro relacionado à exceção.
 	/*! 
 	* \return um char*.
 	*/

	virtual const char* what() const throw() {
		return("Sua lista está cheia!");
	}
};

#endif
