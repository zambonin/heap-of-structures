//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe de exceção para dados inexistentes em estruturas.
/*! Uma classe que trata exceções quando a lista
*	não encontra o elemento solicitado.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 03/09/14
*	\version 1.0
*/

#ifndef EXCECAODADONAOENCONTRADO_H_
#define EXCECAODADONAOENCONTRADO_H_
#include <exception>

class ExcecaoDadoNaoEncontrado {
	public:
    //! Método responsável por descrever o erro relacionado à exceção.
 	/*! 
 	* \return um char*.
 	*/

	virtual const char* what() const throw() {
		return("Sua lista não contém esse dado!");
	}
};

#endif
