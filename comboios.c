#include "comboios.h"
SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

void menu(char *opcao){
	char linha[MAX];
	char teste;


	printf ("\nEscolha uma das opções \n"
				"0 - Terminar programa \n"
				"1 - Mostrar a informação de uma ferrovia \n"
				"2 - Eliminar uma ferrovia \n"
				"3 - Mostrar a informação de um comboio \n"
				"4 – Eliminar um comboio \n"
				"5 - Criar um comboio \n"
				"6 - Simulação dos comboios \n"
				"Opção: ");
	fgets(linha, MAX, stdin);
	sscanf(linha, "%c%c", opcao, &teste);
	printf("\n");
	if(teste!='\n'){
		printf("Insira apenas 1 numero entre 0 e 6");
		menu(opcao);
	}
	if(*opcao>'6' || *opcao<'0'){
		printf("Insira apenas 1 numero entre 0 e 6");
		menu(opcao);
	}
}

/*-----------------COMBOIOS----------------------------*/

COMBOIO* inic_Comboios(CARRUAGEM dados){
	int i=0;

	COMBOIO *head = (COMBOIO*)calloc(1,sizeof(COMBOIO));
    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função inic comboio \n");
     exit(0);
    }

	head->prox=NULL;
	head->cart=dados;
	printf("%d cor car \n",dados.cor);

	for(i=0; i<3; ++i){

		dados.cor = rand()%10;
		printf("%d cor car \n",dados.cor);
		head = addi_Comboio(head, dados);
	}
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

void elimina_comboio(COMBOIO* lista[],char cident[]){
    COMBOIO* temp;
    COMBOIO* head;

    int i,j;

    for( i=0 ; i<MAX ; i++){
        printf("i =%d \n",i);

        if (lista[i]!=NULL){
            printf("cident = %s \n",lista[i]->cart.cident);

            if(strcmp(cident,lista[i]->cart.cident)==0){
               head=lista[i];
               break;
           }
        }
     }
     if (head==NULL){
        // se nao existirem linhas, esta condição é sempre verificada.
       printf("ERRO, ID de linha nao encontrado, verificar ficheiro de config!");
       return;
    }
     for(j=0;j<MAX;j++){
        if(lista[j]==NULL)
            break;
    }
    if(j!=0){
         lista[i]=lista[j-1];
         lista[j-1]=NULL;
    }
    while(head!=NULL){
        temp = head;
        head=head->prox;
        free(temp);
    }
    printf("COMBOIO %s ELIMINADO EBIC STYLE B) \n", cident);
}
void ListaComboio(COMBOIO* lista[]){
    int i;
    printf("Lista de Comboios: ");

    for (i=0;i<MAX&&lista[i]!=NULL;i++){
        printf("%s ",lista[i]->cart.cident);
    }
    printf("\n");



}
void mostraComboio(COMBOIO* lista[], char cident[]) {
    //WIP
   int i;
   printf("cident : %s \n", cident);
   COMBOIO* topo = NULL;

   for (i=0; i<MAX&&lista[i]!=NULL ;i++){
        if ( strcmp (cident, lista[i]->cart.cident)==0 ){
            topo=lista[i];
            break;
        }
   }

    if (topo==NULL){
        printf("Comboio inexistente ! \n \n");
        return;
    }

   for(; topo!=NULL; topo=topo->prox)
    {
       printf("ID : %s nCOR: %d \n",topo->cart.cident, topo->cart.cor);
    }
}

/*------------------LINHAS-------------------*/

FERROVIA* inic_Linha(char lident[], PONTOS dados){
    FERROVIA*head = (FERROVIA*)calloc(1,sizeof(FERROVIA));
    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função inic_Linha \n");
     exit(0);
    }
    strcpy(head->lident, lident);
    head->RA=NULL;
    head->RB=NULL;


    head->pont = dados;

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
    // significa que a linha já existe.
    novo->pont.nEntradas = 1;

    novo->RA=NULL;
    novo->RB=NULL;
    strcpy(novo->lident, head->lident);

    while(head->RA != NULL){
        head=head->RA;
    }
    head->RA=novo;
    head->pont.nSaidas = 1;
    return temp;

}

