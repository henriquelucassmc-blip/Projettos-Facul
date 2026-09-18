#include <stdio.h>
#include <math.h>


int main(){
	
	float n1,n2,soma,media;
	
	printf("Digite sua primeira nota: ");
	scanf("%f", &n1);
	
	printf("Digite agora sua segunda nota: ");
	scanf("%f", &n2);
	
	soma = n1+n2;
	
	media = soma/2;
	
	printf("Sua média final é: %.2f",media);
	
		
	return 0;
}
