#ifndef EXCECAODADONAOENCONTRADO_H_
#define EXCECAODADONAOENCONTRADO_H_
#include <exception>

class ExcecaoDadoNaoEncontrado : public exception {
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
