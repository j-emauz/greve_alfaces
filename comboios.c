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

COMBOIO* init_Comboios(){
    COMBOIO*head = (COMBOIO*)calloc(1,sizeof(COMBOIO));
    if (head==NULL){
     printf("Falha na aquisiçao de bloco de memória, função initcomboio \n");
     exit(0);
    }
    head->prox=NULL;
    return head;
}


COMBOIO* add_Comboio(COMBOIO* head,CARRUAGEM dados){
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

void mostraComboio(COMBOIO* topo) {
    //WIP
    printf("Da locomotiva...\n");
    while(topo->prox!=NULL){
        printf("%s \n",topo->prox->cart.ident);
        printf("%d %d \n",topo->prox->cart.PosiNoGraf[0],topo->prox->cart.PosiNoGraf[1]);
        printf("%p \n",topo->prox);
        topo=topo->prox;
    }
    printf("à ultima carruagem \n");

}

void gera_cor(COMBOIO* Combo){
    /*
    para as estações


    */
}
