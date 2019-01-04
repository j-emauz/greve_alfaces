int RegistoDeEventos(FERROVIA *todas, COMBOIOS *todos){
	SDL_Event event;
	int x, y;

	while (SDL_PollEvent(&event)){
		switch(event.type)
		{
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_q:
						return 0;
				}
			case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&x, &y);
				//funcao para procurar coordenadas, ver se nos pontos, ver se no comboio
				//if(x<coord+10,x>coord-10&&y<coord+10,y>coord-10);
	}
	//se calhar vai ser preciso usar case e switch
}