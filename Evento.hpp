#include <stdlib.h>

class Evento: private ListaEnc<Evento> {
 private:
	Veiculo *veiculo;
	int tipoDeEvento;
	int tempoDoDisparo;
	Pista *pista;
	Evento *proximo;
 public:
	Evento(Veiculo &carro, int tipo, int tempo, Pista &estrada, Evento &proximo) {
		veiculo = carro;
		tipoDeEvento = tipo;
		tempoDoDisparo = tempo;
		pista = estrada;	
	}
	
	executar() {
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
			case 4:
				trocaPista();
				break;
			default:
				destruirVeiculo();
		}
	}
	
	abrirSemaforo() {}

	fecharSemaforo() {}

	criarVeiculo() {}

	chegouSemaforo() {}

	trocaPista() {}

	destruirVeiculo() {}

	adicionaEmOrdem(const Evento& data) {
		if (listaVazia())
			adicionaNoInicio(data);
		ListaEnc<Evento>::Elemento<Evento>* aux = ListaEnc<Evento>::head;
		int pos = 0;
		while (ListaEnc<Evento>::aux->getProximo() != NULL && maior(data->tempoDoDisparo, (ListaEnc<Evento>::aux->getInfo())->tempoDoDisparo) {
			ListaEnc<Evento>::aux = ListaEnc<Evento>::aux->getProximo();
			pos++;
		}
		if (maior(data->tempoDoDisparo, (ListaEnc<Evento>::aux->getInfo())->tempoDoDisparo))
			adiciona(data);
		adicionaNaPosicao(data, pos);
	}
	}

	
}
