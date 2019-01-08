#include "Evento.h"

Evento::Evento(int _tempo, void *_objeto, void *_relacionado, int _tipo) {
  tempo = _tempo;
  objeto = _objeto;
  tipo = _tipo;
  relacionado = _relacionado;
}

int Evento::getTipo() { return tipo; }

int Evento::getTempo() const { return tempo; }

void *Evento::getObjeto() { return objeto; }

void *Evento::getRelacionado() { return relacionado; }

bool ListaDeEventos::maior(Evento *dado1, Evento *dado2) const {
  return dado1->getTempo() > dado2->getTempo();
}
