#include <stdlib.h>

#define Tempo = 3600;
#define Sem_L = 40;
#define Sem_N = 40;
#define Sem_O = 40;
#define Sem_S = 40;

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
    for (int i = 0; i < Tempo; i = i + (Sem_L+Sem_N+Sem_O+Sem_S)) {
	Evento a = new Evento(NULL, 1, i, o1Leste);
	eventos->adicionaEmOrdem(i);	
	Evento b = new Evento(NULL, 1, i, c1Leste);        
	eventos->adicionaEmOrdem(i);
    }

    // fecha os sinaleiros leste
    for (int i = Sem_L; i < Tempo; i = i + (Sem_N+Sem_O+Sem_S+Sem_L)) {
	Evento a = new Evento(NULL, 0, i, o1Leste);
	eventos->adicionaEmOrdem(i);
	Evento b = new Evento(NULL, 0, i, c1Leste);        
	eventos->adicionaEmOrdem(i);
    }

    // abre os sinaleiros norte
    for (int i = Sem_L; i < Tempo; i = i + (Sem_N+Sem_O+Sem_S+Sem_L)) {
	Evento a = new Evento(NULL, 0, i, o1Leste);
	eventos->adicionaEmOrdem(i);
	Evento b = new Evento(NULL, 0, i, c1Leste);        
	eventos->adicionaEmOrdem(i);
    }

    // fecha os sinaleiros norte

    // abre os sinaleiros oeste

    // fecha os sinaleiros oeste

    // abre os sinaleiros sul

    // fecha os sinaleiros sul 


    // 4° passo : processar

}

}
