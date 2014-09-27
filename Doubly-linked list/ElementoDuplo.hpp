#ifndef ELEMENTODUPLO_HPP_
#define ELEMENTODUPLO_HPP_

template<typename T>
class ElementoDuplo {
 private:
    T *info;
    ElementoDuplo<T>* _next;
    ElementoDuplo<T>* _previous;

 public:
	ElementoDuplo(const T& info, ElementoDuplo<T>* next,
		ElementoDuplo<T>* previous):info(new T(info)), _next(next),
        	_previous(previous) {}

	~ElementoDuplo() {
		delete info;
	}

	ElementoDuplo<T>* getProximo() const {
		return _next;
	}

	T getInfo() const {
		return *info;
	}

	void setProximo(ElementoDuplo<T>* next) {
		_next = next;
	}

	ElementoDuplo<T>* getAnterior() const {
		return this->_previous;
	}

    void setAnterior(ElementoDuplo<T>* novo) {
		_previous = novo;
	}
};

#endif
