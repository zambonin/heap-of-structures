//! Copyright year [2014] <Gustavo Zambonin & Lucas Ribeiro Neis>
//! Classe que descreve um elemento genérico.
/*! Classe que opera o elemento da lista encadeada dupla. 
*	\author Gustavo Zambonin, Lucas Ribeiro Neis
*	\since 27/09/14
*	\version 1.0
*/

#ifndef ELEMENTODUPLO_HPP_
#define ELEMENTODUPLO_HPP_

template<typename T>
class ElementoDuplo {
 private:
    //! Informação genérica do elemento.
    /*! Conteúdo do elemento que está presente na lista encadeada dupla. */
    T *info;

    //! Próximo elemento.
    /*! Ponteiro que aponta pro próximo elemento da lista encadeada dupla. */
    ElementoDuplo<T>* _next;

    //! Elemento anterior.
    /*! Ponteiro que aponta pro elemento anterior na lista encadeada dupla. */
    ElementoDuplo<T>* _previous;

 public:
    //! Construtor.
    /*! Construtor que leva os três parâmetros básicos de um elemento. */
	ElementoDuplo(const T& info, ElementoDuplo<T>* next,
		ElementoDuplo<T>* previous):info(new T(info)), _next(next),
        	_previous(previous) {}

	//! Destrutor.
	/*! Destrutor que deleta também a informação contida no elemento. */
	~ElementoDuplo() {
		delete info;
	}

	//! Método para obter o próximo elemento na lista encadeada dupla. */
	/*!
	* \return ponteiro do próximo elemento.
	* \sa getInfo(), setProximo(), getAnterior(), setAnterior()
	*/
	ElementoDuplo<T>* getProximo() const {
		return _next;
	}

	//! Método para obter a informação do elemento.
	/*!
	* \return a informação genérica presente no elemento.
	* \sa getProximo(), setProximo(), getAnterior(), setAnterior()
	*/
	T getInfo() const {
		return *info;
	}

	//! Método que modifica o ponteiro "próximo" do elemento.
	/*!
	* \sa getProximo(), getInfo(), getAnterior(), setAnterior()
	*/
	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}

	//! Método para obter o elemento anterior na lista encadeada dupla. */
	/*!
	* \return ponteiro do elemento anterior.
	* \sa getProximo(), getInfo(), setProximo(), setAnterior()
	*/
	ElementoDuplo<T>* getAnterior() const {
		return this->_previous;
	}

	//! Método que modifica o ponteiro "anterior" do elemento.
	/*!
	* \sa getProximo(), getInfo(), setProximo(), getAnterior()
	*/
    void setAnterior(ElementoDuplo<T>* novo) {
		_previous = novo;
	}
};

#endif
