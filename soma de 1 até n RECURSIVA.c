/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int soma (int n){
    if(n == 0){
        return 0;}
    else{
        return n + soma(n - 1);
}
}
int main(){
    
    int n;

    printf("Digite um número: ");
    scanf("%d", &n);
    
    printf("A soma de 1 até %d: %d", n, soma(n));
   
  
   return 0;
}






