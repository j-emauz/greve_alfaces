#include "comboios.h"

void passarespacos(char **aux){
	do{
		*aux = (strstr(*aux, " ") + 1);
	}while((*aux)[0] == ' ');
}

int ler(char *argv[]/*,    */){
	FILE *fp;
	char linha[MAX];
	char *aux;
	char cident[3]={'\0'};
	char pident[5];
	char pident1[5];
	char lident[5];
	char lident1[5];
	char tipo[4];
	int i=1;
	char fim_linha[MAX];
	int janx, jany; /*//coordenadas da janela, provavelmente passar por endereço*/
	int raio;
	char cor[MAX];
	int t;
	
	fp = fopen(argv[1], "r");
	
	if (fp == NULL){
		printf("Erro na abertura do ficheiro! Verifique se está no sitio certo ou se o nome ta correto\n");
		fclose(fp);
		return 0;
		
	}
	else{
		do{
			fgets(linha, MAX, fp);
			if((linha[0]!='%')&&(linha[0]!='\n')){
				aux = linha;
				if(strspn(linha, "JANELA:")==strlen("JANELA:")){
					passarespacos(&aux);
					sscanf(aux, "%d %d", &janx, &jany);
					printf("%d %d", janx, jany);
				}
				if(strspn(linha, "COMBOIO:")==strlen("COMBOIO:")){
					passarespacos(&aux);
					strncpy(cident, aux, strcspn(aux, " "));
					  printf("ident = %s", cident);
					passarespacos(&aux);
					sscanf(aux, "%d", &raio);
					  printf("numero carruagens = %d ", raio);
					passarespacos(&aux);
					strncpy(cor, aux, strcspn(aux, " "));
					  printf("cor = %s \n", cor);
					 /* memset(cor,0,strlen(cor));//faz clear da string*/
					passarespacos(&aux);
					strncpy(lident, aux, strcspn(aux, " "));
					passarespacos(&aux);
					strncpy(pident, aux, strcspn(aux, " "));
					passarespacos(&aux);
					sscanf(aux, "%d", &t);
					printf("tempo = %d", t);
					//funcao adicionar comboio
				}
				if((strspn(linha, "LINHA:") == strlen("LINHA:"))){
					passarespacos(&aux);
					strcpy(lident, aux);
					printf("%s \n", lident);//para testar
					strcpy(fim_linha, "FIM_DE_LINHA: ");
					//strcat(fim_linha, lident);
					//printf("%s", fim_linha);
					while(strstr(linha, fim_linha)==NULL){
						fgets(linha, MAX, fp);
						if((linha[0]!='%')&&(linha[0]!='\n')){
							passarespacos(&aux);
							strncpy(pident, aux, strcspn(aux, " "));
							passarespacos(&aux);
							sscanf(aux, "%d %d", &posx, &posy);
							passarespacos(&aux);
							passarespacos(&aux);
							strncpy(cor, aux, strcspn(aux, " ");
							passarespacos(&aux);
							strcpy(tipo, aux);
							//passar para linha
							memset(pident,0,strlen(pident));
							memset(cor,0,strlen(cor));
							memset(tipo,0,strlen(tipo));
							//printf("%s", linha);
						}
					}
					memset(lident,0,strlen(lident));
				}
				if(strspn(linha, "LIGAR:")==strlen("LIGAR:")){
					passarespacos(&aux);
					strncpy(lident, aux, strcspn(aux, " "));
					passarespacos(&aux);
					strncpy(pident, aux, strcspn(aux, " "));
					passarespacos(&aux);
					strncpy(lident1, aux, strcspn(aux, " "));
					passarespacos(&aux);
					strcpy(pident1, aux);
					//funcao ligar
				}
				
			};
		}while(feof(fp)==0);
		fclose(fp);
		return 1;
	}
	
}

