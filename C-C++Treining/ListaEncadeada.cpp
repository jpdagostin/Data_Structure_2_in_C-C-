#include <stdio.h>
#include <stdlib.h>

struct JOGADORES {
    char nome[50];
    int idade;
    char posicao[50];
    int numCamisa;
    char clube[50];
    struct JOGADORES *proximoJog;
};

int main() {
	
	struct JOGADORES *jogadoresTOPO = NULL;
    struct JOGADORES *aux = NULL;
    
    int quantidade;

    printf("Digite quantas alocações para formar a lista encadeada que você deseja:");
    scanf("%d", &quantidade);
    printf("\n")


    for (int i = 0; i < quantidade; i++) {
        jogadoresTOPO = (struct JOGADORES *)malloc(sizeof(struct JOGADORES));

        printf("Digite o nome do jogador:");
        scanf("%s", jogadoresTOPO->nome);

        printf("Digite a idade do jogador:");
        scanf("%d", &jogadoresTOPO->idade);

        printf("Digite a posicao do jogador:");
        scanf("%s", jogadoresTOPO->posicao);

        printf("Digite o numero da camisa do jogador:");
        scanf("%d", &jogadoresTOPO->numCamisa);

        printf("Digite o clube do jogador:");
        scanf("%s", jogadoresTOPO->clube);
        
        printf("\n")

        jogadoresTOPO->proximoJog = aux;
        aux = jogadoresTOPO;
    }
    
     // Mostrar os elementos da lista encadeada
    struct JOGADORES *atual = jogadoresTOPO;
    while (atual != NULL) {
        printf("\nNome: %s\n", atual->nome);
        printf("Idade: %d\n", atual->idade);
        printf("Posicao: %s\n", atual->posicao);
        printf("Número da Camisa: %d\n", atual->numCamisa);
        printf("Clube: %s\n", atual->clube);

        atual = atual->proximoJog; // Avança para o próximo nó
    }

    // Liberar a memória alocada para a lista encadeada
    atual = jogadoresTOPO;
    while (atual != NULL) {
        struct JOGADORES *prox = atual->proximoJog;
        free(atual);
        atual = prox;
    }

    return 0;
}


