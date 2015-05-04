// Copyright [2015] <Jonatan Zimath>
//! Classe de implementacao da fila encadeada.
/*!
*   Implementacao da fila encadeada usando templates.
*/

#ifndef FILAENC_HPP
#define FILAENC_HPP

#include "Elemento.cpp"
#include "ListaEnc.cpp"

template <typename T>
class FilaEnc: private ListaEnc<T>{
 public:
	FilaEnc<T>(): ListaEnc<T>::ListaEnc() {
	    last = NULL;
	}

	~FilaEnc() {
	    limparFila();
	}

	void inclui(const T& dado) {
	    Elemento<T> *novo = new Elemento<T>(dado, NULL);
	    if (novo == NULL)
	        throw(20);
	    if (filaVazia()) {
	        ListaEnc<T>::adiciona(dado);
	    } else {
	        last->setProximo(novo);
	    }
	    last = novo;
	    ListaEnc<T>::size;
	}

	T retira() {
	    if (filaVazia())
	        throw(20);
	    T dado = ListaEnc<T>::retiraDoInicio();
	    if (ListaEnc<T>::size == 0)
	        last = NULL;
	    return dado;
	}

	T ultimo() {
	    if (filaVazia())
            throw(20);
	    T dado;
	    dado = last->getInfo();
	    return dado;
	}

	T primeiro() {
	    if (filaVazia())
            throw(20);
	  T dado;
	  dado = ListaEnc<T>::head->getInfo();
	  return dado;
	}

	bool filaVazia() {
	    return ListaEnc<T>::listaVazia();
	}

	void limparFila() {
	    ListaEnc<T>::destroiLista();
	}

 private:
    Elemento<T> *last;
};

#endif
