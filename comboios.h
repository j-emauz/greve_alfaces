#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "cores.h"
// defines para cores// sugiro passar isto para um ficheiro cores.h
/*
#define R  0
#define G  1
#define B  2
*/
#define ALFA  4//???
#define AMARELO 0
#define VERMELHO 1
#define AZUL 2
#define DIMCores 3 // para a matriz
#define DIMrgb 4 // para a matriz
//-------------------
#define MAX 100
/*--------------------------------------------------------------------------------*/
typedef struct pontos {
	int nOrdem;
	char ident[5];
	int coord[2];
	int cor; // cor=VERMELHO
	char tipo[4];//VIA, EST, ponto de via nao aparece ID no boneco
	int raio;
	int nEntradas;
	int nSaidas;
}PONTOS;

typedef struct linha {
	char ident[4];
	PONTOS p;
	struct linha *prox;
}LINHA;

typedef struct carr {
	int cor[9];//usar rand
	int raio;//em pixeis
	int posicao; // para verificar colisoes
}CARRUAGEM;

typedef struct comboio{
	CARRUAGEM c; //
	char ident[4];
	int nCarruagens[4];//numero de carruagens
	//int raio;// raio das bolas => CARRUAGEM.raio
	char PosInicial[6];// ID da linha + ID do ponto
	int cor;/* cor do comboio é cor da locomotiva, primeira CARRUAGEM*/
	struct comboio *prox;
}COMBOIO;

void MostraInfoFerrovia(LINHA* queLinha);

LINHA* EliminaFerrovia(LINHA* queLinha);

void MostraInfoComboio(COMBOIO* queComboio);

//COMBOIO* EliminaComboio(LINHA* queComboio;

void MudaCorVagao(COMBOIO** queComboio); // muda valor em campo CARRUAGEM do comboio
//void VerificaColisao(COMBOIO** queComboio, COMBOIO** queComboio2.....);

// talvez verificar colisao em pontos

/* ----------------------------------------------------------------------------------- */
void menu(char *opcao);
int ler(char *argv[]/*,    */); // pus char aqui.


#endif



