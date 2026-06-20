#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char caractere;
    struct No *proximo;
}No;

No *push(No *topo, char caractere){
    No *novo = (No *) malloc(sizeof(No));
    novo->caractere = caractere;
    novo->proximo = topo;
    return novo;
}

No *pop(No *topo, char *caractere){
    No *removido = topo;
    *caractere = removido->caractere;
    topo = removido->proximo;
    free(removido);
    return topo;
}

int main(){
    No *pilha = NULL;
    char expressao[200];
    char c, topoChar;
    int i, balanceado, opcao;

    do{
        system("cls");
        printf("1 verificar balanceamento de uma expressao\n");
        printf("2 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Expressao: ");
                scanf(" %199[^\n]", expressao);

                balanceado = 1;

                for(i = 0; expressao[i] != '\0'; i++){
                    c = expressao[i];

                    if(c == '(' || c == '[' || c == '{'){
                        pilha = push(pilha, c);
                    }else if(c == ')' || c == ']' || c == '}'){
                        if(pilha == NULL){
                            balanceado = 0;
                        }else{
                            pilha = pop(pilha, &topoChar);
                            if(c == ')' && topoChar != '('){
                                balanceado = 0;
                            }
                            if(c == ']' && topoChar != '['){
                                balanceado = 0;
                            }
                            if(c == '}' && topoChar != '{'){
                                balanceado = 0;
                            }
                        }
                    }
                }

                if(pilha != NULL){
                    balanceado = 0;
                }

                while(pilha != NULL){
                    pilha = pop(pilha, &topoChar);
                }

                if(balanceado == 1){
                    printf("\nExpressao balanceada!\n");
                }else{
                    printf("\nExpressao NAO balanceada.\n");
                }
                system("pause");
                break;
        }
    }while(opcao != 2);

    return 0;
}
