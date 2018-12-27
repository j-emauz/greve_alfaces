#include "comboios.h"


void passarespacos(char **aux){
/*
    Passa o endereço de um vetor "string".
    até encontrar um espaço vai avançando um char
*/
    printf("aux0 : %s \n",*aux);//OK
	if(strstr(*aux, " ")!=NULL){
		do{

			if((*aux)[0] == '\0')
				break;
			*aux = (strstr(*aux, " ") + 1);

		}while(((*aux)[0] == ' ')&&((*aux)[0]!='\n'));
		printf("aux Passa espaços : %s \n",*aux);// OK
	}
}

void lerjanela(char *aux, int jancoord[]){
	passarespacos(&aux);
	sscanf(aux, "%d %d", &jancoord[0], &jancoord[1]);
	 printf("Jan(x,y)= %d %d \n", jancoord[0], jancoord[1]);//OK
}

COMBOIO *lercomboio(char *aux){
	char cident[3]={'\0'};
	int raio;
	char corc[MAX]={'\0'};
	int corn;
	char lident[5];
	char pident[5];
	int nservico;
	CARRUAGEM dados;
	COMBOIO *thomas;

	passarespacos(&aux);

	strncpy(cident, aux, strcspn(aux, " "));
	 printf("ident = %s ", cident);
	passarespacos(&aux);

	sscanf(aux, "%d", &raio);
	 printf("numero carruagens = %d ", raio);
	passarespacos(&aux);

	strncpy(corc, aux, strcspn(aux, " "));
	 printf("cor = %s ", corc);
	corn= ConvCor(corc);
	memset(corc,0,strlen(corc));//faz clear da string*/
	passarespacos(&aux);

	strncpy(lident, aux, strcspn(aux, " "));
	passarespacos(&aux);

	strncpy(pident, aux, strcspn(aux, " "));
	passarespacos(&aux);

	sscanf(aux, "%d", &nservico);
	 printf("tempo = %d", nservico);

	strcpy(dados.cident, cident);

	dados.nCarruagens = 4;
	dados.DimBOLAS = raio;
	dados.cor = corn;

	strcpy(dados.lident, lident);
	strcpy(dados.pident, pident);

	dados.nservico = nservico;

	thomas = inic_Comboios();
	thomas = addi_Comboio(thomas, dados);

	return thomas;
}

FERROVIA *lerlinha(char *aux, FERROVIA *head){
	char pident[5]={'\0'};
	int posx =0, posy=0;
	char cor[MAX]={'\0'};
	int cornum;//
	char tipo[4]={'\0'};//
	PONTOS pontinho;

	// printf("Haha yes\n");
	 fflush(stdout);
    strncpy(pident, aux, strcspn(aux, " "));
	//strncpy(pontinho.pident, aux, strcspn(aux, " ")); //porque nao logo assim?

    strcpy(pontinho.pident, pident);

	//printf(" PIDENT  1 %s \n", pident);//ESTÁ OK
    printf(" PIDENT  3 %s \n", pontinho.pident);


	passarespacos(&aux);

	sscanf(aux, "%d %d", &pontinho.coord[0]/*posx*/, &pontinho.coord[1]/*posy*/);


	printf(" %d %d \n",pontinho.coord[0],pontinho.coord[1] /*posx, posy*/);
	passarespacos(&aux);
	passarespacos(&aux);
	strncpy(cor, aux, strcspn(aux, " "));
	printf(" %s \n", cor);

    pontinho.cor = ConvCor(cor);
    //cornum = ConvCor(cor);
	passarespacos(&aux);

	strcpy(pontinho.TipoDePonto, aux);// problematico


printf(" PIDENT depois strncopy2 %s \n", pontinho.pident);
	 printf("tipo %s \n", pontinho.TipoDePonto);
	 printf("aux %s \n", aux);
	//Adicionar failsafe para cor e tipo errado (igual para comboio)
	//passar para linha
	//-vestigios de quando a funcao tinha outro fgets dentro

	//printf("%s", linha);*/




	pontinho.coord[0]=posx;
	pontinho.coord[1]=posy;
	//pontinho.cor=cornum;
	//strcpy(pontinho.TipoDePonto, tipo);
	pontinho.nEntradas = 0;
	pontinho.nSaidas = 0;

	head = addi_Linha(head, pontinho);

	memset(pident,0,strlen(pident));
	memset(cor,0,strlen(cor));
	memset(tipo,0,strlen(tipo));

	return head;
}

