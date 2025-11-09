#include <stdio.h>
#include <string.h>

#define NUM_TERRITORIOS 5
#define TAM_NOME 50
#define TAM_COR 20

typedef struct {
    char nome[TAM_NOME];
    char cor_exercito[TAM_COR];
    int num_tropas;
} Territorio;

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Territorio mapa[NUM_TERRITORIOS];
    int i;

    printf("🗺️ --- Cadastro Inicial dos %d Territórios (Nível Novato) ---\n\n", NUM_TERRITORIOS);

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("--- Território %d ---\n", i + 1);

        printf("Nome do Território: ");
        fgets(mapa[i].nome, TAM_NOME, stdin);
        
        if (mapa[i].nome[strlen(mapa[i].nome) - 1] == '\n') {
            mapa[i].nome[strlen(mapa[i].nome) - 1] = '\0';
        }

        printf("Cor do Exército Dominante: ");
        fgets(mapa[i].cor_exercito, TAM_COR, stdin);
        
        if (mapa[i].cor_exercito[strlen(mapa[i].cor_exercito) - 1] == '\n') {
            mapa[i].cor_exercito[strlen(mapa[i].cor_exercito) - 1] = '\0';
        }

        printf("Número de Tropas: ");
        if (scanf("%d", &mapa[i].num_tropas) != 1) {
            printf("⚠️ Entrada inválida para o número de tropas. Usando 0.\n");
            mapa[i].num_tropas = 0;
        }
        
        limpar_buffer();
        
        printf("\n");
    }

    printf("--- FIM DO CADASTRO ---\n\n");

    printf("📊 --- Estado Atual do Mapa (Resumo) ---\n");
    printf("+----------------------+----------------------+----------------+\n");
    printf("| Nome do Território   | Exército (Cor)       | N° de Tropas   |\n");
    printf("+----------------------+----------------------+----------------+\n");

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("| %-20s | %-20s | %-14d |\n", 
               mapa[i].nome, 
               mapa[i].cor_exercito, 
               mapa[i].num_tropas);
    }

    printf("+----------------------+----------------------+----------------+\n");

    return 0;
}