#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "cores.h"
/*-------------------*/
#define MAX 2000
/*---------defines para dims----------*/
#define dimEST 5
#define dimVIA 3
#define dimLIDENT 5
#define dimPIDENT 5
#define dimCIDENT 3

/*-------------------*/
#define coordX 0 //
#define coordY 1
#define DISTSEG 40 // distancia de segurança entre comboios
/*--------------------------------------------------------------------------------*/
typedef struct pontoslinha {
	//int nOrdem;
	char pident[dimPIDENT];
	int coord[2];// em pixeis
	int cor; // cor=VERMELHO
	char TipoDePonto[4];//VIA, EST, ponto de via nao aparece ID no boneco
	int Dimensao; //usar dimEST ou dimVIA
	int nEntradas;//max 2
	int nSaidas;//max 2

}PONTOS;

typedef struct ferrolinha {
	char lident[dimLIDENT];
	PONTOS pont;
	struct ferrolinha *RA;// abreviado de ROTA A
	struct ferrolinha *RB;
}FERROVIA;

typedef struct carr {
	//int raio;//em pixeis
	char cident[dimCIDENT];//BA
	int nCarruagens;//numero de carruagens( dimensao)
	int DimBOLAS; // raio em pixeis
	int cor; /* cor do comboio é cor da locomotiva, primeira CARRUAGEM*/
	char lident[dimLIDENT];	/*ex: *LinhaAB->ident e LinhaAB->p->ident ??
    ID da linha + ID do ponto */
	char pident[dimPIDENT];
    int PosiNoGraf[2];//posição atual da carruagem\locomotiva
    int nservico;
    int locomotiva;
    FERROVIA* linha_actual;
}CARRUAGEM;

typedef struct comboio{
	CARRUAGEM cart;
	bool PARACOMBOIO;
	int nServicoInicial;//permite fazer reset do num de serviços dos comboios no SDL
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
int listaComboio(COMBOIO* lista[],int k);
/*DELETES*/
void eliminaComboio(COMBOIO* lista[]);
void libertaComboio(char cident[], COMBOIO* lista[]);
void eliminaLinha(FERROVIA* lista[],COMBOIO* todos[]);
/*-------Funções de apoio\debug------*/
void verifica_na_linhaComboios(COMBOIO* todos[], char lident[]);
int verificaColisoes(COMBOIO* lista[]);
void verificaAcessos(FERROVIA* head[],char ident[]);
int convCor(char corestr[]);
FERROVIA* procuraID(FERROVIA* lista[],char lident[],char IDE_X[]);
char debug;//Isto tem de ser apagado antes de entregar.
void mostraCores(int cores[DIMCores][DIMrgb]);
void trocaCarris(FERROVIA* PercursoA, COMBOIO* todos[]);
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
void abreJanela(int dimJanela[],COMBOIO* todos[], FERROVIA* todas[], int cores[][DIMrgb]);
void SDL_escrevePontos(FERROVIA *todas[],int cores[][DIMrgb]) ;
void SDL_unepontos(FERROVIA *todas[]);
void for_pontos(FERROVIA *head1, FERROVIA* head2);
void moveCarr(COMBOIO *temp, FERROVIA* todas[]);
void PosInicial(COMBOIO *temp, FERROVIA* todas[]);
int InicComboios(COMBOIO *todos[],int cores[][DIMrgb], FERROVIA* todas[]);
void trajectoriaComb(COMBOIO* todo, int cores[][DIMrgb], FERROVIA* todas[]);
void SDL_desenhaButoesHUD(int dimJanela[]);
int RegistoDeEventos(FERROVIA *todas[], COMBOIO *todos[], SDL_Event *event, int dimJanela[], int cores[][DIMrgb]);
void clicaParaAnda(FERROVIA *todas[], COMBOIO *todo, int cores[][DIMrgb]);
void clicaPonto(FERROVIA *toda, int x, int y,COMBOIO *todos[]);
void menuSDL(char *opcao, SDL_Event *event, int dimJanela[]);
int SDLsuspenso(COMBOIO *todos[], FERROVIA *todas[], int dimJanela[], int cores[][DIMrgb], SDL_Event *event);
int SDL_verificaContinua(int dimJanela[], SDL_Event *event);
/*-----*/
#endif
