#include "comboios.h"

int main(int argc, char *argv[]){
	char opcao='0';
	if(argc!=2){
		printf("Por favor insira o nome do ficheiro \n""Exemplo: ./comboios hahayes.txt\n");
		exit(0);
	}
		
	if(ler(argv/*,    */) == 0)
		exit(0);
		
	do{
		menu(&opcao);
		switch(opcao)
		{
			case '1':
				printf("Haha yes\n");
				break;
			case '2':
				printf("hwqeqwjihjihe\n");
				break;
			case '3':
				printf("Subscribe to PewDiePie\n");
				break;
			case '4':
				printf("Suicidio é a resposta\n");
				break;
			case '5':
				printf("Haha no\n");
				break;
		}
	}while(opcao!='0');
	return 0;
}
