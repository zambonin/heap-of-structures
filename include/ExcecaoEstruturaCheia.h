//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe de exceção para estrutura cheia.
/*! Uma classe que trata exceções quando a estrutura linear
 * está com seu número máximo de elementos.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 28/08/14
 * \version 1.1
 */

#ifndef EXCECAOESTRUTURACHEIA_H_
#define EXCECAOESTRUTURACHEIA_H_
#include <exception>

class ExcecaoEstruturaCheia : public std::exception {
 public:
  //! Método responsável por descrever o erro relacionado à exceção.
  /*!
   * \return um char*.
   */
  virtual const char* what() const throw() {
    return ("Sua estrutura linear está cheia!");
  }
};

#endif
