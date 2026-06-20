#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

No *push(No *topo, int valor){
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = topo;
    return novo;
}

No *pop(No *topo, int *valor){
    No *removido = topo;
    *valor = removido->valor;
    topo = removido->proximo;
    free(removido);
    return topo;
}

int main(){
    No *pilha = NULL;
    No *atual, *anterior, *temp;
    int opcao, valor, i, total;

    srand((unsigned int) time(NULL));

    do{
        system("cls");
        printf("1 push (inserir no topo)\n");
        printf("2 pop (remover do topo)\n");
        printf("3 inserir 20 aleatorios (10 a 125)\n");
        printf("4 remover elementos impares\n");
        printf("5 tamanho da pilha\n");
        printf("6 listar pilha\n");
        printf("7 fim\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                pilha = push(pilha, valor);
                break;
            case 2:
                if(pilha == NULL){
                    printf("\nPilha vazia.\n");
                }else{
                    pilha = pop(pilha, &valor);
                    printf("\nValor removido do topo: %d\n", valor);
                }
                system("pause");
                break;
            case 3:
                for(i = 0; i < 20; i++){
                    valor = rand() % (125 - 10 + 1) + 10;
                    pilha = push(pilha, valor);
                }
                printf("\n20 valores aleatorios inseridos.\n");
                system("pause");
                break;
            case 4:
                atual = pilha;
                anterior = NULL;
                while(atual != NULL){
                    if(atual->valor % 2 != 0){
                        temp = atual;
                        if(anterior == NULL){
                            pilha = atual->proximo;
                            atual = pilha;
                        }else{
                            anterior->proximo = atual->proximo;
                            atual = anterior->proximo;
                        }
                        free(temp);
                    }else{
                        anterior = atual;
                        atual = atual->proximo;
                    }
                }
                printf("\nElementos impares removidos.\n");
                system("pause");
                break;
            case 5:
                total = 0;
                atual = pilha;
                while(atual != NULL){
                    total++;
                    atual = atual->proximo;
                }
                printf("\nTamanho da pilha: %d\n", total);
                system("pause");
                break;
            case 6:
                printf("\n");
                if(pilha == NULL){
                    printf("Pilha vazia.\n");
                }else{
                    atual = pilha;
                    printf("Topo -> ");
                    while(atual != NULL){
                        printf("%d ", atual->valor);
                        atual = atual->proximo;
                    }
                    printf("<- Base\n");
                }
                system("pause");
                break;
        }
    }while(opcao != 7);

    while(pilha != NULL){
        pilha = pop(pilha, &valor);
    }

    return 0;
}
