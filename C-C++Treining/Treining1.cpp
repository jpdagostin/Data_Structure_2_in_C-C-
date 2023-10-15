#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomes[50][50];  // Array para armazenar nomes
    int idades[50];      // Array para armazenar idades
    int quantidade = 0;

    printf("Digite a quantidade de nomes que você quer inserir: ");
    scanf("%d", &quantidade);

    // Coleta de nomes e idades
    for (int i = 0; i < quantidade; i++) {
        printf("Digite o nome %d: ", i + 1);
        scanf("%s", nomes[i]);

        printf("Digite a idade %d: ", i + 1);
        scanf("%d", &idades[i]);
    }

    // Mostrar todos os nomes e idades
    printf("\nNomes e Idades:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %s, Idade: %d\n", nomes[i], idades[i]);
    }

    return 0;
}

