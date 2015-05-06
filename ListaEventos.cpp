#ifndef LISTAEVENTOS_HPP
#define LISTAEVENTOS_HPP

#include <cstdio>
#include <stdlib.h>
#include "ListaEnc.cpp"
#include "Elemento.cpp"

template<typename T>

class ListaEventos: private ListaEnc<T> {
 private:
 public:
	ListaEventos(): ListaEnc<T>::ListaEnc() {}

	void adicionaEmOrdem(T data) {
		if (ListaEnc<T>::listaVazia()) {
			//printf("Essa msg deve aparecer apenas uma vez data = %d!\n", data);
			ListaEnc<T>::adicionaNoInicio(data);
			return;		
		}
		Elemento<T> *aux = ListaEnc<T>::head;
		int pos = 0;
		//printf("Deve aparecer apenas 5 vezes! data = %d e o head = %d\n", data, aux->getInfo());
		//printf("data->getTempoDoDisparo() = %f, (aux->getInfo())->getTempoDoDisparo()) = %f\n", data->getTempoDoDisparo(), (aux->getInfo())->getTempoDoDisparo());
		while (aux->getProximo() != NULL && maior(data->getTempoDoDisparo(), (aux->getInfo())->getTempoDoDisparo())) {
			aux = aux->getProximo();
			pos++;
		}
		if (maior(data->getTempoDoDisparo(), (aux->getInfo())->getTempoDoDisparo())) {
			ListaEnc<T>::adiciona(data);
			return;
		}
		ListaEnc<T>::adicionaNaPosicao(data, pos);
	}

	bool maior(double dado1, double dado2) {
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
