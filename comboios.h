#ifndef COMBOIOS_H
#define COMBOIOS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cores.h"
//-------------------
#define MAX 100
/*--------------------------------------------------------------------------------*/
typedef struct linha {
	//int nOrdem;
	char ident[5];
	int coord[2];// em pixeis
	int cor; // cor=VERMELHO
	char TipoDePonto[4];//VIA, EST, ponto de via nao aparece ID no boneco
	int Dimensao; //dimensao do ponto em píxeis
	int nEntradas;//max 2
	int nSaidas;//max 2

}FERROVIA;

typedef struct linha {
	PONTOS p;
	struct linha *prox;
}LINHA;

/*typedef struct carr {
	int cor[9];//usar rand ?????
	int raio;//em pixeis
	int posicao[2]; // para verificar colisoes
}CARRUAGEM;
*/
typedef struct comboio{
	char ident[3];//BA
	int nCarruagens[4];//numero de carruagens( dimensao)
	int DimBOLAS; // raio em pixeis
	int cor; /* cor do comboio é cor da locomotiva, primeira CARRUAGEM*/
	char PosInicial[6];	/*ex: *LinhaAB->ident e LinhaAB->p->ident ??
    ID da linha + ID do ponto */
    int PosiNoGraf[2];//posição atual da carruagem\locomotiva

	struct comboio *prox; // aponta para a prox carruagem
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



