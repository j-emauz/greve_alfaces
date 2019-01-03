
void SDL_unepontos(FERROVIA *todas[]){
	int i;
	FERROVIA* head1,head2;
	FERROVIA *head3;
	char lident[MAX];
	
	for(i=0; todas[i]!=NULL && i<MAX; ++i){
		for(head1=(todas[i]), head2=(todas[i]->RA); head1!=NULL && head2!=NULL && (strcmp(head->lident, lident) == 0); head1 = head1->RA, head2 = head2->RA){
			SDL_SetRenderDrawColor( g_pRenderer, 0, 0, 0, 255 );
			SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head2->pont.coord[coordX], head2->pont.coord[coordY]);
			if(head1->RB!=NULL){
				head3 = head1->RB;
				SDL_SetRenderDrawColor( g_pRenderer, 255, 0, 0, 255 );
				SDL_RenderDrawLine(g_pRenderer, head1->pont.coord[coordX], head1->pont.coord[coordY], head3->pont.coord[coordX], head3->pont.coord[coordY]);
			}
			SDL_RenderPresent(g_pRenderer);
		}
	}
}