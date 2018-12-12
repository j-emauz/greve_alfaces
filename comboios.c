#include "comboios.h"

int ler(char *argv[]/*, PASSAR ESTRUTURAS */){
	FILE *fp;
	char nome_de_ficheiro[MAX];
	strcpy(nome_de_ficheiro, argv[1]);
	
	fp = fopen(nome_de_ficheiro, "r");
	
	if (fp == NULL){
		printf("Erro na abertura do ficheiro! Verifique se está no sitio certo ou se o nome ta correto\n");
		return 0;
		
	}else{
		printf("%s\n", nome_de_ficheiro);
		return 1;
	}
	
	/* funcao para criar/adicionar a lista*/
	fclose(fp);
}

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
