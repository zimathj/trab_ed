#ifndef PISTA_ENC
#define PISTA_ENC

#include <stdlib.h>
#include <time.h>
#include "Veiculo.cpp"
#include "FilaEnc.cpp"

// Nao declarar template aqui

class Pista: private FilaEnc<Veiculo*> {
 private:
   char *id;  // nome da pista
   int tamanhoPista;
   int velocidade;
   int tempoEntrada;
   int variancia;
   bool pistaFonte;
   bool pistaSumidouro;
   Pista *direcao[10];
   int tempo;
   //Pista **direcao = new Pista*[10];
   bool semaforo = false;
   int contador =  0;

 public:
   Pista(char *nome, int tamPista, int vel, int tmpEntr, int var,
         bool pFonte, bool pSumidouro): FilaEnc<Veiculo*>::FilaEnc() {
     id = nome;  //atribuicao do nome
     tamanhoPista = tamPista;
     velocidade = vel;
     variancia = var;
     tempoEntrada = tmpEntr;
     pistaFonte = pFonte;
     pistaSumidouro = pSumidouro;
	for(int i = 0; i < 10; i++)
		direcao[i] = NULL;
     //direcao = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
	//direcao = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	tempo = tamanhoPista/velocidade;  // Tempo q cada veículo vai levar para chegar ao final
   }
   ~Pista() {
	FilaEnc<Veiculo*>::limparFila();  // Usa o destrutor herdado
   }

   // Método para conectar pistas

   void conectarPistas(Pista* dir[]) {
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

   bool getSemaforo() {
     return semaforo;
   }

   Pista* getNovaPista(int indice) {  // Aqui dava erro, tem que ser "Pista*"
     if(indice > -1 && indice < 10)
      return direcao[indice];
   }

   int getContador() {
     return contador;
   }

   int getTempo() {
     return tempo;
   }

   char* getNome() {
     return id;
   }

   //

   void setTamanhoPista(int novoTamanho) {
     tamanhoPista = novoTamanho;
   }

   void setSemaforo(bool estado) {
     semaforo = estado;
   }

   void somaContador(){
     contador++;
   }

   int tempoParaEntrada() {
     srand( (unsigned)time(NULL) );  // Acho q tem q ter essa linha, se não rand() sorteia sempre os mesmos nºos
     return int((rand()/RAND_MAX)*(variancia*2+1) + (tempoEntrada-variancia));  // Seguindo as instrucoes do professor
										// retorna o tempo da criacao
   }

   // INCLUIR MÉTODOS DA FILA ENC

  void inclui(Veiculo*& dado) {
    FilaEnc<Veiculo*>::inclui(dado);
  }
  void retira() {
    FilaEnc<Veiculo*>::retira();
  }

};

#endif
