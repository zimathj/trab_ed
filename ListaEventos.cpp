#ifndef LISTAEVENTOS_HPP
#define LISTAEVENTOS_HPP

#include <stdlib.h>
#include "ListaEnc.cpp"
#include "Elemento.cpp"

template<typename T>

class ListaEventos: private ListaEnc<T> {
 private:
 public:
	ListaEventos(): ListaEnc<T>::ListaEnc() {}

	void adicionaEmOrdem(T data) {
		if (ListaEnc<T>::listaVazia())
			ListaEnc<T>::adicionaNoInicio(data);
		Elemento<T> *aux = ListaEnc<T>::head;
		int pos = 0;
		while (aux->getProximo() != NULL && maior(data->getTempoDoDisparo(), (aux->getInfo())->getTempoDoDisparo())) {
			aux = aux->getProximo();
			pos++;
		}
		if (maior(data->getTempoDoDisparo(), (aux->getInfo())->getTempoDoDisparo()))
			ListaEnc<T>::adiciona(data);
		ListaEnc<T>::adicionaNaPosicao(data, pos);
	}

	bool maior(int dado1, int dado2) {
		if (dado1 > dado2)
			return true;
		return false;
	}

	Elemento<T>* getHead() {
		return ListaEnc<T>::head;
	}

	void eliminaDoInicio() {
		ListaEnc<T>::eliminaDoInicio();
	}

};

#endif
