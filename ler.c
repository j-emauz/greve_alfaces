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

void lerJanela(char *aux, int jancoord[]){//le elementos de linha com dimensoes de janela grafica
	char ident[MAX];
	sscanf(aux, "%s %d %d", ident ,&jancoord[0], &jancoord[1]);
}

COMBOIO *lerComboio(char *aux){//le dados de comboio e inicializa-o numa lista dinâmica
	char corc[MAX]={'\0'};
	CARRUAGEM dados;
	COMBOIO *thomas;

	passarEspacos(&aux);//para passar à frente a parte nao ikmportante da linha "COMBOIO:"
	sscanf(aux, "%s %d %s %s %s %d", dados.cident, &(dados.DimBOLAS), corc, dados.lident, dados.pident, &dados.nservico);
    dados.linha_actual = NULL;//depois inicializado no SDL
	dados.nCarruagens = 4;//igual sempre
	dados.cor = convCor(corc);//converte string cor para inteiro correspondente
	dados.locomotiva = 1;//primeira carruagem é locomotiva
	if (dados.cor == 100)//Desta forma Conv Cor pode ser reutilizada
        exit(0);
	thomas = inicComboios(dados);
	return thomas;
}

FERROVIA *lerLinha(char *aux, FERROVIA *head, char lident[]){//obtem e poe na lista dinamica o ponto correspondente
	char cor[MAX]={'\0'};
	PONTOS pontinho;
	pontinho.nEntradas=0;//dados nao lidos do programa, inicializados a 0
	pontinho.nSaidas=0;
	pontinho.Dimensao = 0;

	sscanf(aux, "%s %d %d %s %s", pontinho.pident, &pontinho.coord[coordX], &pontinho.coord[coordY], cor, pontinho.TipoDePonto);
    pontinho.cor = convCor(cor);

    if (pontinho.cor == 100)//certifica que cor foi bem inicializada
        exit(0);

    if(strcmp(pontinho.TipoDePonto, "EST") == 0){
		pontinho.Dimensao = dimEST;
	}else if(strcmp(pontinho.TipoDePonto, "VIA") == 0){
		pontinho.Dimensao = dimVIA;
	}

    if(head==NULL){
        head = inicLinha(lident, pontinho);//se for o primeiro ponto da linha inicializa
    }else{
        head = addLinha(head, pontinho);//se for outro ponto adiciona a linha ja existente
    }
	memset(cor,0,strlen(cor));//substitui todos os caracteres do vetor cor por '\0'
	return head;
}

void lerLigar(char *aux, FERROVIA* todas[]){//obtem dados para ligar do ficheiro e liga linhas
	char lident1[5];
	char pident1[5];
	char lident2[5];
	char pident2[5];

	passarEspacos(&aux);
	sscanf(aux, "%s %s %s %s", lident1, pident1, lident2, pident2);
    ligaLinhas(todas,lident1,lident2,pident1,pident2);
}

int ler(char *argv[], COMBOIO *todos[], FERROVIA *todas[], int jancoord[]){//funcao geral para ler o ficheiro de configuracao
	FILE *fp = NULL;
	char *aux = NULL;
	char lident[dimLIDENT], ident[MAX], fim_linha[MAX], linha[MAX];
	int i=0, j=0, n;

	fp = fopen(argv[1], "r");//primeira palavra a seguir ao ./comboios inserido no terminal
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
				for(n=0;n<MAX;n++){// substitui o \n no fim da linha por \0, \n final nao fica no ultimo vetor
					if (linha[n] == '\n'){
						linha[n] = '\0';
                        break;
					}
				}
				while(strstr(linha, fim_linha)==NULL){//enquanto nao chegar aos dados de fim da linha
                    if((linha[0]!='%')&&(linha[0]!='\n')&&(linha[0]!=' ')){//skip comentarios e linhas em branco
						aux = linha;
						todas[j] = lerLinha(aux, todas[j], lident);//até chegar ao fim de linha, todas[j] é igual, mesma linha
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
				j=j+1;//é diferente pois a proxima sera outra linha
			}else if(strspn(linha, "LIGAR:")==strlen("LIGAR:")){
				lerLigar(aux,todas);
            }
		}
    }while(feof(fp)==0);//enquanto nao chegar ao fim do ficheiro
    fclose(fp);
    return 1;//return 1 se ler corretamente
}
