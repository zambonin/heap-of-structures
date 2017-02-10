//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve a árvore binária AVL.
/*! Classe que trata das operações relacionadas a árvores AVL.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 14/11/14
 * \version 1.0
 */

#ifndef NOAVL_HPP_
#define NOAVL_HPP_

template <typename T>
class NoAVL {
 private:
  T dado;
  NoAVL<T>* esquerda;
  NoAVL<T>* direita;
  int altura;

 public:
  explicit NoAVL(T data);
  int height(NoAVL<T>* nodo);
  int fator(NoAVL<T>* nodo);
  void arrumarAltura(NoAVL<T>* nodo);
  NoAVL<T>* rotacao_esquerda(NoAVL<T>* raiz);
  NoAVL<T>* rotacao_direita(NoAVL<T>* raiz);
  NoAVL<T>* rotacao_dupla_esquerda(NoAVL<T>* raiz);
  NoAVL<T>* rotacao_dupla_direita(NoAVL<T>* raiz);
  NoAVL<T>* balancear(NoAVL<T>* raiz);
  NoAVL<T>* minimo(NoAVL<T>* nodo);
  NoAVL<T>* removerMinimo(NoAVL<T>* nodo);
  NoAVL<T>* inserir(const T& dado, NoAVL<T>* nodo);
  NoAVL<T>* remover(const T& dado, NoAVL<T>* nodo);
};

template <typename T>
NoAVL<T>::NoAVL(T data) {
  dado = data;
  esquerda = direita = 0;
  altura = 1;
}

template <typename T>
int NoAVL<T>::height(NoAVL<T>* nodo) {
  return nodo ? nodo->altura : 0;
}

template <typename T>
int NoAVL<T>::fator(NoAVL<T>* nodo) {
  return (height(nodo->direita) - height(nodo->esquerda));
}

template <typename T>
void NoAVL<T>::arrumarAltura(NoAVL<T>* nodo) {
  int hL = height(nodo->esquerda);
  int hR = height(nodo->direita);
  nodo->altura = (hL > hR ? hL : hR) + 1;
}

template <typename T>
NoAVL<T>* NoAVL<T>::rotacao_direita(NoAVL<T>* raiz) {
  NoAVL<T>* auxiliar = raiz->esquerda;
  raiz->esquerda = 0;
  auxiliar->direita = raiz;
  raiz = auxiliar;
  arrumarAltura(raiz);
  arrumarAltura(auxiliar);
  return raiz;
}

template <typename T>
NoAVL<T>* NoAVL<T>::rotacao_esquerda(NoAVL<T>* raiz) {
  NoAVL<T>* auxiliar = raiz->direita;
  raiz->direita = 0;
  auxiliar->esquerda = raiz;
  raiz = auxiliar;
  arrumarAltura(raiz);
  arrumarAltura(auxiliar);
  return raiz;
}

template <typename T>
NoAVL<T>* NoAVL<T>::rotacao_dupla_esquerda(NoAVL<T>* raiz) {
  raiz->esquerda = rotacao_direita(raiz->esquerda);
  return rotacao_esquerda(raiz);
}

template <typename T>
NoAVL<T>* NoAVL<T>::rotacao_dupla_direita(NoAVL<T>* raiz) {
  raiz->direita = rotacao_esquerda(raiz->direita);
  return rotacao_direita(raiz);
}

template <typename T>
NoAVL<T>* NoAVL<T>::balancear(NoAVL<T>* raiz) {
  arrumarAltura(raiz);
  if (fator(raiz) == 2) {
    if (fator(raiz->direita) < 0) {
      // return rotacao_dupla_direita(raiz);
      raiz->direita = rotacao_direita(raiz->direita);
    }
    raiz = rotacao_esquerda(raiz);
    return raiz;
  }
  if (fator(raiz) == -2) {
    if (fator(raiz->esquerda) > 0) {
      // return rotacao_dupla_esquerda(raiz);
      raiz->esquerda = rotacao_esquerda(raiz->esquerda);
    }
    raiz = rotacao_direita(raiz);
    return raiz;
  }
  return raiz;
}

template <typename T>
NoAVL<T>* NoAVL<T>::minimo(NoAVL<T>* nodo) {
  return nodo->esquerda ? minimo(nodo->esquerda) : nodo;
}

template <typename T>
NoAVL<T>* NoAVL<T>::removerMinimo(NoAVL<T>* nodo) {
  if (nodo->esquerda == 0) {
    return nodo->direita;
  }
  nodo->esquerda = removerMinimo(nodo->esquerda);
  return balancear(nodo);
}

template <typename T>
NoAVL<T>* NoAVL<T>::inserir(const T& dado, NoAVL<T>* nodo) {
  if (nodo == 0) {
    return nodo = new NoAVL<T>(dado);
  }
  if (dado < nodo->dado) {
    nodo->esquerda = inserir(dado, nodo->esquerda);
  } else {
    nodo->direita = inserir(dado, nodo->direita);
  }
  nodo = balancear(nodo);
  return nodo;
}

template <typename T>
NoAVL<T>* NoAVL<T>::remover(const T& dado, NoAVL<T>* nodo) {
  if (!nodo) {
    throw 0;
  }
  if (dado < nodo->dado) {
    nodo->esquerda = remover(dado, nodo->esquerda);
  } else if (dado > nodo->dado) {
    nodo->direita = remover(dado, nodo->direita);
  } else {
    NoAVL<T>* esq = nodo->esquerda;
    NoAVL<T>* dir = nodo->direita;
    delete nodo;
    if (!dir) {
      return esq;
    }
    NoAVL<T>* min = minimo(dir);
    min->direita = removerMinimo(dir);
    min->esquerda = esq;
    return balancear(min);
  }
  return balancear(nodo);
}

#endif
