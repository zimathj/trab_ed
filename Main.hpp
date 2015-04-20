#include <stdlib.h>

class Main {

  int main() {
    // Classe inicial do programa

    // 1° passo : criar as pistas

    // Pista(int tamPista, int vel, int tmpEntr, int var,
    //      bool pFonte, bool pSumidouro)

    Pista o1Oeste = new Pista(2000, 80, 0, 0, 0, 1);
    Pista o1Leste = new Pista(2000, 80, 10, 2, 1, 0);

    Pista n1Sul = new Pista(500, 60, 20, 5, 1, 0);
    Pista n1Norte = new Pista(500, 60, 0, 0, 0, 1);

    Pista n2Sul = new Pista(500, 40, 20, 5, 1, 0);
    Pista n2Norte = new Pista(500, 80, 0, 0, 0, 1);

    Pista s1Sul = new Pista(500, 60, 0, 0, 0, 1);
    Pista s1Norte = new Pista(500, 60, 30, 7, 1, 0);

    Pista s2Sul = new Pista(500, 40, 0, 0, 0, 1);
    Pista s2Norte = new Pista(500, 40, 60, 15, 1, 0);

    Pista c1Oeste = new Pista(300, 60, 0, 0, 0, 0);
    Pista c1Leste = new Pista(300, 60, 0, 0, 0, 0);

    Pista l1Oeste = new Pista(400, 30, 10, 2, 1, 0);
    Pista l1Leste = new Pista(400, 30, 0, 0, 0, 1);



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

    // 4° passo : processar

}

}
