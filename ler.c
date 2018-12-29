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
	char ident[MAX];
	
	sscanf(aux, "%s %d %d", ident,&jancoord[0], &jancoord[1]);
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
	sscanf(aux, "%s %d %s %s %s %d", cident, &raio, corc, lident, pident, &nservico); 

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
	char tipo[4]={'\0'};//
	PONTOS pontinho;

	sscanf(aux, "%s %d %d %s %s", pident, &posx, &posy, cor, tipo);
	

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
	char ident[MAX];
	
	passarespacos(&aux);
	
	sscanf("%s %s %s %s", lident1, pident1, lident2, pident2);

	printf("pontos %s %s %s %s", lident1, pident1, lident2, pident2);
	fflush(stdout);

    KonnectLinhas(todas,lident1,lident2,pident1,pident2);
	//PASSAR PARA ESTRUTURAS

}

int ler(char *argv[], COMBOIO *todos[], FERROVIA *todas[], int jancoord[]){
	FILE *fp = NULL;
	char linha[MAX];
	char *aux = NULL;
	char lident[5];
	char ident[MAX];
	char fim_linha[MAX];
	int i=0, j=0;
	int n;

	fp = fopen(argv[1], "r");

	if (fp == NULL){
		printf("Erro na abertura do ficheiro! Verifique se está no sitio certo ou se o nome ta correto\n");
		return 0;

	}
	else{
		do{
			fgets(linha, MAX, fp);//lê e avança linha no ficheiro de config
            for(n=0;n<MAX;n++){
                if (linha[n] == '\n'){
                    linha[n] = '\0';
					break;
				}
            }
            

			if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!='\0')){

				//printf("no aux = linha. linha = %s \n",linha); //OK
				aux = linha;//aux aponta para o primeiro elemento de linha.
//                gets(&debug);
				if(strspn(linha, "JANELA:")==strlen("JANELA:")){
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
                    printf(" && aux %s \n ", aux);//para testar
					
					sscanf(linha, "%s %s", ident, lident); 
					
                    printf("Lident %s \n", lident);//para testar
//                    gets(&debug);

					todas[j] = inic_Linha(lident);
					strcpy(fim_linha, "FIM_DE_LINHA: ");
					//strcat(fim_linha, lident);
					printf("%s <-string fim de linha \n", fim_linha);
					

					while(strstr(linha, fim_linha)==NULL){

						if((linha[0]!='%')&&(linha[0]!='\n')){
							aux = linha;
							todas[j] = lerlinha(aux, todas[j]);

						}

						fgets(linha, MAX, fp);
						for(n=0;n<MAX;n++){
							if (linha[n] == '\n'){
								linha[n] = '\0';
								break;
							}
						}

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
