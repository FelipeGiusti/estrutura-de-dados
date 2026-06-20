#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char *nome;
    int idade;
    struct No *proximo;
}No;

No *enqueue(No *inicio, char *nome, int idade){
    No *novo = (No *) malloc(sizeof(No));
    No *atual;

    novo->nome = (char *) malloc(strlen(nome) + 1);
    strcpy(novo->nome, nome);
    novo->idade = idade;
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

No *dequeue(No *inicio){
    No *removido = inicio;
    inicio = removido->proximo;
    free(removido->nome);
    free(removido);
    return inicio;
}

int main(){
    No *fila = NULL;
    No *removido, *atual;
    char bufferNome[100];
    int idade, opcao;

    do{
        system("cls");
        printf("1 inserir\n");
        printf("2 remover\n");
        printf("3 imprimir\n");
        printf("4 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Nome: ");
                scanf(" %99[^\n]", bufferNome);
                printf("Idade: ");
                scanf("%d", &idade);
                fila = enqueue(fila, bufferNome, idade);
                break;
            case 2:
                if(fila == NULL){
                    printf("\nFila vazia.\n");
                }else{
                    removido = fila;
                    printf("\nRemovido -> Nome: %s | Idade: %d\n", removido->nome, removido->idade);
                    fila = dequeue(fila);
                }
                system("pause");
                break;
            case 3:
                printf("\n");
                if(fila == NULL){
                    printf("Fila vazia.\n");
                }else{
                    atual = fila;
                    while(atual != NULL){
                        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
                        atual = atual->proximo;
                    }
                }
                system("pause");
                break;
        }
    }while(opcao != 4);

    while(fila != NULL){
        fila = dequeue(fila);
    }

    return 0;
}
