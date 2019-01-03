#include "comboios.h"

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

/*------------------------------- */
/* JANELA GRAFICA */
/*void SDL_inicComboios(COMBOIO *todos[], int cores[][DIMrgb], FERROVIA *todas[]){
    int i,j,l=1, z=0;
    float X1, X2, Y1, Y2, m;
    COMBOIO *temp, *bora;

    for(i=0; i<MAX && todos[i]!=NULL; ++i){
        for(temp=todos[i];temp!=NULL;temp=temp->prox){
            temp->cart.linha_actual = procuraID(todas,temp->cart.lident,temp->cart.pident);
            temp->cart.PosiNoGraf[coordX] = temp->cart.linha_actual->pont.coord[coordX];
            temp->cart.PosiNoGraf[coordY] = temp->cart.linha_actual->pont.coord[coordY];

            filledCircleRGBA(g_pRenderer,temp->cart.PosiNoGraf[coordX],temp->cart.PosiNoGraf[coordY],temp->cart.DimBOLAS,cores[temp->cart.cor][R],cores[temp->cart.cor][G],cores[temp->cart.cor][B],cores[temp->cart.cor][ALPA]);
            SDL_RenderPresent(g_pRenderer);
            SDL_Delay(100);
            SDL_SetRenderDrawColor(g_pRenderer,255,255,255,255);
            SDL_RenderClear(g_pRenderer);

            for(bora=todos[i]; bora!=NULL && z<l ; bora=bora->prox, z++){
            for(j=0;j<2*(bora->cart.DimBOLAS);j++){
                if(bora->cart.linha_actual->RA != NULL){
                X1=bora->cart.linha_actual->pont.coord[coordX];
                Y1=bora->cart.linha_actual->pont.coord[coordY];
                X2=bora->cart.linha_actual->RA->pont.coord[coordX];
                Y2=bora->cart.linha_actual->RA->pont.coord[coordY];

                if (X2-X1 != 0) {
                     m=(Y1-Y2)/(X2-X1);
                     (bora->cart.PosiNoGraf[coordX])++;
                     bora->cart.PosiNoGraf[coordY]=m+bora->cart.PosiNoGraf[coordY];
                }else{
                    (bora->cart.PosiNoGraf[coordY])++;
                }
                filledCircleRGBA(g_pRenderer,bora->cart.PosiNoGraf[coordX],bora->cart.PosiNoGraf[coordY],bora->cart.DimBOLAS,cores[bora->cart.cor][R],cores[bora->cart.cor][G],cores[bora->cart.cor][B],cores[bora->cart.cor][ALPA]);
                SDL_RenderPresent(g_pRenderer);
                SDL_Delay(100);
                SDL_SetRenderDrawColor(g_pRenderer,255,255,255,255);
            SDL_RenderClear(g_pRenderer);
            }
            }



        }
        l++;


    }


    }




}*/

/*void desenhaComboios(COMBOIO* todo, int cores[][DIMrgb]){
    int i,CX,CY;
    COMBOIO* temp=NULL;
    FERROVIA* tempovia = NULL;

        for (temp=todos[i];temp != NULL;){
            todos[i]->cart.linha_actual = procuraID(todas,todos[i]->cart.lident,todos[i]->cart.pident);
            todos[i]->cart.PosiNoGraf[coordX] = todos[i]->cart.linha_actual->pont.coord[coordX];
            todos[i]->cart.PosiNoGraf[coordY] = todos[i]->cart.linha_actual->pont.coord[coordY];

            CX=todos[i]->cart.PosiNoGraf[coordX];
            CY=todos[i]->cart.PosiNoGraf[coordY];

            filledCircleRGBA(g_pRenderer,CX,CY,todos[i]->cart.DimBOLAS,cores[todos[i])
        }

}*/


void trajectoriaComb(COMBOIO* todos[], int cores[][DIMrgb]) {
    int i;
    float m,Y1,Y2,X2,X1;
    COMBOIO* temp;

    for(i=0; i<MAX && todos[i]!=NULL; ++i){
        for(temp=todos[i]; temp!=NULL; temp=temp->prox){
            if(temp->cart.linha_actual->RA != NULL){
                X1=temp->cart.linha_actual->pont.coord[coordX];
                Y1=temp->cart.linha_actual->pont.coord[coordY];
                X2=temp->cart.linha_actual->RA->pont.coord[coordX];
                Y2=temp->cart.linha_actual->RA->pont.coord[coordY];

                if (X2-X1 != 0) {
                     m=(Y1-Y2)/(X2-X1);
                     (temp->cart.PosiNoGraf[coordX])++;
                     temp->cart.PosiNoGraf[coordY]=m+temp->cart.PosiNoGraf[coordY];
                }else{
                    (temp->cart.PosiNoGraf[coordY])++;
                }
                filledCircleRGBA(g_pRenderer,temp->cart.PosiNoGraf[coordX],temp->cart.PosiNoGraf[coordY],temp->cart.DimBOLAS,cores[temp->cart.cor][R],cores[temp->cart.cor][G],cores[temp->cart.cor][B],cores[temp->cart.cor][ALPA]);
            }else{
                //desenhaComboios(todos[i]);
            }
        }

    }

SDL_RenderPresent(g_pRenderer);
}

