#include "comboios.h"

int main(int argc, char *argv[]){
	char opcao='0';
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