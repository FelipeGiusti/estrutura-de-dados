/* Construir um programa em linguagem C que implemente uma lista DUPLAMENTE encadeada.
O programa deverá possuir as seguintes opções no menu:
- inserir no inicio
- inserir no fim
- inserir no meio
- apresentar a quantidade de elementos da lista (criar funcao)
- inserir 10 elementos sorteados //sorteio inclusive se é inicio, meio ou fim)
- apresentar lista
- remover elemento
- sair
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct apelido_no{
   int valor;
   struct apelido_no *ant;
   struct apelido_no *prox;
}no;

void inserir_inicio(no **lista, int num);
void inserir_fim();
void inserir_meio();
void imprimir(no *lista);
void remover_elemento();
void inserir_aleatorio();

int main(){
	no *lista=NULL;
  	int opcao,valor,anterior;
	do{
    system("cls");  
    printf("1 inserir no inicio\n");
    printf("2 inserir no final\n");
    printf("3 inserir no meio\n");
    printf("4 inserir 10 aleatorios\n");
    printf("5 remover elemento\n");
    printf("6 listar\n");
    printf("7 fim\n\n");
    printf("  OPCAO: ");
    fflush(stdin);
    scanf("%d",&opcao);
    switch (opcao) {
      case 1:
         printf("\nvalor a inserir: ");
         fflush(stdin);
         scanf("%d",&valor);
         inserir_inicio(&lista,valor);
         break;
      case 2:
         printf("\nvalor a inserir: ");
         fflush(stdin);
         scanf("%d",&valor);
         //inserir_fim(&lista,valor);
         break;
      case 3:
         printf("\nvalor a inserir: ");
         fflush(stdin);
         scanf("%d",&valor);
         printf("valor de referencia (inserir apos valor: )");
         fflush(stdin);
         scanf("%d",&anterior);
         
         //inserir_meio(&lista,valor,anterior);
         break; 
      case 4:
         //aleatorio
         //inserir_aleatorio(&lista);
         break;      
      case 5:
         printf("\nvalor a remover: ");
         fflush(stdin);
         scanf("%d",&valor);
         //remover_elemento(&lista, valor);
         break;   
      case 6:
         imprimir(lista);     
         system("pause");
         break;
     } 
  }
  while (opcao!=7); 
  system("pause");
  return 0;
}

void inserir_inicio(no **lista, int num){
	no *novo = malloc(sizeof(no));
	
	if(novo){
		novo->valor = num;
		novo->ant = NULL;
		if(!lista){
			novo->prox = NULL;
		} else {
			novo->prox = *lista;
		}
		*lista = novo;
	} else {
		printf("erro ao alocar");
	}
}

void imprimir(no *lista){
	if(!lista){	
		printf("lista vazia");
	} else {
		no *aux = lista;
		while(aux->prox){
			printf("%d \n",aux->valor);
			aux = aux->prox;
		}
	}
}
