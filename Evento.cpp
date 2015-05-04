#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <stdlib.h>
#include "ListaEventos.cpp"
#include "Veiculo.cpp"
#include "Pista.cpp"
#include "Elemento.cpp"

class Evento {
 private:
	Veiculo *veiculo;
	int tipoDeEvento;
	int tempoDoDisparo;
	Pista *pista;
  ListaEventos<Evento*> *listaEvento;
 public:
	Evento(Veiculo *carro, int tipo, int tempo, Pista *estrada, ListaEventos<Evento*> *lista) {
		veiculo = carro;
		tipoDeEvento = tipo;
		tempoDoDisparo = tempo;
		pista = estrada;
    listaEvento = lista;
	}

	void executar() {
		switch(tipoDeEvento) {
			case 0:
				fecharSemaforo();
				break;
			case 1:
				abrirSemaforo();
				break;
			case 2:
				criarVeiculo();
				break;
			case 3:
				chegouSemaforo();
				break;
			default:
				destruirVeiculo();
		}
	}

  // pode ser um metodo só

	void abrirSemaforo() {
    pista->setSemaforo(true);
  }

	void fecharSemaforo() {
    pista->setSemaforo(false);
  }

  // pode ser um metodo só

  void criarVeiculo() {
		Veiculo *carro = new Veiculo();
		if (verificaTamanho(carro, pista)) { // Não estava recebendo os parametros
			pista->inclui(carro);
			pista->setTamanhoPista(pista->getTamanhoPista() - carro->getTamanho());
			Evento *chegouSemaforo = new Evento(carro, 3, pista->getTempo(), pista, listaEvento);
			listaEvento->adicionaEmOrdem(chegouSemaforo);  // Acho q 'Evento' terá q ser global no main
		}
	}

	void chegouSemaforo() {
    if (verificarSemaforo())
      trocaPista();
  } // chamar trocaPista se semáforo estiver aberto

	void trocaPista() {
      int direcaoVeiculo = veiculo->getDirecao();
      Pista* novaPista = pista->getNovaPista(direcaoVeiculo); // ou é ponteiro ??
    if(verificaTamanho(veiculo, novaPista)) {
      pista->somaContador();
      novaPista->inclui(veiculo);
      novaPista->setTamanhoPista(novaPista->getTamanhoPista() - veiculo->getTamanho());
      pista->retira();
      pista->setTamanhoPista(pista->getTamanhoPista() + veiculo->getTamanho());
    }
  }

	void destruirVeiculo() {
    pista->somaContador();
    pista->setTamanhoPista(pista->getTamanhoPista() + veiculo->getTamanho());
    delete veiculo;
  }

  void executarLista() {
		Elemento<Evento*> *executor;
    while (listaEvento->getHead() != NULL) {
      executor = listaEvento->getHead();
      (executor->getInfo())->executar();
      listaEvento->eliminaDoInicio();
    }

	}

/*	void adicionaEmOrdem(Evento& data) {
		if (listaEvento->ListaEnc<Evento*>::listaVazia())
			ListaEnc<Evento*>::adicionaNoInicio(&data);
		ListaEnc<Evento*>::Elemento<Evento*> *aux = ListaEnc<Evento*>::head;
		int pos = 0;
		while (ListaEnc<Evento*>::aux->getProximo() != NULL && maior(data->tempoDoDisparo, (ListaEnc<Evento*>::aux->getInfo())->tempoDoDisparo)) {
			ListaEnc<Evento*>::aux = ListaEnc<Evento*>::aux->getProximo();
			pos++;
		}
		if (ListaEnc<Evento*>::maior(data->tempoDoDisparo, (ListaEnc<Evento*>::aux->getInfo())->tempoDoDisparo))
			ListaEnc<Evento*>::adiciona(data);
		ListaEnc<Evento*>::adicionaNaPosicao(data, pos);
	}
*/

  bool verificaTamanho(Veiculo *carro, Pista *aPista) {
		if (carro->getTamanho() <= aPista->getTamanhoPista())
			return true;
		return false;
	}

  bool verificarSemaforo() {
    return pista->getSemaforo();
  }

  int getTempoDoDisparo() {
  	return tempoDoDisparo;
  }

};

#endif