void desenhaComboios1(COMBOIO* todos[],FERROVIA* todas[], int cores[][DIMrgb]){
     int CX,CY,m,k,F,PosX;
     int X1,X2,Y1,Y2;
     COMBOIO* tempComb = NULL;
     FERROVIA* linha_actual = NULL;

     while(true){
        for(k=0;k<MAX;k++){
            //procura mini percurso.
            linha_actual = procuraID(todas,todos[k]->cart.lident,todos[k]->cart.pident);
            printf("Encontrou a linha \n");
            if (linha_actual !=NULL && linha_actual->RA!= NULL){
                X1=linha_actual->pont.coord[coordX];
                Y1=linha_actual->pont.coord[coordY];
                X2=linha_actual->RA->pont.coord[coordX];
                Y2=linha_actual->RA->pont.coord[coordY];

            }else {

            }

            PosX=X1;//define primeira pos
            m=(Y1-Y2)/(X2-X1);
            F=m*PosX+Y1;// obtem equação dos pontos.
            if (CY == Y2){


            }
            /*move ao longo da equação os pontos do comboio*/
            for(tempComb=todos[k];tempComb!=NULL;tempComb=tempComb->prox){
                filledCircleRGBA(g_pRenderer,PosX,F,4,cores[tempComb->cart.cor][R],cores[tempComb->cart.cor][G],cores[tempComb->cart.cor][B],cores[tempComb->cart.cor][ALPA]);
                SDL_RenderPresent(g_pRenderer);
            }
             if (F != Y2){
            linha_actual=linha_actual->RA;
            PosX++;

            }else if(linha_actual->RA != NULL){


            }else {


                printf("ERRRO KARALHO!\n");
                exit (0);
            }

        }
     }



}

void abreJanela(int dimJanela[], COMBOIO *todos[], FERROVIA *todas[], int cores[][DIMrgb]){

    SDL_Init(SDL_INIT_EVERYTHING);


    int end_game = 1;
	int coords[2];
	//SDL_Point CheckPontos[]

    if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {

		g_pWindow = SDL_CreateWindow("ComboioSim", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		dimJanela[coordX], dimJanela[coordY], SDL_WINDOW_SHOWN);
	//se inicializa com sucesso inicia o render
		if(g_pWindow != 0)
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);

	}else {
		exit(0);
	}

    do{

         /*Select the color for drawing. It is set to white here. */
        SDL_SetRenderDrawColor(g_pRenderer, cores[BRANCO][R], cores[BRANCO][G], cores[BRANCO][B], cores[BRANCO][ALPA] );


        /* Clear the entire screen to our selected color. */
        SDL_RenderClear(g_pRenderer);

        /* Up until now everything was drawn behind the scenes.
           This will show the new contents of the window. */


        SDL_escrevePontos(todas,cores);
        //trocaCarris(todas[1])
        SDL_unepontos(todas);
        //filledCircleRGBA(g_pRenderer,100,100,10,255,200,100,255);
        SDL_RenderPresent(g_pRenderer);
        SDL_inicComboios(todos, cores, todas);

		SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

		//funcao ir buscar pontos as ferrovias para fazer draw line de cada linha e render dos pontos entre essas posicoes, isto deve estar dentro dum for

		//outra funcao para passar ponto inicial de comboio em coordenadas, se estiver no primeiro ponto da linha este deve somar a dim do comboio a posicao inicial
        //desenhaComboios(todos,todas,cores);

		//outra funcao para por os comboios a andar ate detetar
     } while(end_game);
        /* Give us time to see the window. */
        SDL_Delay(6000);

        /* Always be sure to clean up */
        SDL_DestroyRenderer(g_pRenderer);
        g_pRenderer=NULL;

        SDL_Quit();


        return;



	// "limpa" a função de texto
	gfxPrimitivesSetFont(NULL, 0, 0);
}


void SDL_unepontos(FERROVIA *todas[]){
	int i;
	FERROVIA *head1,*head2;


	for(i=0; todas[i]!=NULL && i<MAX; ++i){

        head1=(todas[i]);
        head2=(todas[i]->RA);

		for_pontos(head1, head2);

		//printf("%d \n",i);
	}
}


void SDL_escrevePontos(FERROVIA *todas[],int cores[][DIMrgb]){
	int i;
	char lident[MAX];
	FERROVIA *head;


	for(i=0; i<MAX&&todas[i]!=NULL; ++i){
		strcpy(lident, todas[i]->lident);

		for(head = todas[i];head!=NULL && strcmp(lident, head->lident)==0; head=head->RA){


			/*SDL_RenderDrawPoint(g_pRenderer, head->pont.coord[coordX], head->pont.coord[coordY];*/
			filledCircleRGBA(g_pRenderer, head->pont.coord[coordX], head->pont.coord[coordY], head->pont.Dimensao, cores[head->pont.cor][R], cores[head->pont.cor][G], cores[head->pont.cor][B], cores[head->pont.cor][ALPA]);
            circleRGBA(g_pRenderer, head->pont.coord[coordX], head->pont.coord[coordY], head->pont.Dimensao,0,0,0,255);// contorno dos pontos, fica bonito.
            SDL_RenderPresent(g_pRenderer);


		}

	}

}
void for_pontos(FERROVIA *head1, FERROVIA* head2){
		FERROVIA *head3;
		char lident[MAX];

		strcpy(lident, head1->lident);

		for(; head1!=NULL && head2!=NULL && (strcmp(head1->lident, lident) == 0); head1 = head1->RA, head2 = head2->RA){
			SDL_SetRenderDrawColor( g_pRenderer, 0, 0, 0, 255 );
			SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head2->pont.coord[coordX], head2->pont.coord[coordY]);

			if(head1->RB!=NULL){
				head3 = head1->RB;
				SDL_SetRenderDrawColor( g_pRenderer, 255, 0, 0, 255 );
				SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head3->pont.coord[coordX], head3->pont.coord[coordY]);

				if(strcmp(head1->lident,head3->lident)==0){
                    for_pontos(head1, head3);
                    }
                }
			}

			SDL_RenderPresent(g_pRenderer);

}
