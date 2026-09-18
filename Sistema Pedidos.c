#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_ITENS 20

// Vetores do card�pio
char nomes[9][30] = {
    "", "X-Burguer", "X-Salada", "X-Bacon", "Mc Lanche Triste", 
    "X-Tudo", "Refrigerante", "Suco", "Agua"
};

float precos[9] = {0, 18.0, 14.0, 16.0, 12.0, 22.0, 5.0, 6.0, 3.0};

// Vetores do pedido do cliente
int pedido_item[MAX_ITENS];
int pedido_qtd[MAX_ITENS];
int contador_pedido = 0;

void bemvindo(char *nome);
void mostrarMenu(void);
void fazerPedido(void);
void mostrarResumoPedido(void);

int main() {
    char nome[50];
    setlocale(LC_ALL, "Portuguese");
    bemvindo(nome);
    mostrarMenu();
    fazerPedido();
    mostrarResumoPedido();
    
    return 0;
}

void bemvindo(char *nome) {
    printf("Bem-vindo a Lanchonete!\n");
    printf("Qual o seu nome? ");
    scanf("%49s", nome);
    printf("\nOla, %s! Faca seu pedido:\n", nome);
}

void mostrarMenu(void) {
    printf("\n=== MENU DA LANCHONETE ===\n");
    for(int i = 1; i <= 8; i++) {
        printf("%d - %-12s R$ %.2f\n", i, nomes[i], precos[i]);
    }
    printf("0 - Finalizar pedido\n");
    printf("==========================\n");
}

void fazerPedido(void) {
    int opcao, quantidade;
    int resultado;
    
    printf("\nFaca seu pedido (digite 0 para finalizar):\n");
    
    while (1) {
        printf("\nDigite o n�mero do item: ");
        resultado = scanf("%d", &opcao);
        
        // Limpar buffer se entrada inv�lida
        if (resultado != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida! Digite um numero entre 0 e 8.\n");
            continue;
        }
        
        if (opcao == 0) break;
        
        if (opcao < 1 || opcao > 8) {
            printf("Opcao inv�lida!\n");
            continue;
        }
        
        // ==================== SWITCH CASE ====================
        switch(opcao) {
            case 1:
                printf("Voce escolheu X-Burguer!\n");
                break;
            case 2:
                printf("Voce escolheu X-Salada!\n");
                break;
            case 3:
                printf("Voce escolheu X-Bacon!\n");
                break;
            case 4:
                printf("Voce escolheu Mc Lanche Triste!\n");
                break;
            case 5:
                printf("Voce escolheu X-Tudo!\n");
                break;
            case 6:
                printf("Voce escolheu Refrigerante!\n");
                break;
            case 7:
                printf("Voce escolheu Suco!\n");
                break;
            case 8:
                printf("Voce escolheu Agua!\n");
                break;
        }
        // ====================================================
        
        printf("Quantidade: ");
        resultado = scanf("%d", &quantidade);z
        
        // Limpar buffer se entrada inv�lida
        if (resultado != 1) {
            while (getchar() != '\n');
            printf("Quantidade inv�lida! Digite um n�mero.\n");
            continue;
        }
        
        if (quantidade > 0 && contador_pedido < MAX_ITENS) {
            pedido_item[contador_pedido] = opcao;
            pedido_qtd[contador_pedido] = quantidade;
            contador_pedido++;
            
            printf("Adicionado: %d x %s!\n", quantidade, nomes[opcao]);
        } else if (contador_pedido >= MAX_ITENS) {
            printf("Pedido cheio!\n");
        }
    }
}

void mostrarResumoPedido(void) {
    float total = 0.0;
    
    printf("\n======================================\n");
    printf("          RESUMO DO PEDIDO\n");
    printf("======================================\n");
    
    for(int i = 0; i < contador_pedido; i++) {
        float subtotal = precos[pedido_item[i]] * pedido_qtd[i];
        printf("%d x %-12s  R$ %.2f\n", pedido_qtd[i], nomes[pedido_item[i]], subtotal);
        total += subtotal;
    }
    
    printf("--------------------------------------\n");
    printf("TOTAL A PAGAR:        R$ %.2f\n", total);
    printf("======================================\n");
    printf("Obrigado pela prefer�ncia!\n");
}