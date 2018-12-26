#include "comboios.h"

void passarespacos(char **aux){
	if(strstr(*aux, " ")!=NULL){
		do{
			if((*aux)[0] == '\0')
				break;
			*aux = (strstr(*aux, " ") + 1);

		}while(((*aux)[0] == ' ')&&((*aux)[0]!='\n'));
	}
}

void lerjanela(char *aux, int jancoord[]){
	passarespacos(&aux);
	sscanf(aux, "%d %d", &jancoord[0], &jancoord[1]);
	 printf("Jan(x,y)= %d %d\n", jancoord[0], jancoord[1]);//testar
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
	char pident[5];
	int posx, posy;
	char cor[MAX]={'\0'};
	int cornum;
	char tipo[4];
	PONTOS pontinho;

	 printf("Haha yes\n");
	 fflush(stdout);

	strncpy(pident, aux, strcspn(aux, " "));
    //printf(" %s ", pident);
	passarespacos(&aux);
	sscanf(aux, "%d %d", &posx, &posy);
	 printf(" %d %d ", posx, posy);
	passarespacos(&aux);
	passarespacos(&aux);
	strncpy(cor, aux, strcspn(aux, " "));
	 printf(" %s ", cor);

    cornum = ConvCor(cor);

	passarespacos(&aux);
	strcpy(tipo, aux);
	 printf(" %s \n", tipo);
	 printf("%s \n", aux);
	//Adicionar failsafe para cor e tipo errado (igual para comboio)
	//passar para linha
	//-vestigios de quando a funcao tinha outro fgets dentro

	//printf("%s", linha);*/


	strcpy(pontinho.pident, pident);
	pontinho.coord[0]=posx;
	pontinho.coord[1]=posy;
	pontinho.cor=cornum;
	strcpy(pontinho.TipoDePonto, tipo);
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
	FILE *fp;
	char linha[MAX];
	char *aux;
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
			fgets(linha, MAX, fp);
			if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!='\0')){
				aux = linha;

				if(strspn(linha, "JANELA:")==strlen("JANELA:")){
					lerjanela(aux, jancoord);
				}

				if(strspn(linha, "COMBOIO:")==strlen("COMBOIO:")){
					todos[i] = lercomboio(aux);
					i=i+1;

					//funcao adicionar comboio
				}
				if((strspn(linha, "LINHA:") == strlen("LINHA:"))){

					passarespacos(&aux);
					strcpy(lident, aux);
                    printf("%s \n", lident);//para testar

					todas[j] = inic_Linha(lident);
					strcpy(fim_linha, "FIM_DE_LINHA: ");
					//strcat(fim_linha, lident);
					printf("%s", fim_linha);
					fgets(linha, MAX, fp);

					while(strstr(linha, fim_linha)==NULL){

						if((linha[0]!='%')&&(linha[0]!='\n')){
							aux = linha;
							todas[j] = lerlinha(aux, todas[j]);

						}
						fgets(linha, MAX, fp);
					}
					memset(lident,0,strlen(lident));
					mostraLinha(todas[j]);
					j=j+1;
				}
				if(strspn(linha, "LIGAR:")==strlen("LIGAR:")){
					lerligar(aux,todas);
					//funcao ligar
				}

			};
		}while(feof(fp)==0);
		fclose(fp);
		return 1;
	}

}