void lerligar(char *aux, FERROVIA* todas[]){
	char lident1[5];
	char pident1[5];
	char lident2[5];
	char pident2[5];

	memset(lident1,0,5);
	memset(pident1,0,5);
	memset(lident2,0,5);
	memset(pident2,0,5);

	passarespacos(&aux);
	printf("%s \n", aux);

	strncpy(lident1, aux, strcspn(aux, " "));
	passarespacos(&aux);
	printf("%s \n", aux);

	strncpy(pident1, aux, strcspn(aux, " "));
	passarespacos(&aux);
	printf("%s \n", aux);

	strncpy(lident2, aux, strcspn(aux, " "));
	passarespacos(&aux);
	printf("%s \n", aux);

	strcpy(pident2, aux);
	printf("%s \n", aux);

	printf("%s %s %s %s", lident1, pident1, lident2, pident2);

    KonnectLinhas(todas,lident1,lident2,pident1,pident2);
	//PASSAR PARA ESTRUTURAS

}

int ler(char *argv[], COMBOIO *todos[], FERROVIA *todas[], int jancoord[]){
	FILE *fp = NULL;
	char linha[MAX];
	char *aux = NULL;
	char lident[5];
	char fim_linha[MAX];
	int i=0, j=0;

	fp = fopen(argv[1], "r");

	if (fp == NULL){
		printf("Erro na abertura do ficheiro! Verifique se está no sitio certo ou se o nome ta correto\n");
		return 0;

	}
	else{
		do{
			fgets(linha, MAX, fp);//lê e avança linha no ficheiro de config
       /*     for(i=0;i<MAX;i++){
                if (linha[i] == '\n')
                    //linha[i] = '\0';
            }*/

			if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!='\0')){

				//printf("no aux = linha. linha = %s \n",linha); //OK
				aux = linha;//aux aponta para o primeiro elemento de linha.
//                gets(&debug);
				if(strspn(linha, "JANELA:")==strlen("JANELA:")){
					printf("no aux = janela. linha = %s \n",linha); //OK
					lerjanela(aux, jancoord);//adquire dados da janela
				}
				if(strspn(linha, "COMBOIO:")==strlen("COMBOIO:")){
					printf("no aux = comboio. linha = %s \n",linha); //OK
					todos[i] = lercomboio(aux);//coloca um apontador para comboio no vetor de apontadores todos, posição i
					i=i+1;

					//funcao adicionar comboio
				}
				if(strspn(linha, "LINHA:") == strlen("LINHA:")){
                printf("no aux = linha. linha = %s \n",linha); //OK
					passarespacos(&aux);//avança aux até chegar a um char diff de " "
                    printf(" && aux %s \n ", aux);//para testar
					strncpy(lident, aux, strcspn(aux, "\0"));//mudei
                    printf("Lident %s \n", lident);//para testar
//                    gets(&debug);

					todas[j] = inic_Linha(lident);
					strcpy(fim_linha, "FIM_DE_LINHA: ");
					//strcat(fim_linha, lident);
					printf("%s <-string fim de linha \n", fim_linha);
					fgets(linha, MAX, fp);
                    /*for(i=0;i<MAX;i++){
                        if (linha[i] == '\n')
                            linha[i] = '\0';
                    }*/

					while(strstr(linha, fim_linha)==NULL){

						if((linha[0]!='%')&&(linha[0]!='\n')){
							aux = linha;
							todas[j] = lerlinha(aux, todas[j]);

						}

						fgets(linha, MAX, fp);
				/*		for(i=0;i<MAX;i++){
                            if (linha[i] == '\n')
                          //      linha[i] = '\0';
                        }
*/
					}
					memset(lident,0,strlen(lident));
					//gets(&debug);
					mostraLinha(todas[j]);
					j=j+1;
				}
				if(strspn(linha, "LIGAR:")==strlen("LIGAR:")){
					printf("no aux = linhaligar . linha = %s \n",linha); //OK
					lerligar(aux,todas);
					//funcao ligar
				}

			};
		}while(feof(fp)==0);
		fclose(fp);
		return 1;
	}

}
