#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <stdlib.h>
#include <time.h>

class Veiculo {
 private:
  int tamanho;
  int direcao; // em pista criar pista pointer (vetor de 10 espaços), pista pointer pergunta qual é a direcao e o pista pointer leva pro pointer que está contio no index[direcao]
 public:
  Veiculo() {
    // tamanho do veiculo mais 3 metros(2 à frente e 1 atrás)
    srand( (unsigned)time(NULL) );
    tamanho = (rand() % 5 + 2) + 3;
    direcao = rand() % 10;
  }
  ~Veiculo(){

  }
  int getTamanho() {
    return tamanho;
  }
  int getDirecao() {
    return direcao;
  }
};

#endif
