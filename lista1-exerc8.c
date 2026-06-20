#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

No *enqueue(No *inicio, int valor){
    No *novo = (No *) malloc(sizeof(No));
    No *atual;

    novo->valor = valor;
    novo->proximo = NULL;

    if(inicio == NULL){
        return novo;
    }

    atual = inicio;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;

    return inicio;
}

No *dequeue(No *inicio, int *valor){
    No *removido = inicio;
    *valor = removido->valor;
    inicio = removido->proximo;
    free(removido);
    return inicio;
}

int main(){
    No *fila = NULL;
    No *atual, *anterior, *temp;
    int opcao, valor, i, total;

    srand((unsigned int) time(NULL));

    do{
        system("cls");
        printf("1 enqueue (inserir no fim)\n");
        printf("2 dequeue (remover do inicio)\n");
        printf("3 inserir 20 aleatorios (10 a 125)\n");
        printf("4 remover elementos impares\n");
        printf("5 tamanho da fila\n");
        printf("6 listar fila\n");
        printf("7 fim\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Valor: ");
                scanf("%d", &valor);
                fila = enqueue(fila, valor);
                break;
            case 2:
                if(fila == NULL){
                    printf("\nFila vazia.\n");
                }else{
                    fila = dequeue(fila, &valor);
                    printf("\nValor removido do inicio: %d\n", valor);
                }
                system("pause");
                break;
            case 3:
                for(i = 0; i < 20; i++){
                    valor = rand() % (125 - 10 + 1) + 10;
                    fila = enqueue(fila, valor);
                }
                printf("\n20 valores aleatorios inseridos.\n");
                system("pause");
                break;
            case 4:
                atual = fila;
                anterior = NULL;
                while(atual != NULL){
                    if(atual->valor % 2 != 0){
                        temp = atual;
                        if(anterior == NULL){
                            fila = atual->proximo;
                            atual = fila;
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
                atual = fila;
                while(atual != NULL){
                    total++;
                    atual = atual->proximo;
                }
                printf("\nTamanho da fila: %d\n", total);
                system("pause");
                break;
            case 6:
                printf("\n");
                if(fila == NULL){
                    printf("Fila vazia.\n");
                }else{
                    atual = fila;
                    printf("Inicio -> ");
                    while(atual != NULL){
                        printf("%d ", atual->valor);
                        atual = atual->proximo;
                    }
                    printf("<- Fim\n");
                }
                system("pause");
                break;
        }
    }while(opcao != 7);

    while(fila != NULL){
        fila = dequeue(fila, &valor);
    }

    return 0;
}
