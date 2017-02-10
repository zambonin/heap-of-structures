//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a lista de eventos.
/*! Classe que gerencia e organiza a lista encadeada de eventos.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 09/10/14
 * \version 1.0
 */

#ifndef LISTADEEVENTOS_HPP_
#define LISTADEEVENTOS_HPP_
#include "Evento.hpp"

class ListaDeEventos : public ListaEnc<Evento*> {
 public:
  //! Método de comparação de eventos.
  /*! Sobrescreve o método principal e ordena os eventos
   * de acordo com seu tempo corretamente.
   */
  bool maior(Evento* dado1, Evento* dado2) const;
};

bool ListaDeEventos::maior(Evento* dado1, Evento* dado2) const {
  return dado1->getTempo() > dado2->getTempo();
}

#endif
