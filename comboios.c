#include "comboios.h"
void menu(char *opcao){
	char linha[MAX];
	char teste;
	printf("Press enter");
	getchar();

	printf ("\nEscolha uma das opções \n"
				"0 - Terminar programa \n"
				"1 - Mostrar a informação de uma ferrovia \n"
				"2 - Eliminar uma ferrovia \n"
				"3 - Mostrar a informação de um comboio \n"
				"4 - Eliminar um comboio \n"
				"5 - Criar um comboio \n"
				"6 - Simulação dos comboios \n"
				"Opção: ");
	fgets(linha, MAX, stdin);
	sscanf(linha, "%c%c", opcao, &teste);
	printf("\n");

	if(teste!='\n' || *opcao>'6' || *opcao<'0' ){
		printf("Insira apenas 1 numero entre 0 e 6 \n");
		menu(opcao);
	}
}
/*-----------------COMBOIOS----------------------------*/
COMBOIO* inicComboios(CARRUAGEM dados){
	int i;
	COMBOIO *head = (COMBOIO*)calloc(1,sizeof(COMBOIO));

    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função inic comboio \n");
     exit(0);
    }
    head->PARACOMBOIO = false;
	head->prox=NULL;
	head->cart=dados;
    head->nServicoInicial=dados.nservico;
	dados.locomotiva = 0;

	for(i=1; i<dados.nCarruagens; ++i){
		dados.cor = rand()%10;
		head = addComboio(head, dados);
	}
    return head;
}

COMBOIO* addComboio(COMBOIO* head,CARRUAGEM dados){
    COMBOIO* temp = head;
    COMBOIO* novo = (COMBOIO*) calloc(1,sizeof(COMBOIO) );

    if (novo == NULL){
        printf("Falha na aquisiçao de bloco de memória \n");
        return head;
    }
    novo->PARACOMBOIO = false;
    novo->cart=dados;
    novo->prox=NULL;

    while (head->prox!=NULL) //pretendemos inserir a carruagem sempre depois da anterior, ou seja, inserir sempre no fim da lista.
        head=head->prox;
    head->prox = novo;

    return temp;
}
void eliminaComboio(COMBOIO* todos[]){

    char cident[MAX];
    if (listaComboio(todos,1)==0){
        return;
    }
    /*Procura de COMBOIO A ELIMINAR*/
    printf("Inserir ID do comboio a eliminar \n");
    scanf("%s", cident);
    libertaComboio(cident,todos);


}
int listaComboio(COMBOIO* lista[],int k){
    // se K < 0 nao faz print, serve para funçoes que utilizem o lista mas nao precisem de printar a lista.
    int i;
    if (lista[0]==NULL){
        if(k>0)
            printf("É dia de greve da CP sem serviços mínimos (TODOS os comboios suprimidos)! \n");
        return 0;
    }
    if (k>0)
        printf("Lista de Comboios: ");

    for (i=0;i<MAX&&lista[i]!=NULL;i++){
        if(k>0)
            printf("%s ",lista[i]->cart.cident);
    }

    if(k>0)
        printf("\nTotal Comboios %d\n",i);
    return i;
}
void mostraComboio(COMBOIO* lista[]) {
     if (listaComboio(lista,1)==0){
        return;
    }
    int i;
    char cident[MAX];
    COMBOIO* topo = NULL;

    printf("Inserir ID do Comboio a mostrar \n");
    scanf("%s",cident);
    //printf("cident: %s \n", cident); debug

    for (i=0; i<MAX&&lista[i]!=NULL ;i++){
         if ( strcmp (cident, lista[i]->cart.cident)==0 ){
             topo=lista[i];
             break;
         }
    }

    if (topo==NULL){
        printf("Comboio inexistente ! Verificar ID \n");
        return;
    }

    for(; topo!=NULL; topo=topo->prox){
	   if(topo->cart.locomotiva == 1){
		   printf("LOCOMOTIVA \nID: %s LINHA INICIAL: %s PONTO INICIAL: %s RAIO: %d ",topo->cart.cident, topo->cart.lident, topo->cart.pident, topo->cart.DimBOLAS);
		   printf("COR: ");
		   printCor(topo->cart.cor);
		   printf("CARRUAGENS: \n");
	   }else{
		   printf("RAIO: %d ", topo->cart.DimBOLAS);
		   printf("COR: ");
		   printCor(topo->cart.cor);
	   }
	}
}
void libertaComboio(char cident[], COMBOIO* lista[]){
    COMBOIO* temp;
    COMBOIO* head;
    int i,j;
    char elident[MAX];
    strcpy(elident,cident);//para depois printar bem no elimina linhas

    for(i=0 ; i<MAX; i++){
        if(lista[i]==NULL){
           // se nao existirem comboios, esta condição é sempre verificada.
           printf("ERRO, ID de comboio nao encontrado, verificar ficheiro de config!\n");
           return;
        }else if(strcmp(cident,lista[i]->cart.cident)==0){
           head=lista[i];
           break;
        }
    }
    /*REORDENAÇÃO*/
    for(j=0;j<MAX;j++){
        if(lista[j]==NULL)
            break;
    }
    if(j!=0){
         lista[i]=lista[j-1];
         lista[j-1]=NULL;
    }
    /*-----------------*/
    while(head!=NULL){
        temp = head;
        head=head->prox;
        free(temp);
    }
    printf("COMBOIO %s ELIMINADO EPIC STYLE B) \n", cident);
}
/*------------------LINHAS-------------------*/
FERROVIA* inicLinha(char lident[], PONTOS dados){
    FERROVIA*head = (FERROVIA*)calloc(1,sizeof(FERROVIA));
    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função inicLinha \n");
     exit(0);
    }
    strcpy(head->lident, lident);
    head->RA=NULL;
    head->RB=NULL;
    head->pont = dados;
    return head;
}