void KonnectLinhas(FERROVIA* lista[], char lident_Sai[], char lident_Recebe[],char ID_Sai[],char ID_Entra[]) {
    // W-MUITO-IP
    /*FAZER VERIFICAÇAO DE NUMERO DE SAIDAS E ENTRADAS*/
    printf("(connect linhas)ID saida: %s , ID entrada:  %s \n", ID_Sai, ID_Entra);

    FERROVIA* ligaEntrada = NULL;
    FERROVIA* ligaSaida = NULL;
    //printf("ID saida: %p , ID entrada:  %p \n", (void*)ligaSaida, (void*)ligaEntrada);
    ligaEntrada = ProcuraID(lista,lident_Recebe,ID_Entra);
    ligaSaida = ProcuraID(lista,lident_Sai,ID_Sai);

    if ( ligaSaida->pont.nSaidas == 2){
        printf("ERRO, Capacidade de saídas do ponto %s excedido \n",ID_Sai);
        return;
    }else if(ligaEntrada->pont.nEntradas==2){
        printf("ERRO, Capacidade de entradas do ponto %s excedido \n",ID_Entra);
        return;
    }

    //printf("ID saida: %p , ID entrada:  %p \n", ligaSaida, ligaEntrada);

    if (ligaSaida -> RA==NULL) {
        printf("ligou por RA \n");
        ligaSaida -> RA = ligaEntrada;
        ligaSaida ->pont.nSaidas++;
        ligaEntrada ->pont.nEntradas++;

    }else {
        printf("ligou por RB \n");
        ligaSaida -> RB = ligaEntrada;
        ligaSaida ->pont.nSaidas++;
        ligaEntrada ->pont.nEntradas++;

    }
}

void ListaFerrovias(FERROVIA* lista[]){
    int i;
    printf("Lista de Ferrovias: ");


    for (i=0;i<MAX&&lista[i]!=NULL;i++){
        printf("%s ",lista[i]->lident);

    }
    printf("\n");

}




void mostraLinha(FERROVIA* lista[], char lident[]) {
    //WIP

    FERROVIA* head = NULL;
    int i;
    for( i=0 ; i<MAX ; i++){
        printf("i =%d \n",i);

        if (lista[i]!=NULL){
            printf("lident = %s \n",lista[i]->lident);

            if(strcmp(lident,lista[i]->lident)==0){
               head=lista[i];
               break;
           }
        }
     }
    if (head==NULL){
        // se nao existirem linhas, esta condição é sempre verificada.
       printf("ERRO, ID de linha nao encontrado, verificar ficheiro de config!");
       return;
    }
    //printf("\n Da primeira estação.... \n\n");
    while(head!=NULL && strcmp(lident,head->lident) == 0 )

    {
       printf("endereço :  %p \n",(void*)head);
       printf("IDENTIFICADOR : %s \n",head->pont.pident);
       printf("nEntradas %d  nSaidas %d \n", head->pont.nEntradas,head->pont.nSaidas);
       head=head->RA;

    }
    //printf("\n ....à ultima estação \n\n");

}

