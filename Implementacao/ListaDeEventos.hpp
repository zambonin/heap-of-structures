#ifndef LISTADEEVENTOS_HPP_
#define LISTADEEVENTOS_HPP_
#include "Evento.hpp"

class ListaDeEventos : public ListaEnc<Evento*> {
 public:
	ListaDeEventos() : ListaEnc<Evento*>(){}

	bool maior(Evento* dado1, Evento* dado2) const {
  		return dado1->getTempo() > dado2->getTempo();
	}

	ListaDeEventos* mergeSort() {
        if(this->getTamanho() < 2) {
            return this;
        }
        int meio = this->getTamanho() / 2;
        ListaDeEventos* esquerda = new ListaDeEventos();
        ListaDeEventos* direita = new ListaDeEventos();
        Elemento<Evento*>* anterior = this->getCabeca();

        for (int i = 0; i < meio -1 ; i++) {
            anterior = anterior->getProximo();
        }
        direita->setCabeca(anterior->getProximo());
        esquerda->setCabeca(this->getCabeca());
        anterior->setProximo(0);
        esquerda->setTamanho(meio);
        direita->setTamanho(this->getTamanho() - meio);
        esquerda = esquerda->mergeSort();
        direita = direita->mergeSort();

        return merge(direita, esquerda);
    }

    ListaDeEventos* merge(ListaDeEventos* dir, ListaDeEventos* esq) {
        ListaDeEventos* resultado = new ListaDeEventos();
       	while (dir->getTamanho() > 0 || esq->getTamanho() > 0) {
            if (dir->getTamanho() > 0 && esq->getTamanho() > 0) {
                if (esq->getCabeca()->getInfo()->getTempo() <= dir->getCabeca()->getInfo()->getTempo()){
                    resultado->adiciona(esq->retiraDoInicio());
                } else {
                    resultado->adiciona(dir->retiraDoInicio());
                }
            } else if (esq->getTamanho() > 0) {
                resultado->adiciona(esq->retiraDoInicio());
            } else if (dir->getTamanho() > 0) {
                resultado->adiciona(dir->retiraDoInicio());
            }
        }
        return resultado;
    }
};

#endif