FERROVIA* addLinha(FERROVIA* head,PONTOS dados){
    FERROVIA* temp=head;
    FERROVIA* novo=(FERROVIA*)calloc(1,sizeof(FERROVIA));

    if (novo==NULL){
        printf("Falha na alocação de memória, addi_linha \n");
        return 0;
    }
    novo->pont=dados;
    novo->pont.nEntradas = 1;//A linha já existe.
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

void ligaLinhas(FERROVIA* lista[], char lident_Sai[], char lident_Recebe[],char ID_Sai[],char ID_Entra[]) {
    /*FAZER VERIFICAÇAO DE NUMERO DE SAIDAS E ENTRADAS*/
    FERROVIA* ligaEntrada = NULL;
    FERROVIA* ligaSaida = NULL;

    ligaEntrada = procuraID(lista,lident_Recebe,ID_Entra);
    ligaSaida = procuraID(lista,lident_Sai,ID_Sai);

    if ( ligaSaida->pont.nSaidas == 2){
        printf("ERRO, Capacidade de saídas do ponto %s excedido \n",ID_Sai);
        return;
    }else if(ligaEntrada->pont.nEntradas==2){
        printf("ERRO, Capacidade de entradas do ponto %s excedido \n",ID_Entra);
        return;
    }

    if (ligaSaida -> RA==NULL) {
        ligaSaida -> RA = ligaEntrada;
        ligaSaida ->pont.nSaidas++;
        ligaEntrada ->pont.nEntradas++;

    }else{
        ligaSaida -> RB = ligaEntrada;
        ligaSaida ->pont.nSaidas++;
        ligaEntrada ->pont.nEntradas++;
    }
}

int listaFerrovias(FERROVIA* lista[]){
    int i;
    printf("Lista de Ferrovias: ");

    if (lista[0]==NULL){
        printf("Não existem linhas! \n");
        return 0;
    }

    for (i=0;i<MAX&&lista[i]!=NULL;i++){
        printf("%s ",lista[i]->lident);
    }
    printf("\nTotal de ferrovias: %d\n",i);
    return i;
}

void mostraLinha(FERROVIA* lista[]) {
    if(listaFerrovias(lista)==0){
        return;
    }
    char lident[MAX];
    printf("Escreva o ID da Ferrovia a apresentar sem espaços! \n");
    scanf("%100s",lident);
    FERROVIA* head = NULL;
    int i;
    for( i=0 ; i<MAX ; i++){
       if (lista[i]!=NULL){
            if(strcmp(lident,lista[i]->lident)==0){
               head=lista[i];
               break;
           }
        }
    }
    if (head==NULL){
        // se nao existirem linhas, esta condição é sempre verificada.
        printf("ERRO, ID de linha nao encontrado! Verificar se o ID foi introduzido correctamente\n");
        return;
    }

    while(head!=NULL && strcmp(lident,head->lident) == 0) {
       //printf("endereço :  %p \n",(void*)head);
       printf("PONTO: %s ",head->pont.pident);
       printf("Nº Entradas: %d  Nº Saidas: %d Tipo de Ponto: %s Cor: ", head->pont.nEntradas,head->pont.nSaidas, head->pont.TipoDePonto);
	   printCor(head->pont.cor);
       head=head->RA;
    }
}

void eliminaLinha(FERROVIA* lista[], COMBOIO* todos[]){
    FERROVIA* temp = NULL;
    FERROVIA* head = NULL;
    char lident[MAX];
    int i,j;

    if (listaFerrovias(lista)==0){
        return;
    }// Lista as ferrovias por ID
    printf("Escreva o ID da Ferrovia a eliminar sem espaços! \n");
    scanf("%s",lident);

    for( i=0 ; i<MAX ; i++){ //Procura da linha com ID = lident
        if (lista[i]!=NULL && strcmp(lident,lista[i]->lident)==0 ){
               head=lista[i];
               break;
        }
	}
    if (head==NULL){// se nao existirem linhas, esta condição é sempre verificada.
       printf("ERRO, ID de linha nao encontrado");
       return;
    }
    verificaAcessos(lista,lident);//ajusta o nEntradas e nSaidas
    verifica_na_linhaComboios(todos,lident,lista);
    for(j=0;j<MAX;j++){

        if(lista[j]==NULL)
            break;
    }
    if(j!=0){
         lista[i]=lista[j-1]; // colocamos o ultimo elemento da lista no lugar do elemento a ser eliminado.
         lista[j-1]=NULL; // limpamos a anterior última célula com dados úteis.
    }
    //free no bloco de memória
    while((head!=NULL)&&(strcmp(head->lident,lident)==0)){/*para que apenas a linha com o ID passado seja eliminada*/
        temp = head;
		if(head->RB!=NULL && strcmp(head->lident, head->RB->lident)==0)
			head = head->RB;
		else
			head=head->RA;

        free(temp);
        temp = NULL;
    }
    printf("FERROVIA %s ELIMINADA EPIC STYLE B) \n", lident);
}
/* funções de apoio e debug*/
void verificaAcessos(FERROVIA* lista[],char ident[]){
    //queremos que a todas as linhas com saída para a linha com ID "ident" seja reduzida 1 saída.
    //queremos que a todas as linhas com entradas provenientes da linha com ID "ident" seja reduzida 1 entrada.
    int k,p,l;
    FERROVIA* temp;
    //É preciso só verificar um numero p de pontos que será o numero total de pontos da linha K.
    for(k=0, temp=lista[k]; lista[k] != NULL && k<MAX ; k++,temp=lista[k]) { // percorremos todas as linhas existentes.

        l=nPontos(lista[k]);// aqui para só correr uma vez e não p vezes no while
        for(p=0; p < l;p++) {
            if(temp->RA !=NULL){//
                if ( strcmp(temp->RA->lident,ident) == 0 && strcmp(temp->lident,ident)!=0 ){//se a proximo ponto(RA) pertencer à estação a eliminar e não estivermos sobre ela

                    temp->pont.nSaidas--;
                    temp->RA= NULL;
                    if (temp->RB !=NULL){
                        temp->RA = temp->RB;
                        temp->RB = NULL; // é suposto perder informação de uma das saídas
                    }

                }else if(strcmp(temp->lident,ident)==0 && strcmp(temp->RA->lident,ident) != 0) {//estamos sobre a estaçao a eliminar mas o prox ponto nao pertence a ela
                    temp->RA->pont.nEntradas--;
                }
            }
            if (temp->RB != NULL){//nem sempre existe
                if ( strcmp(temp->RB->lident,ident) == 0 && strcmp(temp->lident,ident) != 0){//se a proximo ponto(RB) pertencer à estação a eliminar e não estivermos sobre ela
                    temp ->pont.nSaidas --;
                    temp ->RB = NULL;

                }else if(strcmp(temp->lident,ident)== 0 && strcmp(temp->RB->lident,ident) != 0) {//estamos sobre a estaçao a eliminar mas o prox ponto nao pertence a ela
                    temp->RB->pont.nEntradas--;
                }
            }
            temp=temp->RA;
        }
    }
}

void verifica_na_linhaComboios(COMBOIO* todos[], char lident[], FERROVIA* todas[]){
    int i,d,z;
    COMBOIO* temp;

    for (i=0;i<MAX && todos[i] != NULL ;i++){
        if(strcmp(todos[i]->cart.lident,lident)==0 ){
            printf("Comboio: %s, pertencente à linha %s foi eliminado \n",todos[i]->cart.cident,lident);
            libertaComboio(todos[i]->cart.cident,todos);
            i=0;//Temos que voltar a verificar de inicio pois a lista foi reordenada.
        }
    }
    for (i=0;i<MAX && todos[i] != NULL; i++){

         if(todos[i]->cart.linha_actual != NULL && strcmp(todos[i]->cart.linha_actual->lident,lident)==0) {

            for(temp=todos[i],d=temp->cart.nCarruagens; temp != NULL; temp=temp->prox, d--){
                PosInicial(temp, todas);

                for (z=d*2*temp->cart.DimBOLAS; z>0 ; z--) {
                    moveCarr(temp,todas);
                }
            }
        }
    }
}

FERROVIA* procuraID(FERROVIA* lista[],char lident[],char IDE_X[]){
    int i,p;
    FERROVIA* TempX=NULL;

    for(i=0;i<MAX;i++){
        if (lista[i]!=NULL){
            if( strcmp(lident,lista[i]->lident) == 0 ) {
                TempX=lista[i];
                break;
            }
        }
    }
    if (TempX==NULL){
       printf("ERRO, ID de linha nao encontrado, verificar ficheiro de config!");
       exit(0);
    }
    p = nPontos(TempX);

    for (i=0; i<p; i++) {
            if(strcmp(TempX->pont.pident,IDE_X)==0){
                return TempX;
            }
            TempX=TempX->RA;
    }
    printf("ERRO, ID de ponto nao encontrado, verificar ficheiro de config!");
    exit(0);
}

void trocaCarris(FERROVIA* PercursoA, COMBOIO *todos[]){
    int i,k=0;
    COMBOIO* temp;
    for (i=0; i < MAX && todos[i] != NULL; i++){
        for (temp = todos[i];temp !=NULL; temp=temp->prox){
            if (PercursoA == temp->cart.linha_actual)
                k=1;
        }
    }
    if ( k != 1) {
        FERROVIA *temp1=PercursoA->RA;
        PercursoA->RA = PercursoA->RB;
        PercursoA->RB = temp1;
    }
}
/*void mostraCores(int cores[DIMCores][DIMrgb]){ funcao de apoio a debug
    int i,j;
    for(i=0;i<DIMCores;i++){
        for(j=0;j<DIMrgb;j++)
            printf("%d, ", cores[i][j]);
        printf("\n");
    };
}*/
void printCor(int corc){
	if (corc == VERMELHO){
        printf("VERMELHO \n");
    }else if (corc == AMARELO) {
        printf("AMARELO \n");
    }else if (corc == CYAN) {
        printf("CYAN \n");
    }else if (corc == ROXO) {
        printf("ROXO \n");
    }else if (corc == VERDE) {
        printf("VERDE \n");
    }else if (corc == CASTANHO) {
        printf("CASTANHO \n");
    }else if (corc == PRETO){
        printf("PRETO \n");
    }else if (corc == CINZENTO) {
        printf("CINZENTO \n");
    }else if (corc == BRANCO) {
        printf("BRANCO \n");
    }else if (corc == AZUL) {
        printf("AZUL \n");
	}
}

int convCor(char corestr[]){
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
        return 100;
    }
}

