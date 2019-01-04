#include "comboios.h"

SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

/*------------------------------- */
/* JANELA GRAFICA */
void PosInicial(COMBOIO *temp, FERROVIA* todas[]){
	temp->cart.linha_actual = procuraID(todas,temp->cart.lident,temp->cart.pident);
    temp->cart.PosiNoGraf[coordX] = temp->cart.linha_actual->pont.coord[coordX];
    temp->cart.PosiNoGraf[coordY] = temp->cart.linha_actual->pont.coord[coordY];
}
void InicComboios(COMBOIO *todos[],int cores[][DIMrgb], FERROVIA* todas[]){
	int i, d, z;
	COMBOIO *temp;

	for(i=0;i<MAX&&todos[i]!=NULL;++i){
		d=4;
		for(temp=todos[i];temp!=NULL; temp=temp->prox, d--){
			PosInicial(temp, todas);
			for(z= d * 2 * (temp->cart.DimBOLAS); z>0; z--){
				moveCarr(temp, todas);
			}
			filledCircleRGBA(g_pRenderer,temp->cart.PosiNoGraf[coordX],temp->cart.PosiNoGraf[coordY],temp->cart.DimBOLAS,cores[temp->cart.cor][R],cores[temp->cart.cor][G],cores[temp->cart.cor][B],cores[temp->cart.cor][ALPA]);
		}
	}
}
void moveCarr(COMBOIO *temp, FERROVIA* todas[]){
	float X1, X2, Y1, Y2, m, b;

	 if(temp->cart.locomotiva == 0 && temp->cart.cor==temp->cart.linha_actual->pont.cor && strcmp(temp->cart.linha_actual->pont.TipoDePonto,"EST")==0) {

        temp->cart.cor=CINZENTO;
	 }

	if(temp->cart.linha_actual->RA != NULL){
		X1=temp->cart.linha_actual->pont.coord[coordX];
		Y1=temp->cart.linha_actual->pont.coord[coordY];
		X2=temp->cart.linha_actual->RA->pont.coord[coordX];
		Y2=temp->cart.linha_actual->RA->pont.coord[coordY];

		if (X2-X1 != 0) {
			m=(Y2-Y1)/(X2-X1);
			b=Y1-m*X1;

			if(X2>X1)
				(temp->cart.PosiNoGraf[coordX])++;
			else
				(temp->cart.PosiNoGraf[coordX])--;
			temp->cart.PosiNoGraf[coordY]=m*temp->cart.PosiNoGraf[coordX]+b;
			if(temp->cart.PosiNoGraf[coordX] == temp->cart.linha_actual->RA->pont.coord[coordX]){
				temp->cart.linha_actual = temp->cart.linha_actual->RA;
			}
		}else{

			if(Y2>Y1)
				(temp->cart.PosiNoGraf[coordY])++;
			else
				(temp->cart.PosiNoGraf[coordY])--;

			if(temp->cart.PosiNoGraf[coordY] == temp->cart.linha_actual->RA->pont.coord[coordY]){
				temp->cart.linha_actual = temp->cart.linha_actual->RA;
			}
        }

    }else{
        temp->cart.nservico--;
		PosInicial(temp, todas);
    }

}
void trajectoriaComb(COMBOIO* todo, int cores[][DIMrgb], FERROVIA* todas[]) { //mudei para ser so de um comboio
    //int i;
   // float m,Y1,Y2,X2,X1;
    COMBOIO* temp;

	for(temp=todo; temp!=NULL; temp=temp->prox){

		moveCarr(temp, todas);
		if(temp->cart.nservico>0){
				filledCircleRGBA(g_pRenderer,temp->cart.PosiNoGraf[coordX],temp->cart.PosiNoGraf[coordY],temp->cart.DimBOLAS,cores[temp->cart.cor][R],cores[temp->cart.cor][G],cores[temp->cart.cor][B],cores[temp->cart.cor][ALPA]);
		}
    }
}
void abreJanela(int dimJanela[], COMBOIO *todos[], FERROVIA *todas[], int cores[][DIMrgb]){

    SDL_Init(SDL_INIT_EVERYTHING);


    int end_game = 1;
	int i;
//int coords[2];
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
	SDL_SetRenderDrawColor(g_pRenderer, cores[BRANCO][R], cores[BRANCO][G], cores[BRANCO][B], cores[BRANCO][ALPA] );


        /* Clear the entire screen to our selected color. */
    SDL_RenderClear(g_pRenderer);

	SDL_unepontos(todas);
	SDL_escrevePontos(todas,cores);
	InicComboios(todos, cores, todas);
	SDL_RenderPresent(g_pRenderer);

	SDL_Delay(1000);


    do{
        SDL_SetRenderDrawColor(g_pRenderer, cores[BRANCO][R], cores[BRANCO][G], cores[BRANCO][B], cores[BRANCO][ALPA] );
        SDL_RenderClear(g_pRenderer);// pinta o ecra da cor acima
		SDL_unepontos(todas);
        SDL_escrevePontos(todas,cores);
        //filledCircleRGBA(g_pRenderer,100,100,10,255,200,100,255);

		for(i=0;i<MAX&&todos[i]!=NULL;i++){
			if(todos[i]->PARACOMBOIO==false){
				trajectoriaComb(todos[i], cores, todas);
			}
		}

		SDL_RenderPresent(g_pRenderer);

		SDL_Delay(15);

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
            //SDL_RenderPresent(g_pRenderer);


		}

	}

}
void for_pontos(FERROVIA *head1, FERROVIA* head2){
		FERROVIA *head3, *headtemp;
		char lident[MAX];

		strcpy(lident, head1->lident);

		for(; head1!=NULL && head2!=NULL && (strcmp(head1->lident, lident) == 0); head1 = head1->RA, head2 = head2->RA){
			SDL_SetRenderDrawColor( g_pRenderer, 0, 0, 0, 255 );
			SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head2->pont.coord[coordX], head2->pont.coord[coordY]);

			if(head1->RB!=NULL){
				head3 = head1->RB;
				SDL_SetRenderDrawColor( g_pRenderer, 255, 0, 0, 255 );
				SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head3->pont.coord[coordX], head3->pont.coord[coordY]);

				if((strcmp(head1->lident,head3->lident)==0) &&(head3->RA!=NULL)) {
                    headtemp= head3;
                    head3 = head3 ->RA;
                    for_pontos(headtemp, head3);
                    }
                }
			}

			//SDL_RenderPresent(g_pRenderer);

}
