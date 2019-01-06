#include "comboios.h"

void passarEspacos(char **aux){
/*  Passa o endereço de um vetor "string".
    até encontrar um espaço vai avançando um char
*/
    if(strstr(*aux, " ")!=NULL){
		do{
			if((*aux)[0] == '\0')
				break;
			*aux = (strstr(*aux, " ") + 1);

		}while(((*aux)[0] == ' ')&&((*aux)[0]!='\n'));
	}
}

void lerJanela(char *aux, int jancoord[]){
	char ident[MAX];
	sscanf(aux, "%s %d %d", ident ,&jancoord[0], &jancoord[1]);
}

COMBOIO *lerComboio(char *aux){
	char corc[MAX]={'\0'};
	CARRUAGEM dados;
	COMBOIO *thomas;

	passarEspacos(&aux);
	sscanf(aux, "%s %d %s %s %s %d", dados.cident, &(dados.DimBOLAS), corc, dados.lident, dados.pident, &dados.nservico);
    dados.linha_actual = NULL;
	dados.nCarruagens = 4;
	dados.cor = convCor(corc);
	dados.locomotiva = 1;
	if (dados.cor == 100)//Desta forma Conv Cor pode ser reutilizada
        exit(0);
	thomas = inicComboios(dados);
	return thomas;
}

FERROVIA *lerLinha(char *aux, FERROVIA *head, char lident[]){
	char cor[MAX]={'\0'};
	PONTOS pontinho;
	pontinho.nEntradas=0;
	pontinho.nSaidas=0;
	pontinho.Dimensao = 0;

	sscanf(aux, "%s %d %d %s %s", pontinho.pident, &pontinho.coord[coordX], &pontinho.coord[coordY], cor, pontinho.TipoDePonto);
    pontinho.cor = convCor(cor);

    if (pontinho.cor == 100)//Desta forma Conv Cor pode ser reutilizada
        exit(0);

    if(strcmp(pontinho.TipoDePonto, "EST") == 0){
		pontinho.Dimensao = dimEST;
	}else if(strcmp(pontinho.TipoDePonto, "VIA") == 0){
		pontinho.Dimensao = dimVIA;
	}

    if(head==NULL){
        head = inicLinha(lident, pontinho);
    }else{
        head = addLinha(head, pontinho);
    }
	memset(cor,0,strlen(cor));
	return head;
}

void lerLigar(char *aux, FERROVIA* todas[]){
	char lident1[5];
	char pident1[5];
	char lident2[5];
	char pident2[5];

	passarEspacos(&aux);
	sscanf(aux, "%s %s %s %s", lident1, pident1, lident2, pident2);
    ligaLinhas(todas,lident1,lident2,pident1,pident2);
}

int ler(char *argv[], COMBOIO *todos[], FERROVIA *todas[], int jancoord[]){
	FILE *fp = NULL;
	char *aux = NULL;
	char lident[dimLIDENT], ident[MAX], fim_linha[MAX], linha[MAX];
	int i=0, j=0, n;

	fp = fopen(argv[1], "r");
	if (fp == NULL){
		printf("Erro na abertura do ficheiro! Verifique se está no sitio certo ou se o nome ta correto\n");
		return 0;
	}
	do{
        fgets(linha, MAX, fp);//lê e avança linha no ficheiro de config
        for(n=0;n<MAX;n++){
            if (linha[n] == '\n'){
                linha[n] = '\0'; // substitui o \n no fim da linha por \0
				break;
			}
        }
		if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!='\0')){
			aux = linha;//aux aponta para o primeiro elemento de linha.
			if(strspn(linha, "JANELA:")==strlen("JANELA:")){
				lerJanela(aux, jancoord);//adquire dados da janela
			}else if(strspn(linha, "COMBOIO:")==strlen("COMBOIO:")){
				todos[i] = lerComboio(aux);//coloca um apontador para comboio no vetor de apontadores todos, posição i
				i=i+1;
			}else if(strspn(linha, "LINHA:") == strlen("LINHA:")){
				sscanf(linha, "%s %s", ident, lident);
				strcpy(fim_linha, "FIM_DE_LINHA: ");

				fgets(linha,MAX,fp);
				for(n=0;n<MAX;n++){
					if (linha[n] == '\n'){
						linha[n] = '\0';
                        break;
					}
				}
				while(strstr(linha, fim_linha)==NULL){
                    if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!=' ')){
						aux = linha;
						todas[j] = lerLinha(aux, todas[j], lident);
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
				j=j+1;
			}else if(strspn(linha, "LIGAR:")==strlen("LIGAR:")){
				lerLigar(aux,todas);
            }
		}
    }while(feof(fp)==0);
    fclose(fp);
    return 1;
}
