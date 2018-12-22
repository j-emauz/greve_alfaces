#include "comboios.h"
/*ISTO É UM FICHEIRO PARA TESTES, SUBSTITUI A MAIN*/
int main(int argc, char *argv[]){
	int cores[DIMCores][DIMrgb]={ {255,0,0,255},// vermelho
                                  {0,0,255,255},// azul
                                  {255,255,0,255},// AMARELO
                                  {0,255,255,255},//Cyan
                                  {153,0,153,255}, //Roxo
                                  {0,230,0,0}, // Verde
                                  {153,76,0,255}, //Castanho
                                  {0,0,0,255},//Preto
                                  {128,128,128,255},//Cinzento
                                  {255,255,255,255}//Branco
                                  };


    //mostracores(cores);

    COMBOIO *tchooBase =  init_Comboios();
    /* Recebendo os seguintes dados:*/
    CARRUAGEM carro1;
        carro1.cor=VERMELHO;
        carro1.DimBOLAS = 10;
        strcpy(carro1.ident,"PE");
        carro1.nCarruagens = 2;
        strcpy(carro1.PosInicial, "L1W1");
        carro1.PosiNoGraf[ox] = 100;
        carro1.PosiNoGraf[oy] = 120;
    CARRUAGEM carro2;
        carro2.cor=AZUL;
        carro2.DimBOLAS = 10;
        strcpy(carro2.ident,"PE");
        carro2.nCarruagens = 2;
        strcpy(carro2.PosInicial, "L1W1");
        carro2.PosiNoGraf[ox] = 120;
        carro2.PosiNoGraf[oy] = 120;


    /* Criamos um comboio */
    add_Comboio(tchooBase,carro1);
    add_Comboio(tchooBase,carro2);
    //add_Comboio(tchooBase,carro2);
    //add_Comboio(tchooBase,carro1);
    //mostraComboio(tchooBase);


    FERROVIA* linha1= init_Linha();
    /* Com os seguintes pontos...*/
    PONTOS start;
        strcpy(start.ident, "C0");
        start.coord[ox]=100;
        start.coord[oy]=100;
        start.cor=AZUL;
        strcpy(start.TipoDePonto, "EST");
        start.Dimensao=dimEST;
        start.nSaidas=0;
        start.nEntradas=0;
    PONTOS mid;
        strcpy(mid.ident, "C1");
        mid.coord[ox]=200;
        mid.coord[oy]=100;
        mid.cor=PRETO;
        strcpy(mid.TipoDePonto, "VIA");
        mid.Dimensao=dimVIA;
        mid.nSaidas=0;
        mid.nEntradas=0;
    PONTOS end;
        strcpy(end.ident, "C2");
        end.coord[ox]=300;
        end.coord[oy]=100;
        end.cor=VERMELHO;
        strcpy(end.TipoDePonto, "EST");
        end.Dimensao=dimEST;
        end.nSaidas=0;
        end.nEntradas=0;
    /* criamos uma linha */

    add_Linha(linha1,start);
    add_Linha(linha1,mid);
    add_Linha(linha1,end);

    mostraLinha(linha1);

    int dibuga;
    printf("insere um caracter");
    scanf("%c",&dibuga);
    /*agora quero Ligar um ponto de outra Linha no meio da linha*/

    PONTOS start2;
        strcpy(start2.ident, "A0");
        start2.coord[ox]=200;
        start2.coord[oy]=150;
        start2.cor=AMARELO;
        strcpy(start2.TipoDePonto, "EST");
        start2.Dimensao=dimEST;
        start2.nSaidas=0;
        start2.nEntradas=1;

    PONTOS end2;
        strcpy(end2.ident, "A1");
        end2.coord[ox]=100;
        end2.coord[oy]=150;
        end2.cor=AMARELO;
        strcpy(end2.TipoDePonto, "EST");
        end2.Dimensao=dimEST;
        end2.nSaidas=0;
        end2.nEntradas=0;

        FERROVIA* linha2= init_Linha();

        add_Linha(linha2,start2);
        add_Linha(linha2,end2);

        mostraLinha(linha2);


 return 0;
 }