int nPontos(FERROVIA* lista){
    if (lista == NULL)
        return 0;
    int numero=1;
    while (lista->RA!=NULL && strcmp(lista->lident,lista->RA->lident)==0){//
        numero++;
        lista=lista->RA;
    }
    return numero;
}

void criarComboio(COMBOIO *todos[], FERROVIA *todas[]){
	CARRUAGEM nova;
	char cor[MAX], ident[MAX];
	int i;
	FERROVIA* head = NULL;
    memset(nova.cident,0,3);
    memset(nova.lident,0,5);
    memset(nova.pident,0,5);
	printf("Comboios existentes: ");
	listaComboio(todos,1);
	printf("Escreva o identificador do novo comboio: ");
    scanf("%s", ident);
    strncpy(nova.cident,ident,dimCIDENT-1);

	if(nova.cident[0]==' '||nova.cident[0]=='\n'||nova.cident[0]=='\0'){
		printf("\nInsira um identificador correto para a proxima \n");
		return;
	}
	for(i=0; i<MAX&&todos[i]!=NULL;++i){
		if(strcmp(nova.cident, todos[i]->cart.cident)==0){
			printf("\nComboio ja existente! Erro na criaçao de comboio.\n");
			return;
		}
	}
	printf("Insira raio da carruagem (entre 4 e 10): ");
	scanf("%d",  &nova.DimBOLAS);
	while(nova.DimBOLAS>10||nova.DimBOLAS<4){
		printf("\nInsira o valor entre 4 e 10: ");
		scanf("%d",  &nova.DimBOLAS);
	}
	printf("\nEscreva a cor (SEM ESPAÇOS E EM MAIUSCULAS) de entre a lista de cores: \n"
	"VERMELHO, AZUL, AMARELO, CYAN, ROXO, \nVERDE, CASTANHO, PRETO, CINZENTO, BRANCO \n");
	do{
		scanf("%100s", cor);
		nova.cor = convCor(cor);
	}while(nova.cor==100);
	printf("Escolha a linha para a posição inicial diante das existentes(SEM ESPAÇOS)\n:");
	if(listaFerrovias(todas)==0)
		return;
    memset(ident,0,MAX);
	scanf("%s", ident);
    strncpy(nova.lident,ident,dimLIDENT-1);
	for(i=0; i<MAX&&todas[i]!=NULL;++i){
		if(strcmp(nova.lident, todas[i]->lident)==0){
			head=todas[i];
			break;
		}
	}
	if(head==NULL){
		printf("\nLinha não encontrada, escreva bem para a próxima!\n");
		return;
	}
	printf("\nEscolha o ponto de entre os existentes nessa linha: \n");
	mostraPontos(todas, nova.lident);
	memset(ident,0,MAX);
	scanf("%s",ident);
    strncpy(nova.pident,ident,dimPIDENT-1);
	procuraID(todas, nova.lident, nova.pident);
	printf("\nInsira o numero de serviços \n");
	scanf("%d", &nova.nservico);
	i=0;
	while(todos[i]!=NULL){
		i=i+1;
	}
	nova.nCarruagens = 4;
	nova.locomotiva = 1;
	todos[i] = inicComboios(nova);
	printf("Comboio CRIADO \n");
}
void mostraPontos(FERROVIA *todas[], char lident[]){
    FERROVIA* head = NULL;
    int i;
    for( i=0 ; i<MAX ; i++){
        if (todas[i]!=NULL){
            if(strcmp(lident,todas[i]->lident)==0){
               head=todas[i];
               break;
           }
        }
     }
    if (head==NULL){
        // se nao existirem linhas, esta condição é sempre verificada.
       printf("ERRO, ID de linha nao encontrado! Verificar se o ID foi introduzido correctamente\n");
       return;
    }

    while(head!=NULL && strcmp(lident,head->lident) == 0 ){
       printf("IDENTIFICADOR : %s \n",head->pont.pident);
       head=head->RA;
    }
}

