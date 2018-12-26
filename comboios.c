#include "comboios.h"
SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

//funcao ler em ler.c

void menu(char *opcao){
	char linha[MAX];
	char teste;


	printf ("\nEscolha uma das opções \n"
				"0 - Terminar programa \n"
				"1 - Mostrar a informação de uma ferrovia \n"
				"2 - Permite eliminar uma ferrovia \n"
				"3 - Mostrar a informação de um comboio \n"
				"4 – Permite eliminar um comboio \n"
				"5 - Simulação \n"
				"Opção: ");
	fgets(linha, MAX, stdin);
	sscanf(linha, "%c%c", opcao, &teste);
	printf("\n");
	if(teste!='\n'){
		printf("Insira apenas 1 numero entre 0 e 5");
		menu(opcao);
	}
	if(*opcao>'5' || *opcao<'0'){
		printf("Insira apenas 1 numero entre 0 e 5");
		menu(opcao);
	}
}

/*-----------------COMBOIOS----------------------------*/

COMBOIO* inic_Comboios(){
    COMBOIO *head = (COMBOIO*)calloc(1,sizeof(COMBOIO));
    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função iniccomboio \n");
     exit(0);
    }
    head->prox=NULL;
    return head;
}

COMBOIO* addi_Comboio(COMBOIO* head,CARRUAGEM dados){
    COMBOIO* temp = head;

    COMBOIO* novo = (COMBOIO*) calloc(1,sizeof(COMBOIO) );
    if (novo == NULL){
        printf("Falha na aquisiçao de bloco de memória \n");
        return head;
    }
    novo->cart=dados;
    novo->prox=NULL;

    while (head->prox!=NULL ) //pretendemos inserir a carruagem sempre depois da anterior, ou seja, inserior sempre no fim da lista.
        head=head->prox;
    head->prox = novo;

    return temp;
}

COMBOIO* elimina_comboio(COMBOIO* head){
    COMBOIO* temp;
    head=head->prox;
    while(head!=NULL){
        temp = head;
        head=head->prox;
        free(temp);
    }
    return head;//n deve ser preciso returnar nada
}

void mostraComboio(COMBOIO* topo) {
    //WIP
    if (topo==NULL){
        printf("Comboio inexistente ! \n \n");
        return;
    }

    printf("\n Da locomotiva...\n\n");

    for(topo=topo->prox; topo!=NULL; topo=topo->prox)//aqui n e preciso inicializar topo... n deveria ser so for(;topo!=NULL;
    {
        printf("%s \n",topo->cart.ident);
        printf("%d %d \n",topo->cart.PosiNoGraf[0],topo->cart.PosiNoGraf[1]);
        //printf("%p \n",(void*)topo);

    }
    printf("\n \n à ultima carruagem \n");

}

/*------------------LINHAS-------------------*/

FERROVIA* inic_Linha(){
    FERROVIA*head = (FERROVIA*)calloc(1,sizeof(FERROVIA));
    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função inic_Linha \n");
     exit(0);
    }
    head->RA=NULL;
    head->RB=NULL;
    return head;
}

FERROVIA* addi_Linha(FERROVIA* head,PONTOS dados){
    FERROVIA* temp=head;
    FERROVIA* novo=(FERROVIA*)calloc(1,sizeof(FERROVIA));
    if (novo==NULL){
        printf("Falha na alocação de memória, addi_linha \n");
        return 0;
    }
    novo->pont=dados;
    if (head->RA != NULL) // significa que a linha já existe.
        novo->pont.nEntradas = 1;

    novo->RA=NULL;
    novo->RB=NULL;
    while(head->RA != NULL){
        head=head->RA;
    }
    head->RA=novo;
    head->pont.nSaidas = 1;
    return temp;
}

void KonnectLinhas(FERROVIA* linhaSai, FERROVIA* linhaRecebe,char ID_Sai[],char ID_Entra[]) {
    // W-MUITO-IP
    /*FAZER VERIFICAÇAO DE NUMERO DE SAIDAS E ENTRADAS*/
    printf("ID saida: %s , ID entrada:  %s \n", ID_Sai, ID_Entra);

    FERROVIA* ligaEntrada = linhaRecebe->RA;
    FERROVIA* ligaSaida = linhaSai->RA;

    //printf("ID saida: %p , ID entrada:  %p \n", (void*)ligaSaida, (void*)ligaEntrada);
    ligaEntrada = ProcuraID(ligaEntrada,ID_Entra);
    ligaSaida = ProcuraID(ligaSaida,ID_Sai);

    if ( ligaSaida->pont.nSaidas == 2){
        printf("ERRO, Capacidade de saídas do ponto %s excedido \n",ID_Sai);
        return;
    }else if(ligaEntrada->pont.nEntradas==2){
        printf("ERRO, Capacidade de entradas do ponto %s excedido \n",ID_Entra);
        return;
    }

    //printf("ID saida: %p , ID entrada:  %p \n", ligaSaida, ligaEntrada);

    if (ligaSaida -> RB==NULL) {
        printf("ligou por RB \n");
        ligaSaida -> RB = ligaEntrada;
        ligaSaida ->pont.nSaidas++;
        ligaEntrada ->pont.nEntradas++;

    }else {
        printf("ligou por RA \n");
        ligaSaida -> RA = ligaEntrada;
        ligaSaida ->pont.nSaidas++;
        ligaEntrada ->pont.nEntradas++;

    }
}

