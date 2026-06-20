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
    int valor, i, opcao;

    srand((unsigned int) time(NULL));

    do{
        system("cls");
        printf("1 montar fila (20 aleatorios entre 1 e 100)\n");
        printf("2 remover multiplos de 5\n");
        printf("3 listar fila\n");
        printf("4 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                for(i = 0; i < 20; i++){
                    valor = rand() % (100 - 1 + 1) + 1;
                    fila = enqueue(fila, valor);
                }
                printf("\nFila montada.\n");
                system("pause");
                break;
            case 2:
                atual = fila;
                anterior = NULL;
                while(atual != NULL){
                    if(atual->valor % 5 == 0){
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
                printf("\nMultiplos de 5 removidos.\n");
                system("pause");
                break;
            case 3:
                printf("\n");
                if(fila == NULL){
                    printf("Fila vazia.\n");
                }else{
                    atual = fila;
                    while(atual != NULL){
                        printf("%d ", atual->valor);
                        atual = atual->proximo;
                    }
                    printf("\n");
                }
                system("pause");
                break;
        }
    }while(opcao != 4);

    while(fila != NULL){
        fila = dequeue(fila, &valor);
    }

    return 0;
}
