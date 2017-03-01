//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve o objeto "carro".
/*! Classe que trata das operações relacionadas ao objeto "carro".
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.1
 */

#ifndef CARRO_H_
#define CARRO_H_
#include <cstdlib>

class Carro {
 private:
  //! Identificador de tamanho.
  /*! Descreve o tamanho aleatório do carro. */
  int tamanho;

  //! Identificador da probabilidade.
  /*! Descreve o número a designar o caminho a ser tomado pelo carro. */
  int probabilidade;

 public:
  //! Construtor.
  /*! Define o tamanho e a probabilidade de caminho do carro. */
  Carro();

  //! Método que retorna a probabilidade do caminho a ser escolhido pelo carro.
  /*
   * \return um inteiro.
   */
  int getProbabilidade();

  //! Método que retorna o tamanho variável do carro.
  /*
   * \return um inteiro.
   */
  int getTamanho();
};

#endif
