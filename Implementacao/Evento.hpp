#ifndef EVENTO_HPP_
#define EVENTO_HPP_
#include "Linked/ListaEnc.hpp"

class Evento {
public:
  int tempo;
  int tipo;
  void *objeto;
  void *relacionado;

  Evento(int _tempo, void* _objeto, void* _relacionado, int _tipo) {
    tempo = _tempo;
    objeto = _objeto;
    tipo = _tipo;
    relacionado = _relacionado;
  }

  int getTipo() {
    return tipo;
  }

  int getTempo() const {
    return tempo;
  }

  void* getObjeto() {
    return objeto;
  }
  
  void* getRelacionado() {
    return relacionado;
  }

};

#endif