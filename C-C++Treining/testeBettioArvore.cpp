#include <stdio.h>
#include <stdlib.h>
// Defini��o da estrutura de um n� da �rvore.
struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
};
// Fun��o para criar um novo n�.
struct Node* criarNovoNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}
// Fun��o para inserir um n� na �rvore de busca bin�ria.
struct Node* inserirNaBST(struct Node* raiz, int valor) {
    if (raiz == NULL) {
        // Se a �rvore estiver vazia, cria um novo n�.
        return criarNovoNo(valor);
    }
    if (valor < raiz->valor) {
        // Se o valor for menor que o valor do n� atual, insere � esquerda.
        raiz->esquerda = inserirNaBST(raiz->esquerda, valor);
    }
if (valor > raiz->valor) {
        // Se o valor for maior que o valor do n� atual, insere � direita.
        raiz->direita = inserirNaBST(raiz->direita, valor);
    }
 // Retorna a raiz da �rvore atualizada.
    return raiz;
}
 // Fun��o para percorrer a �rvore em ordem
void percorrerEmOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        percorrerEmOrdem(raiz->direita);
    }
}
void percorrerEmPreOrdem(struct Node* raiz) {
    if (raiz != NULL) {
    printf("%d ", raiz->valor);
        percorrerEmOrdem(raiz->esquerda);
        percorrerEmOrdem(raiz->direita);
    }
}
void percorrerEmProOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        percorrerEmOrdem(raiz->esquerda);
        percorrerEmOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

struct Node* buscarUmNo(struct Node* raiz, int valor) {
    if (raiz == NULL) {
        // Se a �rvore estiver vazia, printa null.
        printf("null");
    }
    if(raiz->valor == valor){
    printf("c%d ", raiz->valor);
    return raiz;
}
    if (valor < raiz->valor) {
        // Se o valor for menor que o valor do n� atual, insere � esquerda.
        //printf("b%d ", raiz->valor);
        raiz->esquerda = buscarUmNo(raiz->esquerda, valor);
       
    } else if (valor > raiz->valor) {
        // Se o valor for maior que o valor do n� atual, insere � direita.
        // printf("a%d ", raiz->valor);
        raiz->direita = buscarUmNo(raiz->direita, valor);
       
    }
 // Retorna a raiz da �rvore atualizada.
    return raiz;
}

struct Node* excluirUmNoFolha(struct Node* raizOld, struct Node* raiz, int valor){

int aux = 0;

//printf("1-(%x %d (%d)\n", raiz, raiz->valor, valor);

if (raiz == NULL) {
        // Se a �rvore estiver vazia, printa o valor anterior.
       printf("Elemento anterior: %d", raizOld->valor);
   }
    if(raiz->valor == valor){
    printf("Um valor encontrado: %d ", raiz->valor);
    if(raiz->esquerda == NULL && raiz->direita == NULL){
    aux = raizOld->valor;
    free(raiz);
    raiz = NULL;
    //printf("Elemento folha removido: %d !", valor);
    return raiz;
}
   return 0;
}
    if (valor < raiz->valor) {
        // Se o valor for menor que o valor do n� atual, insere � esquerda.
        //printf("b%d ", raiz->valor);
        raiz->esquerda = excluirUmNoFolha(raiz, raiz->esquerda, valor);
    }
if (valor > raiz->valor) {
        // Se o valor for maior que o valor do n� atual, insere � direita.
       // printf("a(%x)e(%d)d(%x)(%d)(%d)\n",raiz, raiz->esquerda->valor, raiz->direita, raiz->valor, valor);
        raiz->direita = excluirUmNoFolha(raiz, raiz->direita, valor);
    }
 // Retorna a raiz da �rvore atualizada.
    return raiz;
}
struct Node* excluirUmNoComUmaFolha(struct Node* raiz, struct Node* raizOld, int valor) {
    if (raiz == NULL) {
        // A �rvore est� vazia, n�o h� nada para excluir.
        return raiz;
    }

