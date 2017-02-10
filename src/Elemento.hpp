//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve um elemento genérico.
/*! Classe que opera o elemento da lista encadeada simples.
 * \author Gustavo Zambonin, Lucas Ribeiro Neis
 * \since 14/09/14
 * \version 1.0
 */

#ifndef ELEMENTO_HPP
#define ELEMENTO_HPP

template <typename T>
class Elemento {
 private:
  //! Informação genérica do elemento.
  /*! Conteúdo do elemento que está presente na lista encadeada simples. */
  T* info;

  //! Próximo elemento.
  /*! Ponteiro que aponta pro próximo elemento da lista encadeada simples. */
  Elemento<T>* _next;

 public:
  //! Construtor.
  /*! Construtor que leva os dois parâmetros básicos de um elemento. */
  Elemento(const T& info, Elemento<T>* next)
    : info(new T(info)), _next(next) {}

  //! Destrutor.
  /*! Destrutor que deleta também a informação contida no elemento. */
  ~Elemento() {
    delete info;
  }

  //! Método para obter o próximo elemento na lista encadeada simples. */
  /*!
   * \return ponteiro do próximo elemento.
   * \sa getInfo(), setProximo()
   */
  Elemento<T>* getProximo() const {
    return _next;
  }

  //! Método para obter a informação do elemento.
  /*!
   * \return a informação genérica presente no elemento.
   * \sa getProximo(), setProximo()
   */
  T getInfo() const {
    return *info;
  }

  //! Método que modifica o ponteiro "próximo" do elemento.
  /*!
   * \param next o ponteiro a ser modificado.
   * \sa getProximo(), getInfo(), getAnterior(), setAnterior()
   */
  void setProximo(Elemento<T>* next) {
    _next = next;
  }
};

#endif
