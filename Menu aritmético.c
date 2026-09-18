#include <stdio.h>

int main(){
	
	int opcao, n1, n2;
	
	printf("1 - Soma\n2- Subtra��o\n3- Multiplica��o\n4- Divis�o\n0- Sair\n\n");
	scanf("%d", &opcao);
	
	printf("Digite dois valores: ");
	scanf("%d%d",&n1, &n2);
	
	switch(opcao){
		case 0:
			printf("Saindo...\n");
			break;
		
		case 1:
			printf("Soma: %d\n",n1 + n2);
			break;
			
		case 2:
			printf("Subtra��o: %d\n",n1 - n2);
			break;
			
		case 3:
			printf("Multiplica��o: %d\n", n1 * n2);
			break;
			
		case 4:
			while(n2 == 0){
			printf("N�o existe divis�o por zero!\nDigite outro valor!: ");
			scanf("%d", &n2);
		}
		printf("Divis�o: %d\n", n1 / n2);
		break;	
		
		default:
			printf("op��o inv�lida!\nDigite outra op��o:");
	}
	return 0; 
}
