#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[50];
    int idade;
    struct No *proximo;
}No;

No *enqueue(No *inicio, char *nome, int idade){
    No *novo = (No *) malloc(sizeof(No));
    No *atual;

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

No *dequeue(No *inicio, char *nome, int *idade){
    No *removido = inicio;

    strcpy(nome, removido->nome);
    *idade = removido->idade;

    inicio = removido->proximo;
    free(removido);

    return inicio;
}

int main(){
    No *fila1 = NULL;
    No *fila2 = NULL;
    No *fila3 = NULL;
    No *atual;
    char nome[50];
    int idade, opcao, total1, total2, total3;

    do{
        system("cls");
        printf("1 inserir pessoa na fila1\n");
        printf("2 montar fila2 (ate 30) e fila3 (acima de 30)\n");
        printf("3 listar fila1\n");
        printf("4 listar fila2\n");
        printf("5 listar fila3\n");
        printf("6 tamanho das filas\n");
        printf("7 fim\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Nome: ");
                scanf(" %49[^\n]", nome);
                printf("Idade: ");
                scanf("%d", &idade);
                fila1 = enqueue(fila1, nome, idade);
                break;
            case 2:
                while(fila1 != NULL){
                    fila1 = dequeue(fila1, nome, &idade);
                    if(idade <= 30){
                        fila2 = enqueue(fila2, nome, idade);
                    }else{
                        fila3 = enqueue(fila3, nome, idade);
                    }
                }
                printf("\nFILA2 e FILA3 montadas. FILA1 esvaziada.\n");
                system("pause");
                break;
            case 3:
                printf("\n");
                if(fila1 == NULL){
                    printf("FILA1 vazia.\n");
                }else{
                    atual = fila1;
                    while(atual != NULL){
                        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
                        atual = atual->proximo;
                    }
                }
                system("pause");
                break;
            case 4:
                printf("\n");
                if(fila2 == NULL){
                    printf("FILA2 vazia.\n");
                }else{
                    atual = fila2;
                    while(atual != NULL){
                        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
                        atual = atual->proximo;
                    }
                }
                system("pause");
                break;
            case 5:
                printf("\n");
                if(fila3 == NULL){
                    printf("FILA3 vazia.\n");
                }else{
                    atual = fila3;
                    while(atual != NULL){
                        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
                        atual = atual->proximo;
                    }
                }
                system("pause");
                break;
            case 6:
                total1 = 0;
                atual = fila1;
                while(atual != NULL){
                    total1++;
                    atual = atual->proximo;
                }

                total2 = 0;
                atual = fila2;
                while(atual != NULL){
                    total2++;
                    atual = atual->proximo;
                }

                total3 = 0;
                atual = fila3;
                while(atual != NULL){
                    total3++;
                    atual = atual->proximo;
                }

                printf("\nFILA1: %d | FILA2: %d | FILA3: %d\n", total1, total2, total3);
                system("pause");
                break;
        }
    }while(opcao != 7);

    while(fila1 != NULL){
        fila1 = dequeue(fila1, nome, &idade);
    }
    while(fila2 != NULL){
        fila2 = dequeue(fila2, nome, &idade);
    }
    while(fila3 != NULL){
        fila3 = dequeue(fila3, nome, &idade);
    }

    return 0;
}
