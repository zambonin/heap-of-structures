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
    *   de acordo com seu tempo corretamente. */
	bool maior(Evento* dado1, Evento* dado2) const;

};

bool ListaDeEventos::maior(Evento* dado1, Evento* dado2) const {
    return dado1->getTempo() > dado2->getTempo();
}

#endif


    // ListaDeEventos* mergeSort() {
 //        if(this->getTamanho() < 2) {
 //            return this;
 //        }
 //        int meio = this->getTamanho() / 2;
 //        ListaDeEventos* esquerda = new ListaDeEventos();
 //        ListaDeEventos* direita = new ListaDeEventos();
 //        Elemento<Evento*>* anterior = this->getCabeca();

 //        for (int i = 0; i < meio -1 ; i++) {
 //            anterior = anterior->getProximo();
 //        }
 //        direita->setCabeca(anterior->getProximo());
 //        esquerda->setCabeca(this->getCabeca());
 //        anterior->setProximo(0);
 //        esquerda->setTamanho(meio);
 //        direita->setTamanho(this->getTamanho() - meio);
 //        esquerda = esquerda->mergeSort();
 //        direita = direita->mergeSort();

 //        return merge(direita, esquerda);
 //    }

 //    ListaDeEventos* merge(ListaDeEventos* dir, ListaDeEventos* esq) {
 //        ListaDeEventos* resultado = new ListaDeEventos();
 //         while (dir->getTamanho() > 0 || esq->getTamanho() > 0) {
 //            if (dir->getTamanho() > 0 && esq->getTamanho() > 0) {
 //                if (esq->getCabeca()->getInfo()->getTempo() <= dir->getCabeca()->getInfo()->getTempo()){
 //                    resultado->adiciona(esq->retiraDoInicio());
 //                } else {
 //                    resultado->adiciona(dir->retiraDoInicio());
 //                }
 //            } else if (esq->getTamanho() > 0) {
 //                resultado->adiciona(esq->retiraDoInicio());
 //            } else if (dir->getTamanho() > 0) {
 //                resultado->adiciona(dir->retiraDoInicio());
 //            }
 //        }
 //        return resultado;
 //    }