#include <stdlib.h>

class Evento : private Elemento<int> {
 private:
	Veiculo *veiculo;
	int tipoDeEvento;
	int tempoDoDisparo;

 public:
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

	
}
