#include "comboios.h"


int main(int argc, char *argv[]){
    srand(time(NULL));

    int i=0;
    int jancoord[2];
    char opcao='0';

    COMBOIO* todos[MAX];
    FERROVIA* todas[MAX];
    for (i=0;i<MAX;i++){
        todos[i]=NULL;
        todas[i]=NULL;
    }

	if(argc!=2){
		printf("Por favor insira o nome do ficheiro \n""Exemplo: ./comboios hahayes.txt\n");
		exit(0);
	}
	if(ler(argv,todos,todas,jancoord) == 0)
		exit(0);

	do{
		menu(&opcao);
		getchar();//limpa buffer de stdin
		switch(opcao)
		{
			case '1': // MOSTRA FERROVIA
				mostraLinha(todas);
				break;
			case '2': // ELIMINA FERROVIA
				//print instruçoes
                //scanf("%s", Indent);
                eliminaLinha(todas);
                //memset(Indent, 0, MAX);
				break;
			case '3': // MOSTRA COMBOIOS
				mostraComboio(todos);
				break;
			case '4': // ELIMINA COMBOIOS
                // Lista para depois eliminar por ID
                eliminaComboio(todos);
 				break;
			case '5':
				criarComboio(todos, todas);

				break;
			case '6':
				printf("Simular");
				break;
		}
	}while(opcao!='0');
	return 0;
}
