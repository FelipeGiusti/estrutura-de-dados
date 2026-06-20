#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[30];
    int idade;
    struct No *proximo;
}No;

No *push(No *topo, char *nome, int idade){
    No *novo = (No *) malloc(sizeof(No));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->proximo = topo;
    return novo;
}

No *pop(No *topo, char *nome, int *idade){
    No *removido = topo;
    strcpy(nome, removido->nome);
    *idade = removido->idade;
    topo = removido->proximo;
    free(removido);
    return topo;
}

int main(){
    No *pilha = NULL;
    No *atual;
    char nome[30];
    int idade, opcao;

    do{
        system("cls");
        printf("1 empilhar\n");
        printf("2 desempilhar\n");
        printf("3 mostrar pilha\n");
        printf("4 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Nome: ");
                scanf(" %29[^\n]", nome);
                printf("Idade: ");
                scanf("%d", &idade);
                pilha = push(pilha, nome, idade);
                break;
            case 2:
                if(pilha == NULL){
                    printf("\nPilha vazia.\n");
                }else{
                    pilha = pop(pilha, nome, &idade);
                    printf("\nRemovido -> Nome: %s | Idade: %d\n", nome, idade);
                }
                system("pause");
                break;
            case 3:
                printf("\n");
                if(pilha == NULL){
                    printf("Pilha vazia.\n");
                }else{
                    atual = pilha;
                    printf("Topo ->\n");
                    while(atual != NULL){
                        printf("Nome: %s | Idade: %d\n", atual->nome, atual->idade);
                        atual = atual->proximo;
                    }
                }
                system("pause");
                break;
        }
    }while(opcao != 4);

    while(pilha != NULL){
        pilha = pop(pilha, nome, &idade);
    }

    return 0;
}
