//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a exceção de sinal vermelho.
/*! Classe que trata da exceção que ocorre quando um carro chega em um sinal
* vermelho.
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 09/10/14
* \version 1.0
*/

#ifndef EXCECAOSINALVERMELHO_HPP_
#define EXCECAOSINALVERMELHO_HPP_
#include <exception>

class ExcecaoSinalVermelho : public std::exception {
 public:
  //! Método responsável por descrever o erro relacionado à exceção.
  /*!
  * \return um char*.
  */

  virtual const char* mostrarMensagem() const throw() {
    return "O semáforo está vermelho.";
  }
};

#endif
