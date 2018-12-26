#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "cores.h"
//-------------------
#define MAX 100
#define MAXCOORD 2
/*---------defines para linhas----------*/
#define dimEST 20
#define dimVIA 10
/*-------------------*/
#define coordX 0 //
#define coordY 1
/*----------------------------------------LER--------------------------------------*/

int ler(char *argv[],COMBOIO* todos[],FERROVIA* todas[], int jancoord[]); // pus char aqui.
void passarespacos(char **aux);
void lerjanela(char *aux, int jancoord[]);
void lercomboio(char *aux);
void lerlinha(char *aux);
void lerligar(char *aux);

/*--------------------------------------------------------------------------------*/
typedef struct pontoslinha {
	//int nOrdem;
	char pident[5];
	int coord[2];// em pixeis
	int cor; // cor=VERMELHO
	char TipoDePonto[4];//VIA, EST, ponto de via nao aparece ID no boneco
	int Dimensao; //usar dimEST ou dimVIA
	int nEntradas;//max 2
	int nSaidas;//max 2

}PONTOS;

typedef struct ferrolinha {
	char lident[5];
	PONTOS pont;
	struct ferrolinha *RA;// abreviado de ROTA A
	struct ferrolinha *RB;
}FERROVIA;

typedef struct carr {
	//int raio;//em pixeis
	char cident[3];//BA
	int nCarruagens;//numero de carruagens( dimensao)
	int DimBOLAS; // raio em pixeis
	int cor; /* cor do comboio é cor da locomotiva, primeira CARRUAGEM*/
	char PosInicial[10];	/*ex: *LinhaAB->ident e LinhaAB->p->ident ??
    ID da linha + ID do ponto */
	//char pident[5];
    int PosiNoGraf[2];//posição atual da carruagem\locomotiva
}CARRUAGEM;

typedef struct comboio{
	CARRUAGEM cart;
	struct comboio *prox; // aponta para a prox carruagem
}COMBOIO;


// talvez verificar colisao em pontos

/* ----------------------------------------------------------------------------------- */
void menu(char *opcao);
/*ADDS*/
COMBOIO* addi_Comboio(COMBOIO* head,CARRUAGEM dados); // no fim da lista
FERROVIA* addi_Linha(FERROVIA* head,PONTOS dados);

void KonnectLinhas(FERROVIA* linhaSai, FERROVIA* linhaRecebe,char ID_Sai[],char ID_Entra[]);

/*INITS*/
COMBOIO* inic_Comboios();
FERROVIA* inic_Linha();

/*MOSTRAS*/
void mostraComboio(COMBOIO* topo);
void mostraLinha(FERROVIA* topo);
/*DELETES*/
COMBOIO* elimina_comboio(COMBOIO* head);
FERROVIA* elimina_linha(FERROVIA* head);
/*-------Funções de apoio\debug------*/

FERROVIA* ProcuraID(FERROVIA* ligaX,char IDE_X[]);

void mostracores(int cores[DIMCores][DIMrgb]);
void trocaCarris(FERROVIA* PercursoA);
/*------------SDL---------------------*/
void AbreJanela(int dimJanela[]);

/*-----------------------------------*/
#endif



