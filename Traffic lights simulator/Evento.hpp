//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve o objeto "evento".
/*! Classe que trata das operações relacionadas ao objeto "evento".
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.0
 */

#ifndef EVENTO_HPP_
#define EVENTO_HPP_
#include "Linked/ListaEnc.hpp"

class Evento {
 private:
  //! Identificador de tempo.
  /*! Descreve o tempo discreto do evento. */
  int tempo;

  //! Identificador de tipo.
  /*! Descreve o tipo do evento: 0 para a criação de um carro,
   * 1 para a mudança de estado do semáforo, 2 para a chegada
   * do carro no semáforo e 3 para a deleção do carro.
   */
  int tipo;

  //! Identificador de objeto.
  /*! Descreve o objeto característico do evento atual. */
  void* objeto;

  //! Identificador de objeto relacionado.
  /*! Descreve o objeto relacionado à característica principal
   * do evento, apresentando mais informações sobre tal.
   */
  void* relacionado;

 public:
  //! Construtor.
  /*! Construtor do objeto que leva todos os atributos descritos
   * acima para frisar a variabilidade do evento.
   */
  Evento(int _tempo, void* _objeto, void* _relacionado, int _tipo);

  //! Método que retorna o tipo do evento.
  /*!
   * \return um inteiro.
   */
  int getTipo();

  //! Método que retorna o tempo constante do evento.
  /*!
   * \return um inteiro.
   */
  int getTempo() const;

  //! Método que retorna um objeto de qualquer tipo para descrever o evento.
  /*
   * \return um ponteiro void (qualquer tipo de objeto).
   */
  void* getObjeto();

  //! Método que retorna o objeto relacionado ao evento principal.
  /*
   * \return um ponteiro void (qualquer tipo de objeto).
   */
  void* getRelacionado();
};

Evento::Evento(int _tempo, void* _objeto, void* _relacionado, int _tipo) {
  tempo = _tempo;
  objeto = _objeto;
  tipo = _tipo;
  relacionado = _relacionado;
}

int Evento::getTipo() {
  return tipo;
}

int Evento::getTempo() const {
  return tempo;
}

void* Evento::getObjeto() {
  return objeto;
}

void* Evento::getRelacionado() {
  return relacionado;
}

#endif