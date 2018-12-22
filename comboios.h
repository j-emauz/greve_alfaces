#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
//-------------------
#define MAX 100
/*---------defines para linhas----------*/
#define dimEST 20
#define dimVIA 10
/*-------------------*/
#define ox 0 //
#define oy 1

/*--------------------------------------------------------------------------------*/
typedef struct pontoslinha {
	//int nOrdem;
	char ident[5];
	int coord[2];// em pixeis
	int cor; // cor=VERMELHO
	char TipoDePonto[4];//VIA, EST, ponto de via nao aparece ID no boneco
	int Dimensao; //usar dimEST ou dimVIA
	int nEntradas;//max 2
	int nSaidas;//max 2

}PONTOS;

typedef struct ferrolinha {
	PONTOS pont;
	struct ferrolinha *prox;
	//struct ferrolinha *prox2;

}FERROVIA;

typedef struct carr {
	int raio;//em pixeis
	char ident[3];//BA
	int nCarruagens;//numero de carruagens( dimensao)
	int DimBOLAS; // raio em pixeis
	int cor; /* cor do comboio é cor da locomotiva, primeira CARRUAGEM*/
	char PosInicial[6];	/*ex: *LinhaAB->ident e LinhaAB->p->ident ??
    ID da linha + ID do ponto */
    	int PosiNoGraf[2];//posição atual da carruagem\locomotiva
}CARRUAGEM;

typedef struct comboio{
	CARRUAGEM cart;
	struct comboio *prox; // aponta para a prox carruagem
}COMBOIO;


// talvez verificar colisao em pontos

/* ----------------------------------------------------------------------------------- */
void menu(char *opcao);
int ler(char *argv[]/*,    */); // pus char aqui.
/*ADDS*/
COMBOIO* add_Comboio(COMBOIO* head,CARRUAGEM dados); // no fim da lista
FERROVIA* add_Linha(FERROVIA* head,PONTOS dados);
//FERROVIA* add_LinhaN(FERROVIA* head, PONTOS dados,)

/*INITS*/
COMBOIO* init_Comboios();
FERROVIA* init_Linha();

/*MOSTRAS*/
void mostraComboio(COMBOIO* topo);
void mostraLinha(FERROVIA* topo);

/*-------Funções de apoio\debug------*/


void mostracores(int cores[DIMCores][DIMrgb]);



/*-----------------------------------*/
#endif



