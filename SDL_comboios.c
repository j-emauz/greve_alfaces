#include "comboios.h"

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

/*------------------------------- */
/* JANELA GRAFICA *//*
void desenhaComboios(COMBOIO* todos,FERROVIA* todas){
     int CX,CY,m,k,F;
     int X1,X2,Y1,Y2;
     COMBOIO* tempComb = NULL;
     FERROVIA* linha_actual = NULL;
     while(true){
        for(k=0;k<MAX;k++){
            X1=procuraID(todas,todos->cart.lident,todos->cart.pident)->pont.coord[coordX];
            Y1=procuraID(todas,todos->cart.lident,todos->cart.pident)->pont.coord[coordY];
            X2=procuraID(todas,todos->cart.lident,todos->cart.pident)->RA->pont.coord[coordX];
            Y2=procuraID(todas,todos->cart.lident,todos->cart.pident)->RA->pont.coord[coordY];
            m=(Y1-Y2)/(X2-X1);

            for(temp=todos[k];temp!=NULL;temp=temp->prox){


            }

        }


     }



}
*/
void abreJanela(int dimJanela[], COMBOIO *todos[], FERROVIA *todas[], int cores[][DIMrgb]){

    SDL_Init(SDL_INIT_EVERYTHING);



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

// eliminar        SDL_Error();

         /*Select the color for drawing. It is set to white here. */
        SDL_SetRenderDrawColor(g_pRenderer, cores[BRANCO][R], cores[BRANCO][G], cores[BRANCO][B], cores[BRANCO][ALPA] );


        /* Clear the entire screen to our selected color. */
        SDL_RenderClear(g_pRenderer);

        /* Up until now everything was drawn behind the scenes.
           This will show the new contents of the window. */
        printf("step \n");

        SDL_escrevePontos(todas,cores);
        SDL_unepontos(todas);
        //filledCircleRGBA(g_pRenderer,100,100,10,255,200,100,255);
        SDL_RenderPresent(g_pRenderer);




		SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

		//funcao ir buscar pontos as ferrovias para fazer draw line de cada linha e render dos pontos entre essas posicoes, isto deve estar dentro dum for

		//outra funcao para passar ponto inicial de comboio em coordenadas, se estiver no primeiro ponto da linha este deve somar a dim do comboio a posicao inicial


		//outra funcao para por os comboios a andar ate detetar

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
	FERROVIA *head3, *headtemp;
	char lident[MAX];

	for(i=0; todas[i]!=NULL && i<MAX; ++i){
        strcpy(lident, todas[i]->lident);
		for(head1=(todas[i]), head2=(todas[i]->RA); head1!=NULL && head2!=NULL && (strcmp(head1->lident, lident) == 0); head1 = head1->RA, head2 = head2->RA){
			SDL_SetRenderDrawColor( g_pRenderer, 0, 0, 0, 255 );
			SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head2->pont.coord[coordX], head2->pont.coord[coordY]);
			if(head1->RB!=NULL){
				head3 = head1->RB;
				SDL_SetRenderDrawColor( g_pRenderer, 255, 0, 0, 255 );
				SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head3->pont.coord[coordX], head3->pont.coord[coordY]);
                if(strcmp(head1->lident,head3->lident)==0){
                    headtemp = head1;
                    for(; head1!=NULL && head3!=NULL && (strcmp(head1->lident, lident) == 0); head1 = head1->RA, head3 = head3->RA){
                        SDL_SetRenderDrawColor( g_pRenderer, 0, 0, 0, 255 );
                        SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head3->pont.coord[coordX], head3->pont.coord[coordY]);
                    }//fazer isto numa funcao recursiva
                }
			}

			SDL_RenderPresent(g_pRenderer);

		}
		printf("%d \n",i);
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