    // Caso base: se o valor a ser exclu�do � igual ao valor na raiz.
    if (valor == raiz->valor) {
        // Se o n� atual tem um filho � esquerda, exclua-o e substitua pelo filho.
        if (raiz->esquerda != NULL && raiz->direita == NULL) {
            struct Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        // Se o n� atual tem um filho � direita, exclua-o e substitua pelo filho.
        if (raiz->direita != NULL && raiz->esquerda == NULL) {
            struct Node* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        // Se o n� atual n�o tem filhos, simplesmente exclua-o.
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
    }

    // Caso recursivo: continue procurando o valor a ser exclu�do na sub�rvore esquerda e direita.
    if (valor < raiz->valor) {
        raiz->esquerda = excluirUmNoComUmaFolha(raiz->esquerda, raizOld, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = excluirUmNoComUmaFolha(raiz->direita,raizOld, valor);
    }

    return raiz;
}


struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->esquerda != NULL) {
        current = current->esquerda;
    }
    return current;
}

struct Node* excluirComDoisFilhos(struct Node* raiz, struct Node* raizOld, int valor) {
    if (raiz == NULL) {
        return raiz; // Retorna NULL se a �rvore estiver vazia ou o n� n�o for encontrado.
    }

    if (valor < raiz->valor) {
        // Se o valor for menor que o valor do n� atual, insere � esquerda.
        raiz->esquerda = excluirComDoisFilhos(raiz->esquerda, raizOld, valor);
    } else if (valor > raiz->valor) {
        // Se o valor for maior que o valor do n� atual, insere � direita.
        raiz->direita = excluirComDoisFilhos(raiz->direita, raizOld, valor);
    } else {
        // O n� com o valor a ser exclu�do foi encontrado.

        if (raiz->esquerda == NULL) {
            struct Node* temp = raiz->direita;
            free(raiz);
            return temp; // Retorna o filho direito para substituir o n�.
        } else if (raiz->direita == NULL) {
            struct Node* temp = raiz->esquerda;
            free(raiz);
            return temp; // Retorna o filho esquerdo para substituir o n�.
        }

        // Se o n� tiver dois filhos, encontre o menor n� na sub�rvore direita (sucessor in-order).
        struct Node* temp = findMinValueNode(raiz->direita);

        // Copie o valor do n� sucessor para o n� atual.
        raiz->valor = temp->valor;

        // Exclua o n� sucessor.
        raiz->direita = excluirComDoisFilhos(raiz->direita, raizOld, temp->valor);
    }

    return raiz;
}




int main() {
    struct Node* raiz = NULL;
    int opcao = 0;
    int valor = 70;
    int removerValor = 80;
    int removerValor2 = 70;
    int removerValor3 = 60;
     // Inserindo valores na �rvore de busca bin�ria.
    raiz = inserirNaBST(raiz, 50);
    raiz = inserirNaBST(raiz, 30);
    raiz = inserirNaBST(raiz, 20);
    raiz = inserirNaBST(raiz, 40);
    raiz = inserirNaBST(raiz, 70);
    raiz = inserirNaBST(raiz, 60);
    raiz = inserirNaBST(raiz, 80);
    raiz = inserirNaBST(raiz, 69);
     

    // Loop principal do menu
    while (1) {
    	printf("\n----------------------------------");
        printf("\nMenu:\n\n");							
        printf("1. Excluir um no folha\n");		
        printf("2. Excluir no com uma folha\n");	
        printf("3. Excluir no com duas folhas\n");	
        printf("4. Imprimir Arvore\n");				
        printf("5. Sair\n");
		printf("\n----------------------------------\n");							
        printf("Escolha uma opcao: ");			
        scanf("%d", &opcao);
        

        switch (opcao) {
        	case 1:
        		printf("Encontrei o valor a ser removido: ", excluirUmNoFolha(raiz, raiz, removerValor));
        		break;
            case 2:
                printf("Encontrei o valor a ser removido: ", excluirUmNoComUmaFolha(raiz, raiz, removerValor3));
                break;
            case 3:
                printf("Encontrei o valor a ser removido: ", excluirComDoisFilhos(raiz, raiz, removerValor2));
                break; 
            case 4:
                printf("Arvore em in-ordem: ");
    			percorrerEmOrdem(raiz);
				printf("\n\n");
				printf("Arvore em pre-ordem: ");
				percorrerEmPreOrdem(raiz);
				printf("\n\n"); 
				printf("Arvore em pro-ordem: ");
				percorrerEmProOrdem(raiz);
                break;
            case 5:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
