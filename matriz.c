#include "comboios.h"

int main(int argc, char *argv[]){
	/*int cores[DIMCores][DIMrgb]={ {255,0,0,255},// vermelho
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
                                  */
   /* int i,j;
    for(i=0;i<DIMCores;i++){
        for(j=0;j<DIMrgb;j++)
            printf("%d, ", cores[i][j]);
        printf("\n");
    };
*/


    COMBOIO *tchooBase =  init_Comboios();
    /* Recebendo os seguintes dados:*/
    CARRUAGEM carro1;
        carro1.cor=VERMELHO;
        carro1.DimBOLAS = 10;
        strcpy(carro1.ident,"PE");
        carro1.nCarruagens = 2;
        strcpy(carro1.PosInicial, "L1W1");
        carro1.PosiNoGraf[0] = 100;
        carro1.PosiNoGraf[1] = 120;
    CARRUAGEM carro2;
        carro2.cor=AZUL;
        carro2.DimBOLAS = 10;
        strcpy(carro2.ident,"PE");
        carro2.nCarruagens = 2;
        strcpy(carro2.PosInicial, "L1W1");
        carro2.PosiNoGraf[0] = 120;
        carro2.PosiNoGraf[1] = 120;


    /* Criamos um comboio */
    add_Comboio(tchooBase,carro1);
    add_Comboio(tchooBase,carro2);
    add_Comboio(tchooBase,carro2);
    add_Comboio(tchooBase,carro1);
    mostraComboio(tchooBase);
 return 0;
 }
