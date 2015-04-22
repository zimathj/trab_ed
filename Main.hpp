#include <stdlib.h>

#define TempoSimulacao = 3600;
#define Sem_L = 40;
#define Sem_S = 40;
#define Sem_O = 40;
#define Sem_N = 40;

class Main {

  int main() {
    // Classe inicial do programa

    // 1° passo : criar as pistas

    // Pista(int tamPista, int vel, int tmpEntr, int var,
    //      bool pFonte, bool pSumidouro)

    Lista[] pistas = new Lista<Pista>[14];

    Pista o1Oeste = new Pista(2000, 80, 0, 0, 0, 1);
    Pista o1Leste = new Pista(2000, 80, 10, 2, 1, 0);
    pistas[0] = o1Oeste;
    pistas[1] = o1Leste;

    Pista n1Sul = new Pista(500, 60, 20, 5, 1, 0);
    Pista n1Norte = new Pista(500, 60, 0, 0, 0, 1);
    pistas[2] = n1Sul;
    pistas[3] = n1Norte;

    Pista n2Sul = new Pista(500, 40, 20, 5, 1, 0);
    Pista n2Norte = new Pista(500, 80, 0, 0, 0, 1);
    pistas[4] = n2Sul;
    pistas[5] = n2Norte;

    Pista s1Sul = new Pista(500, 60, 0, 0, 0, 1);
    Pista s1Norte = new Pista(500, 60, 30, 7, 1, 0);
    pistas[6] = s1Sul;
    pistas[7] = s1Norte;

    Pista s2Sul = new Pista(500, 40, 0, 0, 0, 1);
    Pista s2Norte = new Pista(500, 40, 60, 15, 1, 0);
    pistas[8] = s2Sul;
    pistas[9] = s2Norte;

    Pista c1Oeste = new Pista(300, 60, 0, 0, 0, 0);
    Pista c1Leste = new Pista(300, 60, 0, 0, 0, 0);
    pistas[10] = c1Oeste;
    pistas[11] = c1Leste;

    Pista l1Oeste = new Pista(400, 30, 10, 2, 1, 0);
    Pista l1Leste = new Pista(400, 30, 0, 0, 0, 1);
    pistas[12] = l1Oeste;
    pistas[13] = l1Leste;

    // 2° passo : conectar as pistas

    //o1Oeste.conectarPistas();
    o1Leste.conectarPistas({c1Leste, c1Leste, c1Leste, c1Leste, c1Leste, c1Leste,
                            c1Leste, c1Leste, n1Norte, s1Sul});

    n1Sul.conectarPistas({c1Leste, c1Leste, c1Leste, c1Leste, c1Leste, c1Leste,
                          c1Leste, c1Leste, o1Oeste, s1Sul});
    //n1Norte.conectarPistas();

    n2Sul.conectarPistas({l1Leste, l1Leste, l1Leste, l1Leste, c1Oeste, c1Oeste,
                          c1Oeste, s2Sul, s2Sul, s2Sul});
    //n2Norte.conectarPistas();

    //s1Sul.conectarPistas();
    s1Norte.conectarPistas({c1Leste, c1Leste, c1Leste, c1Leste, c1Leste, c1Leste,
                            c1Leste, c1Leste, n1Norte, o1Oeste});

    //s2Sul.conectarPistas();
    s2Norte.conectarPistas({l1Leste, l1Leste, l1Leste, l1Leste, s2Sul, s2Sul, s2Sul,
                            c1Oeste, c1Oeste, c1Oeste});

    c1Oeste.conectarPistas({o1Oeste, o1Oeste, o1Oeste, o1Oeste, n1Norte, n1Norte,
                            n1Norte, s1Sul, s1Sul, s1Sul});
    c1Leste.conectarPistas({l1Leste, l1Leste, l1Leste, l1Leste, n2Norte, n2Norte,
                            n2Norte, s2Sul, s2Sul, s2Sul});

    l1Oeste.conectarPistas({n2Norte, n2Norte, n2Norte, n2Norte, c1Leste, c1Leste,
                            c1Leste, s2Sul, s2Sul, s2Sul, });
    //l1Leste.conectarPistas();



    // 3° passo : criar eventos


    ListaEnc eventos = new ListaEnc<Evento>();  // cria a lista de eventos

    // abre os sinaleiros leste
    for (int i = 0; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 1, i, o1Leste);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 1, i, c1Leste);
	eventos->adicionaEmOrdem(b);
    }

    // fecha os sinaleiros leste
    for (int i = Sem_L; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 0, i, o1Leste);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 0, i, c1Leste);
	eventos->adicionaEmOrdem(b);
    }

    // abre os sinaleiros sul
    for (int i = Sem_L; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 1, i, n1Sul);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 1, i, n2Sul);
	eventos->adicionaEmOrdem(b);
    }

    // fecha os sinaleiros sul
    for (int i = Sem_L+Sem_S; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 0, i, n1Sul);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 0, i, n2Sul);
	eventos->adicionaEmOrdem(b);
    }

    // abre os sinaleiros oeste
    for (int i = Sem_L+Sem_S; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 1, i, c1Oeste);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 1, i, l1Oeste);
	eventos->adicionaEmOrdem(b);
    }
    // fecha os sinaleiros oeste
    for (int i = Sem_L+Sem_S+Sem_O; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 0, i, c1Oeste);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 0, i, l1Oeste);
	eventos->adicionaEmOrdem(b);
    }

    // abre os sinaleiros norte
    for (int i = Sem_L+Sem_S+Sem_O; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 1, i, s1Norte);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 1, i, s2Norte);
	eventos->adicionaEmOrdem(b);
    }

    // fecha os sinaleiros norte
    for (int i = Sem_L+Sem_S+Sem_O+Sem_N; i < TempoSimulacao; i = i + (Sem_L+Sem_S+Sem_O+Sem_N)) {
	Evento *a = new Evento(NULL, 0, i, s1Norte);
	eventos->adicionaEmOrdem(a);
	Evento *b = new Evento(NULL, 0, i, s2Norte);
	eventos->adicionaEmOrdem(b);
    }



    // criaçao de carros nas pistas fonte



    for (int i = 0; i < TempoSimulacao; i = i + (int tmp = o1Leste->tempoParaEntrada())) {
      Evento *a = new Evento(NULL, 2, i + tmp, o1Leste);
     // if (a != NULL) {				// 'b' só vai ocorrer, se 'a' ocorrer, ou seja, somente em tempo de execução
     //   eventos->adicionaEmOrdem(a);
     //   Evento *b = new Evento(NULL, 3, i+o1Leste->tempo, o1Leste);
     //   eventos->adicionaEmOrdem(b);
      }
    }

    for (int i = 0; i < TempoSimulacao; i = i + (int tmp = n1Sul->tempoParaEntrada())) {
      Evento *a = new Evento(NULL, 2, i + tmp, n1Sul);
     // if (a != NULL) {
     //   eventos->adicionaEmOrdem(a);
     //   Evento *b = new Evento(NULL, 3, i+n1Sul->tempo, n1Sul);
     //   eventos->adicionaEmOrdem(b);
      }
    }

    for (int i = 0; i < TempoSimulacao; i = i + (int tmp = n2Sul->tempoParaEntrada())) {
      Evento *a = new Evento(NULL, 2, i + tmp, n2Sul);
     // if (a != NULL) {
     //   eventos->adicionaEmOrdem(a);
     //   Evento *b = new Evento(NULL, 3, i+n2Sul->tempo, n2Sul);
     //   eventos->adicionaEmOrdem(b);
      }
    }

    for (int i = 0; i < TempoSimulacao; i = i + (int tmp = l1Oeste->tempoParaEntrada())) {
      Evento *a = new Evento(NULL, 2, i + tmp, l1Oeste);
     // if (a != NULL) {
     //   eventos->adicionaEmOrdem(a);
     //   Evento *b = new Evento(NULL, 3, i+l1Oeste->tempo, l1Oeste);
     //   eventos->adicionaEmOrdem(b);
      }

    for (int i = 0; i < TempoSimulacao; i = i + (int tmp = s2Norte->tempoParaEntrada())) {
      Evento *a = new Evento(NULL, 2, i + tmp, s2Norte);
     // if (a != NULL) {
     //   eventos->adicionaEmOrdem(a);
     //   Evento *b = new Evento(NULL, 3, i+s2Norte->tempo, s2Norte);
     //   eventos->adicionaEmOrdem(b);
      }
    }

    for (int i = 0; i < TempoSimulacao; i = i + (int tmp = s1Norte->tempoParaEntrada())) {
      Evento *a = new Evento(NULL, 2, i + tmp, s1Norte);
     // if (a != NULL) {
     //   eventos->adicionaEmOrdem(a);
     //   Evento *b = new Evento(NULL, 3, i+s1Norte->tempo, s1Norte);
     //   eventos->adicionaEmOrdem(b);
      }
    }





    // 4° passo : processar




    Evento *executor;
    executor->executarLista(eventos);


}

}
