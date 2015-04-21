#include <stdlib.h>

class Evento: private ListaEnc<T> {
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
		Elemento<Evento>* aux = head;
		int pos = 0;
		while (aux->getProximo() != NULL && maior(data->tempoDoDisparo, (aux->getInfo())->tempoDoDisparo) {
			aux = aux->getProximo();
			pos++;
		}
		if (maior(data->tempoDoDisparo, (aux->getInfo())->tempoDoDisparo))
			adiciona(data);
		adicionaNaPosicao(data, pos);
	}
	}

	
}
