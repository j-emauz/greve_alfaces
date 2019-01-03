void SDL_escreve_linhas(FERROVIA *todas[], cores[][DIMrgb]){
	int i;
	char lident[MAX];
	FERROVIA *head;
	
	
	for(i=0; i<MAX&&todas[i]!=NULL; ++i){
		strcpy(lident, todas[i]->lident);
		head = todas[i];
		for(;head!=NULL && strcmp(lident, head->lident); head=head->RA){
			
			/*SDL_SetRenderColor(g_pRenderer, cores[head->pont.cor][R], cores[head->pont.cor][G], cores[head->pont.cor][B], cores[head->pont.cor][ALPA]);
			SDL_RenderDrawPoint(g_pRenderer, head->pont.coord[coordX], head->pont.coord[coordY];*/
			filledCircleRGBA(g_pRenderer, head->pont.coord[coordX], head->pont.coord[coordY], ,head->pont.Dimensao, cores[head->pont.cor][R], cores[head->pont.cor][G], cores[head->pont.cor][B], cores[head->pont.cor][ALPA]);
		}
	}
	
}