#include "comboios.h"


int main(int argc, char *argv[]){
    srand(time(NULL));
    char Indent[MAX];
	int cores[DIMCores][DIMrgb]={ {255,0,0,255},/* vermelho*/
                                  {0,0,255,255},/* azul    */
                                  {255,255,0,255}/* AMARELO */};

    COMBOIO* todos[MAX];
    FERROVIA* todas[MAX];
    int i=0;
    int jancoord[2];
    for (i=0;i<MAX;i++){
        todos[i]=NULL;
        todas[i]=NULL;
    }


	char opcao='0';
	if(argc!=2){
		printf("Por favor insira o nome do ficheiro \n""Exemplo: ./comboios hahayes.txt\n");
		exit(0);
	}
	if(ler(argv,todos,todas,jancoord) == 0)
		exit(0);

	do{
		menu(&opcao);
		switch(opcao)
		{
			case '1':
				printf("Haha yes\n");
				break;
			case '2':
				//print instruçoes
				ListaFerrovias(todas);
                printf("Escreva o ID da Ferrovia a eliminar sem espaços! \n");
                scanf("%s", Indent);
                elimina_linha(todas, Indent);
                memset(Indent, 0, MAX);
				break;
			case '3':
				printf("Subscribe to PewDiePie\n");
				break;
			case '4':
                ListaComboio(todos);
                printf("Escreva o ID do Comboio a eliminar sem espaços! \n");
                scanf("%s", Indent);
                elimina_comboio(todos, Indent);
                memset(Indent, 0, MAX);
               // fflush(stdout);
				break;
			case '5':

				mostraComboio(todos,todos[1]->cart.cident);
                elimina_comboio(todos, todos[1]->cart.cident);
				printf("Haha no\n");

				mostraLinha(todas,todas[0]->lident);
				elimina_linha(todas, todas[0]->lident);
				mostraLinha(todas,"PUTA");
				mostraLinha(todas,todas[0]->lident);
				//scanf("%c",&debug);*/

				break;
			case '6':
				printf("Simular");
				break;
		}
	}while(opcao!='0');
	return 0;
}
