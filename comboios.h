#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "cores.h"
#include <time.h>
/*-------------------*/
#define MAX 200
/*---------defines para linhas----------*/
#define dimEST 20
#define dimVIA 10
/*-------------------*/
#define coordX 0 //
#define coordY 1
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
	char lident[5];	/*ex: *LinhaAB->ident e LinhaAB->p->ident ??
    ID da linha + ID do ponto */
	char pident[5];
    int PosiNoGraf[2];//posição atual da carruagem\locomotiva
    int nservico;
}CARRUAGEM;

typedef struct comboio{
	CARRUAGEM cart;
	struct comboio *prox; // aponta para a prox carruagem
}COMBOIO;
/* ----------------------------------------------------------------------------------- */
void menu(char *opcao);
/*ADDS*/
COMBOIO* addComboio(COMBOIO* head,CARRUAGEM dados); // no fim da lista
FERROVIA* addLinha(FERROVIA* head,PONTOS dados);
void ligaLinhas(FERROVIA* Lista[], char lident_Sai[], char lident_Recebe[],char ID_Sai[],char ID_Entra[]);
/*INITS*/
COMBOIO* inicComboios(CARRUAGEM dados);
FERROVIA* inicLinha(char lident[], PONTOS dados);
/*MOSTRAS*/
void mostraComboio(COMBOIO* lista[]);
void mostraLinha(FERROVIA* lista[]);
/*LISTAS*/
int listaFerrovias(FERROVIA* lista[]);
int listaComboio(COMBOIO* lista[]);
/*DELETES*/
void eliminaComboio(COMBOIO* lista[]);
void eliminaLinha(FERROVIA* lista[]);
/*-------Funções de apoio\debug------*/
void verificaAcessos(FERROVIA* head[],char ident[]);
int convCor(char corestr[]);
FERROVIA* ProcuraID(FERROVIA* lista[],char lident[],char IDE_X[]);
char debug;//Isto tem de ser apagado antes de entregar.
void mostraCores(int cores[DIMCores][DIMrgb]);
void trocaCarris(FERROVIA* PercursoA);
int nPontos(FERROVIA* lista);
/*LER*/
int ler(char *argv[], COMBOIO *todos[], FERROVIA *todas[], int jancoord[]); // pus char aqui.
void passarEspacos(char **aux);
void lerJanela(char *aux,int jancoor[]);
COMBOIO* lerComboio(char *aux);
FERROVIA* lerLinha(char *aux, FERROVIA *head, char lident[]);
void lerLigar(char *aux, FERROVIA* todas[]);
/*CRIAR COMBOIO*/
void criarComboio(COMBOIO *todos[], FERROVIA *todas[]);
void mostraPontos(FERROVIA *todas[], char lident[]);

/*SDL*/
void abreJanela(int dimJanela[]);
/*-----*/
#endif