void elimina_linha(FERROVIA* lista[], char lident []){
    FERROVIA* temp = NULL;
    FERROVIA* head = NULL;
    int i,j;

    for( i=0 ; i<MAX ; i++){
        printf("i =%d \n",i);

        if (lista[i]!=NULL){
            printf("lident = %s \n",lista[i]->lident);

            if(strcmp(lident,lista[i]->lident)==0){
               head=lista[i];
               break;
           }
        }
     }
    if (head==NULL){
        // se nao existirem linhas, esta condição é sempre verificada.
       printf("ERRO, ID de linha nao encontrado, verificar ficheiro de config!");
       return;
    }

    for(j=0;j<MAX;j++){

        if(lista[j]==NULL)
            break;
    }

    if(j!=0){
         lista[i]=lista[j-1];
         lista[j-1]=NULL;
    }

    /*para que apenas a linha com identificador passado seja eliminada*/
    while((head!=NULL)&&(strcmp(head->lident,lident)==0)){
        temp = head;
        head=head->RA;
        free(temp);
        temp = NULL;
    }
    printf("FERROVIA %s ELIMINADA EBIC STYLE B) \n", lident);
}
/* funções de apoio e debug*/

FERROVIA* ProcuraID(FERROVIA* lista[],char lident[],char IDE_X[]){
    int i=0,k=0;

    FERROVIA* TempX=NULL;
   // printf("AT Procura ID, lident lista is %s <- \n", lista[i+1]->lident);//quickfix
    //printf("AT Procura ID, lident is %s \n", lident);


    for(i=0;i<MAX;i++){
        if (lista[i]!=NULL){

           // printf("AT Procura ID inside FOR, i = %d, lident lista is %s <- \n",i, lista[i]->lident);
            //printf("AT Procura ID inside FOR, lident is %s <-\n", lident);
         //   scanf("%c",&debug);
             k = strcmp(lident,lista[i]->lident);
             printf ("k = %d \n", k );


            if( k == 0 ) {
                //printf (" %d \n",strcmp(lident,lista[i]->lident)==0 );
                TempX=lista[i];
                printf("match em TempX = %p de lista[%d] \n",(void*)TempX,i);
    //            scanf("%c",&debug);
                break;
            }
        }
    }
    if (TempX==NULL){
       printf("ERRO, ID de linha nao encontrado, verificar ficheiro de config!");
       exit(0);
    }
    while( (strcmp(TempX->lident,lident)==0) && (strcmp( TempX->pont.pident,IDE_X ) != 0 ) ){

        if(TempX->RA != NULL){
            printf("IDENTIFICADOR : %s \n",TempX->pont.pident);
            TempX=TempX->RA;
        }else{
            printf("ERRO, ID de ponto nao encontrado, verificar ficheiro de config!");
            exit(0);
        }
    }
    printf("MATCH : %s \n",TempX->pont.pident);
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
    //printf("printei isto ::: === %s", corestr);

    if ( strcmp(corestr,"VERMELHO") == 0 ){
        return VERMELHO;

    }else if ( strcmp(corestr,"AMARELO")  == 0 ) {
        return AMARELO;

    }else if ( strcmp(corestr,"CYAN")  == 0 ) {
        return CYAN;

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

    }else if ( strcmp(corestr,"AZUL")  == 0 ) {
        return AZUL;

    } else {
        printf("Erro na conversão de cores, atenção utilizar só as cores especificadas:\n"
               "VERMELHO, AZUL, AMARELO, CYAN, ROXO, VERDE, CASTANHO, PRETO, CINZENTO, BRANCO \n\n");
        exit(0);
    }
}


/*------------------------------- */
/* JANELA GRAFICA */
/*void AbreJanela(int dimJanela[]){

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

         Select the color for drawing. It is set to red here. */
        //SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);

        /* Clear the entire screen to our selected color. */
        //SDL_RenderClear(g_pRenderer);

        /* Up until now everything was drawn behind the scenes.
           This will show the new, red contents of the window. */
        //SDL_RenderPresent(g_pRenderer);

        /* Give us time to see the window. */
        //SDL_Delay(5000);

        /* Always be sure to clean up */
        //SDL_DestroyRenderer(g_pRenderer);
        //g_pRenderer=NULL;

        //SDL_Quit();


    //    return;



	// "limpa" a função de texto
	//gfxPrimitivesSetFont(NULL, 0, 0);
//}


