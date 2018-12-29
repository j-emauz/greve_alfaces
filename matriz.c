#include "comboios.h"
/*ISTO É UM FICHEIRO PARA TESTES, SUBSTITUI A MAIN*/

int main(int argc, char *argv[]){
	srand(time(NULL));
	int cores[DIMCores][DIMrgb]={ {255,0,0,255},// vermelho
                                  {0,0,255,255},// azul
                                  {255,255,0,255},// AMARELO
                                  {0,255,255,255},//Cyan
                                  {153,0,153,255}, //Roxo
                                  {0,230,0,0}, // Verde
                                  {153,76,0,255}, //Castanho
                                  {0,0,0,255},//Preto
                                  {128,128,128,255},//Cinzento
                                  {255,255,255,255}/*Branco*/};
    CARRUAGEM carro1;
        carro1.cor=VERMELHO;
        carro1.DimBOLAS = 10;
        strcpy(carro1.cident,"PE");
        carro1.nCarruagens = 2;
        strcpy(carro1.pident, "L1W1");
        carro1.PosiNoGraf[coordX] = 100;
        carro1.PosiNoGraf[coordY] = 120;

    CARRUAGEM carro2;
        carro2.cor=AZUL;
        carro2.DimBOLAS = 10;
        strcpy(carro2.cident,"LE");
        carro2.nCarruagens = 2;
        strcpy(carro2.pident, "LD");
        carro2.PosiNoGraf[coordX] = 120;
        carro2.PosiNoGraf[coordY] = 120;

    PONTOS start;
        strcpy(start.pident, "A0");
        start.coord[coordX]=100;
        start.coord[coordY]=100;
        start.cor=AZUL;
        strcpy(start.TipoDePonto, "EST");
        start.Dimensao=dimEST;
        start.nSaidas=0;
        start.nEntradas=0;

    PONTOS mid;
        strcpy(mid.pident, "A1");
        mid.coord[coordX]=200;
        mid.coord[coordY]=100;
        mid.cor=PRETO;
        strcpy(mid.TipoDePonto, "VIA");
        mid.Dimensao=dimVIA;
        mid.nSaidas=0;
        mid.nEntradas=0;

    PONTOS end;
        strcpy(end.pident, "A2");
        end.coord[coordX]=300;
        end.coord[coordY]=100;
        end.cor=VERMELHO;
        strcpy(end.TipoDePonto, "EST");
        end.Dimensao=dimEST;
        end.nSaidas=0;
        end.nEntradas=0;

    PONTOS start2;
        strcpy(start2.pident, "B0");
        start2.coord[coordX]=200;
        start2.coord[coordY]=150;
        start2.cor=AMARELO;
        strcpy(start2.TipoDePonto, "EST");
        start2.Dimensao=dimEST;
        start2.nSaidas=0;
        start2.nEntradas=0;

    PONTOS end2;
        strcpy(end2.pident, "B1");
        end2.coord[coordX]=100;
        end2.coord[coordY]=150;
        end2.cor=AMARELO;
        strcpy(end2.TipoDePonto, "EST");
        end2.Dimensao=dimEST;
        end2.nSaidas=0;
        end2.nEntradas=0;

    PONTOS start3;
        strcpy(start3.pident, "C0");
        start3.coord[coordX]=200;
        start3.coord[coordY]=150;
        start3.cor=AMARELO;
        strcpy(start3.TipoDePonto, "EST");
        start3.Dimensao=dimEST;
        start3.nSaidas=0;
        start3.nEntradas=0;

    PONTOS end3;
        strcpy(end3.pident, "C1");
        end3.coord[coordX]=100;
        end3.coord[coordY]=150;
        end3.cor=AMARELO;
        strcpy(end3.TipoDePonto, "EST");
        end3.Dimensao=dimEST;
        end3.nSaidas=0;
        end3.nEntradas=0;
    int i=0;
    FERROVIA* linha[100];
    COMBOIO* tchooBase[100];
    for(i=0;i<MAX;i++){
        linha[i]= NULL;
        tchooBase[i]=NULL;
    }


    tchooBase[0] =  inic_Comboios(carro1);
    tchooBase[1] =  inic_Comboios(carro2);
    mostraComboio(tchooBase[0]);
    mostraComboio(tchooBase[1]);
    scanf("%c",&debug);

    linha[0]= inic_Linha("LOL");

    addi_Linha(linha[0],start);
    addi_Linha(linha[0],mid);
    addi_Linha(linha[0],end);


    mostraLinha(linha[0]);
    printf("-------------------\n\n");
    linha[1]= inic_Linha("LOLA");

    addi_Linha(linha[1],start2);
    addi_Linha(linha[1],end2);
    mostraLinha(linha[1]);
    printf("-------------------\n\n");

    KonnectLinhas(linha,"LOLA", "LOL", "B1", "A1");
    printf("-------------------\n\n");
    mostraLinha(linha[0]);
    printf("-------------------\n\n");
    mostraLinha(linha[1]);
    printf("-------------------\n\n");

    linha[2]= inic_Linha("PEPE");

    addi_Linha(linha[2],start3);
    addi_Linha(linha[2],end3);
    mostraLinha(linha[2]);

    KonnectLinhas(linha, "PEPE","LOL","C0","A1");

    mostraLinha(linha[0]);
    printf("-------------------\n\n");
    mostraLinha(linha[1]);
    printf("-------------------\n\n");
    mostraLinha(linha[2]);
    printf("-------------------\n\n");

    elimina_linha(linha,"PEPE");
    elimina_linha(linha,"LOL");

    elimina_linha(linha,"LOLA");

    tchooBase[0]=elimina_comboio(tchooBase[0]);

    mostraLinha(linha[0]);
    printf("-------------------\n\n");
    mostraLinha(linha[1]);
    printf("-------------------\n\n");
    mostraLinha(linha[2]);
    printf("-------------------\n\n");
    mostraComboio(tchooBase[0]);


    int dimJan[2]= {860,600};
   // AbreJanela(dimJan);


 return 0;
 }
