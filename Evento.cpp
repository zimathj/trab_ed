#ifndef EVENTO_HPP
#define EVENTO_HPP

#include <stdlib.h>
#include <cstdio>
#include "ListaEventos.cpp"
#include "Veiculo.cpp"
#include "Pista.cpp"
#include "Elemento.cpp"

class Evento {
 private:
	Veiculo *veiculo;
	int tipoDeEvento;
	double tempoDoDisparo;
	Pista *pista;
  ListaEventos<Evento*> *listaEvento;
 public:
	Evento(Veiculo *carro, int tipo, double tempo, Pista *estrada, ListaEventos<Evento*> *lista) {
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
			//printf("Incluiu carro!\n");
			pista->setTamanhoPista(pista->getTamanhoPista() - carro->getTamanho());
			Evento *chegouSemaforo = new Evento(carro, 3, (tempoDoDisparo + pista->getTempo()), pista, listaEvento);
			//printf("Endereco do chegouSemaforo = %d\n", chegouSemaforo);
			//printf("Endereco da lista = %d\n", listaEvento);
			listaEvento->adicionaEmOrdem(chegouSemaforo);  // Acho q 'Evento' terá q ser global no main
			//printf("Adicionou o ChegouSemáforo = %d\n", chegouSemaforo);
		}
	}

	void chegouSemaforo() {
	//printf("verificou semaforo aberto\n");
    if (verificarSemaforo())
      trocaPista();
  } // chamar trocaPista se semáforo estiver aberto

	void trocaPista() {
      int direcaoVeiculo = veiculo->getDirecao();
      Pista* novaPista = pista->getNovaPista(direcaoVeiculo); // ou é ponteiro ??
    if(verificaTamanho(veiculo, novaPista)) {
      pista->somaContador();
	//printf("Pista tamanho = %d,  e head = %d\n", pista->getTamanhoPista(), pista->getInfor());
      novaPista->inclui(veiculo);
      novaPista->setTamanhoPista(novaPista->getTamanhoPista() - veiculo->getTamanho());
	//printf("NovaPista tamanho = %d,  e head = %d\n", novaPista->getTamanhoPista(), novaPista->getInfor());
      pista->retira();
      pista->setTamanhoPista(pista->getTamanhoPista() + veiculo->getTamanho());
	//printf("Pista tamanho = %d,  e head = %d\n", pista->getTamanhoPista(), pista->getInfor());
	//printf("Trocou carro de pista!\n");
	Evento *destruir = new Evento(veiculo, 4, (tempoDoDisparo + novaPista->getTempo()), novaPista, listaEvento);
	//printf("Destruir veiculo = %d\n", destruir);
	listaEvento->adicionaEmOrdem(destruir);
    }
  }

	void destruirVeiculo() {
    pista->somaContador();
    pista->setTamanhoPista(pista->getTamanhoPista() + veiculo->getTamanho());
    delete veiculo;
  }

  void executarLista(ListaEventos<Evento*> *lista, int tempo) {
		Elemento<Evento*> *executor;
	executor = lista->getHead();
	int numeroEvento = 1;
    while (executor != NULL && (executor->getInfo())->getTempoDoDisparo() < tempo) {
	//printf("Endereco do %d evento na lista = %d\n", numeroEvento, executor->getInfo());
      (executor->getInfo())->executar();
	executor = executor->getProximo();
      lista->eliminaDoInicio();
	numeroEvento++;
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

  double getTempoDoDisparo() {
  	return tempoDoDisparo;
  }

};

#endif
