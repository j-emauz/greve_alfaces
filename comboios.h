#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "cores.h"
/*-------------------*/
#define MAX 500
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
/*----------------------------*/
typedef struct pontoslinha{
	char pident[dimPIDENT];//ID do ponto
	int coord[2];// em pixeis
	int cor; // cor=VERMELHO
	char TipoDePonto[4];//VIA, EST, ponto de via nao aparece ID no boneco
	int Dimensao; //usar dimEST ou dimVIA
	int nEntradas;//max 2
	int nSaidas;//max 2

}PONTOS;

typedef struct ferrolinha {//lista de pontos
	char lident[dimLIDENT];//ID da linha
	PONTOS pont;//struct que contem os dados do Ponto
	struct ferrolinha *RA;// abreviado de ROTA A
	struct ferrolinha *RB;// abreviado de ROTA B
}FERROVIA;

typedef struct carr {
	char cident[dimCIDENT];//ID do comboio (sempre igual para cada carruagem
	int nCarruagens;//numero de carruagens( dimensao)
	int DimBOLAS; // raio em pixeis
	int cor; /* cor do comboio é cor da locomotiva, primeira CARRUAGEM*/
	char lident[dimLIDENT];//ID da linha inicial
	char pident[dimPIDENT];//ID do ponto inicial
    int PosiNoGraf[2];//posição atual da carruagem\locomotiva
    int nservico;// numero de viagens que o comboio faz
    int locomotiva;//se for locomotiva é 1 se nao for é 0
    FERROVIA* linha_actual;//linha atual do comboio, endereço.
}CARRUAGEM;

typedef struct comboio{//lista de 4 carruagens
	CARRUAGEM cart;
	bool PARACOMBOIO;// se true o comboio para e vice versa.
	int nServicoInicial;//permite fazer reset do num de serviços dos comboios no SDL
	struct comboio *prox; // aponta para a prox carruagem
}COMBOIO;
/* -----------------------------------*/
void menu(char *opcao);//menu
/*ADDS*/
COMBOIO* addComboio(COMBOIO* head,CARRUAGEM dados); //adiciona carruagens no fim da lista
FERROVIA* addLinha(FERROVIA* head,PONTOS dados);//adiciona linhas a lista existente
void ligaLinhas(FERROVIA* Lista[], char lident_Sai[], char lident_Recebe[],char ID_Sai[],char ID_Entra[]);
//faz as ligações especificadas pelo ficheiro de config
/*INITS*/
COMBOIO* inicComboios(CARRUAGEM dados);//inicializa um comboio com alocação de memória
FERROVIA* inicLinha(char lident[], PONTOS dados);//inicializa linhas com alocação de memória
/*MOSTRAS*/
void mostraComboio(COMBOIO* lista[]);//mostra info sobre comboio
void mostraLinha(FERROVIA* lista[]);//mostra info sobre linha
/*LISTAS*/
int listaFerrovias(FERROVIA* lista[]);//lista as ferrovias e retorna o numero de linhas existentes
int listaComboio(COMBOIO* lista[],int k);//lista os comboios e retorna o numero de comboios existentes
/*DELETES*/
void eliminaComboio(COMBOIO* lista[]);//função para pedir o comboio a eliminar, chama o liberta comboio
void libertaComboio(char cident[], COMBOIO* lista[]);//liberta o bloco de memoria do comboio eliminado
void eliminaLinha(FERROVIA* lista[],COMBOIO* todos[]);
/*-------Funções de apoio\debug------*/
void verifica_na_linhaComboios(COMBOIO* todos[], char lident[], FERROVIA* todas[]);
int verificaColisoes(COMBOIO* lista[]);//verifica se existem colisoes entre comboios
void verificaAcessos(FERROVIA* head[],char ident[]);//ao eliminar linha, corrige o num de entradas e saidas de cada ponto afectado
int convCor(char corestr[]);// converte o string das cores para inteiros pre definidos
FERROVIA* procuraID(FERROVIA* lista[],char lident[],char IDE_X[]);// procura por um ID de ponto especifico nas linhas existentes
//void mostraCores(int cores[DIMCores][DIMrgb]); // apoio e debug
void printCor(int corc);// obtem um inteiro faz print da cor (pre-definida) correspondente
void trocaCarris(FERROVIA* PercursoA, COMBOIO* todos[]);//faz uma troca de proximo endereço na lista de linhas
int nPontos(FERROVIA* lista);//retorna o numero de pontos numa linha
/*LER, funções para obter informação do ficheiro de config*/
int ler(char *argv[], COMBOIO *todos[], FERROVIA *todas[], int jancoord[]);//funcao geral para ler o ficheiro de configuracao
void passarEspacos(char **aux);
void lerJanela(char *aux,int jancoor[]);//le elementos de linha com dimensoes de janela grafica
COMBOIO* lerComboio(char *aux);//le dados de comboio e inicializa-o numa lista dinâmica
FERROVIA* lerLinha(char *aux, FERROVIA *head, char lident[]);//obtem e poe na lista dinamica o ponto correspondente
void lerLigar(char *aux, FERROVIA* todas[]);//obtem dados para ligar do ficheiro e liga linhas
/*CRIAR COMBOIO*/
void criarComboio(COMBOIO *todos[], FERROVIA *todas[]); //criação de comboio com escolha do ponto inicial do trajeto, feito no menu
void mostraPontos(FERROVIA *todas[], char lident[]);//lista os pontos de uma linha especifica
/*SDL*/
void abreJanela(int dimJanela[],COMBOIO* todos[], FERROVIA* todas[], int cores[][DIMrgb]);// abre janela do SDL
void SDL_escrevePontos(FERROVIA *todas[],int cores[][DIMrgb]); // desenha pontos na janela
void SDL_unepontos(FERROVIA *todas[]); // desenha a ligação dos pontos
void for_pontos(FERROVIA *head1, FERROVIA* head2);// apoio ao desenho da ligação de pontos
void moveCarr(COMBOIO *temp, FERROVIA* todas[]);//move cada carruagem e verifica se passa numa estação de cor igual
void PosInicial(COMBOIO *temp, FERROVIA* todas[]);//apoio ao inicComboios, dá as posições iniciais das carr
int SDL_inicComboios(COMBOIO *todos[],int cores[][DIMrgb], FERROVIA* todas[]);//inicia os comboios no ponto inicial, desenha os comboios
void trajectoriaComb(COMBOIO* todo, int cores[][DIMrgb], FERROVIA* todas[]);//trata do deslocamento dos comboios
void SDL_desenhaButoesHUD(int dimJanela[]);// desenha os butoes no SDL
int RegistoDeEventos(FERROVIA *todas[], COMBOIO *todos[], SDL_Event *event, int dimJanela[], int cores[][DIMrgb]);//permite detectar eventos na janela grafica, por ex carregar nos butoes
void clicaPonto(FERROVIA *toda, int x, int y,COMBOIO *todos[]);//detecta o click no ponto e altera a via se houver via alternativa, através do Troca carris
void menuSDL(char *opcao, SDL_Event *event, int dimJanela[]);//menu durante o "suspender"
int SDLsuspenso(COMBOIO *todos[], FERROVIA *todas[], int dimJanela[], int cores[][DIMrgb], SDL_Event *event);//chama o menuSDL, permite inicializar comboios criados
int SDL_verificaContinua(int dimJanela[], SDL_Event *event);//verificar o click no butao continua
void clicaParaAnda(FERROVIA *todas[], COMBOIO *todo, int cores[][DIMrgb]);// para e move os comboios ao clicar. faz os comboios darem um saltinho para o caso de estarem em colisao
#endif
