#include "comboios.h"

char * passarespacos(char *aux){
	aux = (strstr(aux, " ") + 1);
	do{
		if((aux)[0] == '\0')
			break;
		

	}while((aux[0] == ' '));
	return aux;
}

void lerjanela(char *aux, int *janx, int *jany){
	aux = passarespacos(aux);
	sscanf(aux, "%d %d", janx, jany);
	 printf("Jan(x,y)= %d %d\n", *janx, *jany);//testar
}

void lercomboio(char *aux){
	char cident[3]={'\0'};
	int raio;
	char corc[MAX]={'\0'};
	char lident[5];
	char pident[5];
	int tempo;
	
	aux = passarespacos(aux);
	strncpy(cident, aux, strcspn(aux, " "));
	 printf("ident = %s ", cident);
	aux = passarespacos(aux);
	sscanf(aux, "%d", &raio);
	 printf("numero carruagens = %d ", raio);
	aux = passarespacos(aux);
	strncpy(corc, aux, strcspn(aux, " "));
	 printf("cor = %s ", corc);
	memset(corc,0,strlen(corc));//faz clear da string*/
	 aux = passarespacos(aux);
	strncpy(lident, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	strncpy(pident, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	sscanf(aux, "%d", &tempo);
	 printf("tempo = %d", tempo);
	
	//PASSAR DADOS PARA ESTRUTURA
}

void lerlinha(char *aux){
	char pident[5];
	int posx, posy;
	char cor[MAX];
	char tipo[4];
	
	printf("Haha yes\n");
	fflush(stdout);
	
	aux = passarespacos(aux);
	printf("Haha yes\n");
	fflush(stdout);
	strncpy(pident, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	sscanf(aux, "%d %d", &posx, &posy);
	aux = passarespacos(aux);
	strncpy(cor, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	strcpy(tipo, aux);
	//Adicionar failsafe para cor e tipo errado (igual para comboio)
	//passar para linha
	//-vestigios de quando a funcao tinha outro fgets dentro
	memset(pident,0,strlen(pident));
	memset(cor,0,strlen(cor));
	memset(tipo,0,strlen(tipo));
	//printf("%s", linha);*/
}

void lerligar(char *aux){
	char lident[5];
	char pident[5];
	char lident1[5];
	char pident1[5];
	
	aux = passarespacos(aux);
	strncpy(lident, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	strncpy(pident, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	strncpy(lident1, aux, strcspn(aux, " "));
	aux = passarespacos(aux);
	strcpy(pident1, aux);
	
	//PASSAR PARA ESTRUTURAS
	
}

int ler(char *argv[]/*,    */){
	FILE *fp;
	char linha[MAX];
	char *aux;
	char lident[5];
	char fim_linha[MAX];
	int janx, jany; //coordenadas da janela, provavelmente passar por endereço
	
	fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("Erro na abertura do ficheiro! Verifique se está no sitio certo ou se o nome ta correto\n");
		fclose(fp);
		return 0;
		
	}
	else{
		do{
			fgets(linha, MAX, fp);
			if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!='\0')){
				aux = linha;
				if(strspn(linha, "JANELA:")==strlen("JANELA:")){
					lerjanela(aux, &janx, &jany);
				}
				if(strspn(linha, "COMBOIO:")==strlen("COMBOIO:")){
					lercomboio(aux);
					//funcao adicionar comboio
				}
				if((strspn(linha, "LINHA:") == strlen("LINHA:"))){
					aux = passarespacos(aux);
					strcpy(lident, aux);
					printf("%s \n", lident);//para testar
					strcpy(fim_linha, "FIM_DE_LINHA: ");
					//strcat(fim_linha, lident);
					//printf("%s", fim_linha);
					while(strstr(linha, fim_linha)==NULL){
						fgets(linha, MAX, fp);
						
						if((linha[0]!='%')&&(linha[0]!='\n')){
							aux = linha;
							lerlinha(aux);
						}
					}
					memset(lident,0,strlen(lident));
				}
				if(strspn(linha, "LIGAR:")==strlen("LIGAR:")){
					lerligar(aux);
					//funcao ligar
				}
				
			};
		}while(feof(fp)==0);
		fclose(fp);
		return 1;
	}
	
}

