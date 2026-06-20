#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PessoaLista{
    char nome[30];
    int retirou;
    struct PessoaLista *proximo;
}PessoaLista;

typedef struct PessoaFila{
    char nome[30];
    struct PessoaFila *proximo;
}PessoaFila;

typedef struct Pizza{
    char sabor[30];
    struct Pizza *proximo;
}Pizza;

// LISTA: insere um novo sorteado no final, com retirou = 0 (ainda nao retirou)
PessoaLista *inserirLista(PessoaLista *lista, char *nome){
    PessoaLista *novo = (PessoaLista *) malloc(sizeof(PessoaLista));
    PessoaLista *atual;

    strcpy(novo->nome, nome);
    novo->retirou = 0;
    novo->proximo = NULL;

    if(lista == NULL){
        return novo;
    }

    atual = lista;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;

    return lista;
}

// LISTA: procura o sorteado pelo nome e atualiza o status para retirado
void marcarRetirada(PessoaLista *lista, char *nome){
    while(lista != NULL){
        if(strcmp(lista->nome, nome) == 0){
            lista->retirou = 1;
            return;
        }
        lista = lista->proximo;
    }
}

// FILA: enfileira uma pessoa que chegou para aguardar atendimento (insere no fim)
PessoaFila *enqueueFila(PessoaFila *fila, char *nome){
    PessoaFila *novo = (PessoaFila *) malloc(sizeof(PessoaFila));
    PessoaFila *atual;

    strcpy(novo->nome, nome);
    novo->proximo = NULL;

    if(fila == NULL){
        return novo;
    }

    atual = fila;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;

    return fila;
}

// FILA: desenfileira a pessoa do inicio (proxima a ser atendida)
PessoaFila *dequeueFila(PessoaFila *fila, char *nome){
    PessoaFila *removido = fila;
    strcpy(nome, removido->nome);
    fila = removido->proximo;
    free(removido);
    return fila;
}

// PILHA: empilha uma pizza pronta no topo
Pizza *pushPilha(Pizza *pilha, char *sabor){
    Pizza *novo = (Pizza *) malloc(sizeof(Pizza));
    strcpy(novo->sabor, sabor);
    novo->proximo = pilha;
    return novo;
}

// PILHA: desempilha a pizza do topo (a ultima que ficou pronta)
Pizza *popPilha(Pizza *pilha, char *sabor){
    Pizza *removido = pilha;
    strcpy(sabor, removido->sabor);
    pilha = removido->proximo;
    free(removido);
    return pilha;
}

int main(){
    PessoaLista *lista = NULL;
    PessoaLista *atualLista;
    PessoaFila *fila = NULL;
    PessoaFila *atualFila;
    Pizza *pilha = NULL;
    Pizza *atualPilha;
    char nome[30];
    char sabor[30];
    int opcao;

    do{
        system("cls");
        printf("1 inserir sorteado na lista\n");
        printf("2 listar sorteados (lista)\n");
        printf("3 inserir pessoa na fila de atendimento\n");
        printf("4 listar fila de atendimento\n");
        printf("5 inserir pizza na pilha\n");
        printf("6 listar pilha de pizzas\n");
        printf("7 realizar entrega\n");
        printf("8 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            // cadastra um sorteado na lista
            case 1:
                printf("Nome do sorteado: ");
                scanf(" %29[^\n]", nome);
                lista = inserirLista(lista, nome);
                break;
            // mostra a lista de sorteados com o status de cada um
            case 2:
                printf("\n");
                if(lista == NULL){
                    printf("Lista vazia.\n");
                }else{
                    atualLista = lista;
                    while(atualLista != NULL){
                        if(atualLista->retirou == 1){
                            printf("Nome: %s | Status: Pizza Retirada\n", atualLista->nome);
                        }else{
                            printf("Nome: %s | Status: Aguardando\n", atualLista->nome);
                        }
                        atualLista = atualLista->proximo;
                    }
                }
                system("pause");
                break;
            // enfileira uma pessoa que chegou na pizzaria
            case 3:
                printf("Nome: ");
                scanf(" %29[^\n]", nome);
                fila = enqueueFila(fila, nome);
                break;
            // mostra quem esta na fila de atendimento
            case 4:
                printf("\n");
                if(fila == NULL){
                    printf("Fila vazia.\n");
                }else{
                    atualFila = fila;
                    printf("Inicio -> ");
                    while(atualFila != NULL){
                        printf("%s ", atualFila->nome);
                        atualFila = atualFila->proximo;
                    }
                    printf("<- Fim\n");
                }
                system("pause");
                break;
            // empilha uma pizza que acabou de ficar pronta
            case 5:
                printf("Sabor da pizza: ");
                scanf(" %29[^\n]", sabor);
                pilha = pushPilha(pilha, sabor);
                break;
            // mostra as pizzas prontas na pilha
            case 6:
                printf("\n");
                if(pilha == NULL){
                    printf("Pilha vazia.\n");
                }else{
                    atualPilha = pilha;
                    printf("Topo -> ");
                    while(atualPilha != NULL){
                        printf("%s ", atualPilha->sabor);
                        atualPilha = atualPilha->proximo;
                    }
                    printf("<- Base\n");
                }
                system("pause");
                break;
            // entrega: atende quem esta na frente da fila e retira a pizza do topo da pilha,
            // depois marca essa pessoa como "Pizza Retirada" na lista
            case 7:
                if(fila == NULL){
                    printf("\nFila vazia, nao ha ninguem para atender.\n");
                }else if(pilha == NULL){
                    printf("\nPilha vazia, nao ha pizza pronta.\n");
                }else{
                    fila = dequeueFila(fila, nome);
                    pilha = popPilha(pilha, sabor);
                    marcarRetirada(lista, nome);
                    printf("\n%s foi atendido e retirou a pizza de %s.\n", nome, sabor);
                }
                system("pause");
                break;
        }
    }while(opcao != 8);

    // libera a memoria das tres estruturas antes de encerrar
    while(lista != NULL){
        atualLista = lista;
        lista = lista->proximo;
        free(atualLista);
    }
    while(fila != NULL){
        fila = dequeueFila(fila, nome);
    }
    while(pilha != NULL){
        pilha = popPilha(pilha, sabor);
    }

    return 0;
}
