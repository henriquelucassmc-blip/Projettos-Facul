#include <stdio.h>
#include <math.h>

int main(){
	
	int i,numero;
	
	printf("Digite um que deseja ver a Tabuada: ");
	scanf("%d", &numero);
	
	for( i = 1; i <=10; i++)
	printf("%2d  x %3d = %3d   ",numero,i,numero*i);
	
	getchar();			
	return 0;
}
