//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária red-black.
/*! Classe que trata das operações relacionadas a árvores red-black. 
* \author Gustavo Zambonin, Lucas Ribeiro Neis
* \since 14/11/14
* \version 1.0
*/

#ifndef NORB_HPP_
#define NORB_HPP_
#include "NoBinario.hpp"

template<typename T>
class NoRB : NoBinario {
 private:
 	NoRB<T>(const T& dado): dado(new T(dado)), esquerda(0), direita(0), cor(false) {}

 public:
 	bool cor; //false para preto, true para rubro
};