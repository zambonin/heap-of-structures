//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe de exceção para árvores AVL.
/*! Uma classe que trata exceções variadas da árvore AVL.
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 19/09/14
*	\version 1.0
*/

#ifndef EXCECAOAVL_H_
#define EXCECAOAVL_H_
#include <exception>

class ExcecaoAVL {
	public:
    //! Método responsável por descrever o erro relacionado à exceção.
 	/*! 
 	* \return um char*.
 	*/

	virtual const char* what() const throw() {
		return("Sua árvore AVL não contém esse nodo "
			"e você não pode inserir dados iguais!");
	}
};

#endif
