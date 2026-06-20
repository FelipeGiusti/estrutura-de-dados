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
    char palavra[100];
    char invertida[100];
    int tamanho, i, opcao;

    do{
        system("cls");
        printf("1 verificar se uma palavra e palindromo\n");
        printf("2 sair\n\n");
        printf("OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Palavra: ");
                scanf(" %99[^\n]", palavra);

                tamanho = strlen(palavra);

                for(i = 0; i < tamanho; i++){
                    pilha = push(pilha, palavra[i]);
                }

                for(i = 0; i < tamanho; i++){
                    pilha = pop(pilha, &invertida[i]);
                }
                invertida[tamanho] = '\0';

                if(strcmp(palavra, invertida) == 0){
                    printf("\n%s e palindromo!\n", palavra);
                }else{
                    printf("\n%s nao e palindromo.\n", palavra);
                }
                system("pause");
                break;
        }
    }while(opcao != 2);

    return 0;
}
