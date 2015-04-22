#include <stdlib.h>

class Evento: private ListaEnc<Evento> {
 private:
	Veiculo *veiculo;
	int tipoDeEvento;
	int tempoDoDisparo;
	Pista *aPista;
 public:
	Evento(Veiculo &carro, int tipo, int tempo, Pista &estrada) {
		veiculo = carro;
		tipoDeEvento = tipo;
		tempoDoDisparo = tempo;
		aPista = estrada;	
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

	criarVeiculo() {
		Veiculo *carro = new Veiculo();
		if (verificaTamanho()) {
			aPista->adiciona(carro);
			aPista->tamanhoPista = tamanhoPista - carro->tamanho;
			Evento *chegouSemaforo = new Evento(carro, 3, aPista->tempo, aPista);
			Main::eventos->adicionaEmOrdem(chegouSemaforo);  // Acho q 'eventos' terá q ser global no main
		}
	}

	chegouSemaforo() {
		
	}

	trocaPista() {}

	destruirVeiculo() {}

	adicionaEmOrdem(const Evento &data) {
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

	bool verificaTamanho(const Veiculo &carro, const Pista &estrada) {
		if (carro->tamanho <= aPista->tamanhoPista)
			return true;
		return false;	
	}

	
}
