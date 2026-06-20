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
    No *atual;
    int valor, i, repetido, opcao;

    srand((unsigned int) time(NULL));

    do{
        system("cls");
        printf("1 montar pilha (10 aleatorios sem repetir)\n");
        printf("2 listar pilha\n");
        printf("3 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                for(i = 0; i < 10; i++){
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
                printf("\nPilha montada.\n");
                system("pause");
                break;
            case 2:
                printf("\n");
                if(pilha == NULL){
                    printf("Pilha vazia.\n");
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
        }
    }while(opcao != 3);

    while(pilha != NULL){
        pilha = pop(pilha, &valor);
    }

    return 0;
}