int verificaColisoes(COMBOIO* lista[]){
    COMBOIO *temp, *compara;
    int k,m,ret = 0;
    double distancia=0;
    int nComboios=listaComboio(lista,0);
    if (nComboios > 1){

        for (k=0;k<nComboios;k++){
            for (m=0;m<nComboios;m++){
				if(m!=k){//para que nao se compare o mesmo comboio
					for(compara=lista[m];compara!=NULL;compara=compara->prox){
						if(strcmp(lista[k]->cart.linha_actual->lident,compara->cart.linha_actual->lident)==0){
							distancia = (compara->cart.DimBOLAS+lista[k]->cart.DimBOLAS) + sqrt(  pow( lista[k]->cart.PosiNoGraf[coordX] - compara->cart.PosiNoGraf[coordX],2) + pow(lista[k]->cart.PosiNoGraf[coordY] - compara->cart.PosiNoGraf[coordY],2 ) );

							if(distancia < DISTSEG ){
								ret = 1;
								for(temp=lista[k];temp!=NULL;temp=temp->prox)
									temp->PARACOMBOIO = true;
								for(temp=lista[m];temp!=NULL;temp=temp->prox)
									temp->PARACOMBOIO = true;
							}
						}
					}
				}
            }
        }
    }
    return ret;// se 0 não há colisões
}
