#include <stdlib.h>
#include <time.h>

#include "FilaEnc.hpp"

class Pista: private FilaEnc<Veiculo> {
 private:
   int tamanhoPista;
   int velocidade;
   int tempoEntrada;
   int variancia;
   bool pistaFonte;
   bool pistaSumidouro;
   Pista *direcao[10];
   int tempo;
   //Pista **direcao = new Pista*[10];

 public:
   Pista(int tamPista, int vel, int tmpEntr, int var,
         bool pFonte, bool pSumidouro) {
     tamanhoPista = tamPista;
     velocidade = vel;
     srand( (unsigned)time(NULL) );  // Acho q tem q ter essa linha, se não rand() sorteia sempre os mesmos nºos
     variancia = rand() % var*2 + 1 + (-var);  // +/- rand() % var
     tempoEntrada = tmpEntr + var; // tempoEntrada + variancia
     pistaFonte = pFonte;
     pistaSumidouro = pSumidouro;
     direcao = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
     tempo = tamanhoPista/velocidade;  // Tempo q cada veículo vai levar para chegar ao final
   }
   ~Pista() {
	ListaEnc<Veiculo>::destroiLista();  // Usa o destrutor herdado
   }

   // Método para conectar pistas

   void conectarPistas(Pista *dir[10]) {
     int i;
     for (i = 0; i < 10; i++)
       direcao[i] = dir[i];
   }

   // Métodos GET :

   int getTamanhoPista() {
     return tamanhoPista;
   }

   int getVelocidade() {
     return velocidade;
   }

   int getTempoEntrada() {
     return tempoEntrada;
   }

   int getVariancia() {
     return variancia;
   }

   bool getPistaFonte() {
     return pistaFonte;
   }

   bool getPistaSumidouro() {
     return pistaSumidouro;
   }

   //


};
