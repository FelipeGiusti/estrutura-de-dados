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

int contarMaiores50(No *topo){
    int total = 0;
    while(topo != NULL){
        if(topo->valor > 50){
            total++;
        }
        topo = topo->proximo;
    }
    return total;
}

int main(){
    No *pilha = NULL;
    No *pares = NULL;
    No *impares = NULL;
    No *atual;
    int valor, i, repetido, opcao;

    srand((unsigned int) time(NULL));

    do{
        system("cls");
        printf("1 montar pilha original (15 aleatorios sem repetir)\n");
        printf("2 distribuir em pares e impares (esvazia a pilha original)\n");
        printf("3 listar pilha original\n");
        printf("4 listar pilha de pares\n");
        printf("5 listar pilha de impares\n");
        printf("6 contar elementos maiores que 50 na pilha original\n");
        printf("7 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                for(i = 0; i < 15; i++){
                    do{
                        valor = rand() % (100 - 10 + 1) + 10;
                        repetido = 0;
                        atual = pilha;
                        while(atual != NULL){
                            if(atual->valor == valor){
                                repetido = 1;
                            }
                            atual = atual->proximo;
                        }
                    }while(repetido == 1);

                    pilha = push(pilha, valor);
                }
                printf("\nPilha original montada.\n");
                system("pause");
                break;
            case 2:
                while(pilha != NULL){
                    pilha = pop(pilha, &valor);
                    if(valor % 2 == 0){
                        pares = push(pares, valor);
                    }else{
                        impares = push(impares, valor);
                    }
                }
                printf("\nPilhas de pares e impares montadas. Pilha original esvaziada.\n");
                system("pause");
                break;
            case 3:
                printf("\n");
                if(pilha == NULL){
                    printf("Pilha original vazia.\n");
                }else{
                    atual = pilha;
                    while(atual != NULL){
                        printf("%d ", atual->valor);
                        atual = atual->proximo;
                    }
                    printf("\n");
                }
                system("pause");
                break;
            case 4:
                printf("\n");
                if(pares == NULL){
                    printf("Pilha de pares vazia.\n");
                }else{
                    atual = pares;
                    while(atual != NULL){
                        printf("%d ", atual->valor);
                        atual = atual->proximo;
                    }
                    printf("\n");
                }
                system("pause");
                break;
            case 5:
                printf("\n");
                if(impares == NULL){
                    printf("Pilha de impares vazia.\n");
                }else{
                    atual = impares;
                    while(atual != NULL){
                        printf("%d ", atual->valor);
                        atual = atual->proximo;
                    }
                    printf("\n");
                }
                system("pause");
                break;
            case 6:
                printf("\nQuantidade de elementos maiores que 50: %d\n", contarMaiores50(pilha));
                system("pause");
                break;
        }
    }while(opcao != 7);

    while(pilha != NULL){
        pilha = pop(pilha, &valor);
    }
    while(pares != NULL){
        pares = pop(pares, &valor);
    }
    while(impares != NULL){
        impares = pop(impares, &valor);
    }

    return 0;
}