void mostraLinha(FERROVIA* topo) {
    //WIP
    if (topo==NULL){
        printf("Linha inexistente! \n\n");
        return;
    }
    topo=topo->RA;
    //printf("\n Da primeira estação.... \n\n");
    while(topo!=NULL)
    /* estou a usar uma espécie de "registo separado para a base",
    em que o primeiro bloco pode ser usado para colocar dados temporariamente e aponta para a "locomotiva"*/
    {

        if(topo->RA != NULL){
            printf("endereço :  %p \n",(void*)topo);
            printf("IDENTIFICADOR : %s \n",topo->pont.ident);
            printf("nEntradas %d  nSaidas %d \n", topo->pont.nEntradas,topo->pont.nSaidas);
            topo=topo->RA;
        }else{
            printf("endereço :  %p \n",(void*)topo);
            printf("IDENTIFICADOR  : %s \n",topo->pont.ident);
            printf("nEntradas %d  nSaidas %d \n", topo->pont.nEntradas,topo->pont.nSaidas);
            topo=topo->RB;
        }
    }
    //printf("\n ....à ultima estação \n\n");

}

FERROVIA* elimina_linha(FERROVIA* head){
    FERROVIA* temp;
    head=head->RA;
    while(head!=NULL){
        temp = head;
        head=head->RA;
        free(temp);
    }
    return head;
}
/* funções de apoio e debug*/

FERROVIA* ProcuraID(FERROVIA* ligaX,char IDE_X[]){
    FERROVIA* TempX = ligaX;
    while( strcmp( TempX->pont.ident,IDE_X ) != 0){

        if(TempX->RA != NULL){
            //printf("endereço :  %p \n",TempX);
            printf("IDENTIFICADOR : %s \n",TempX->pont.ident);
            TempX=TempX->RA;
        }else{
            //printf("endereço :  %p \n",TempX);
            printf("IDENTIFICADOR : %s \n",TempX->pont.ident);
            TempX=TempX->RB;
        }
        if(TempX==NULL){
            printf("ERRO, ID de ponto nao encontrado, verificar ficheiro de config!");
            exit(0);
        }
    }
    printf("MATCH : %s \n",TempX->pont.ident);
    printf(" AT Address : %p \n",(void*)TempX);
    return TempX;
 }

void trocaCarris(FERROVIA* PercursoA){
    /*WIP*/
    /*É importante correr esta função duas vezes, uma vez para o comboio passar e segunda depois do comboio passar,
    porque se alguém apagar uma linha enquanto os carris estão trocados, em vez de apagar essa linha vai apagar uma mistura de linhas.
    */
    FERROVIA *temp1=PercursoA->RA;
    PercursoA->RA = PercursoA->RB;
    PercursoA->RB = temp1->RA;

 }

void mostracores(int cores[DIMCores][DIMrgb]){
    int i,j;
    for(i=0;i<DIMCores;i++){
        for(j=0;j<DIMrgb;j++)
            printf("%d, ", cores[i][j]);

        printf("\n");
    };
}

int ConvCor(char corestr[]){
    if ( strcmp(corestr,"VERMELHO") == 0 ){
        return VERMELHO;

    }else if ( strcmp(corestr,"AMARELO")  == 0 ) {
        return AMARELO;

    }else if ( strcmp(corestr,"ROXO")  == 0 ) {
        return ROXO;

    }else if ( strcmp(corestr,"VERDE")  == 0 ) {
        return VERDE;

    }else if ( strcmp(corestr,"CASTANHO")  == 0 ) {
        return CASTANHO;

    }else if ( strcmp(corestr,"PRETO")  == 0 ) {
        return PRETO;

    }else if ( strcmp(corestr,"CINZENTO")  == 0 ) {
        return CINZENTO;

    }else if ( strcmp(corestr,"BRANCO")  == 0 ) {
        return BRANCO;

    }else {
        printf("Erro na conversão de cores, atenção utilizar só as cores especificadas:\n"
               "VERMELHO, AZUL, AMARELO, CYAN, ROXO, VERDE, CASTANHO, PRETO, CINZENTO, BRANCO \n\n");
        exit(0);
    }
}



/*------------------------------- */
/* JANELA GRAFICA */
void AbreJanela(int dimJanela[]){

    SDL_Init(SDL_INIT_EVERYTHING);
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

        //SDL_Error();

        /* Select the color for drawing. It is set to red here. */
        SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);

        /* Clear the entire screen to our selected color. */
        SDL_RenderClear(g_pRenderer);

        /* Up until now everything was drawn behind the scenes.
           This will show the new, red contents of the window. */
        SDL_RenderPresent(g_pRenderer);

        /* Give us time to see the window. */
        SDL_Delay(5000);

        /* Always be sure to clean up */
        SDL_DestroyRenderer(g_pRenderer);
        g_pRenderer=NULL;

        SDL_Quit();


        return;



	// "limpa" a função de texto
	//gfxPrimitivesSetFont(NULL, 0, 0);
}


