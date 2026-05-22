#include <stdlib.h>
#include <stdio.h>

void enqueue(int item);
void dequeue();
void imprimir();
int entrada_dados();
void redistribuir();
void imprimirRedistribuicao();

typedef struct apelido_no{
	int dado;
	struct apelido_no *proximo;
}no;

no *frente = NULL;
no *fim = NULL;

no *frente2 = NULL;
no *fim2 = NULL;

no *frente3 = NULL;
no *fim3 = NULL;

int main(){
	int n, opcao;
	do {
		system("cls");
		printf("\n\nMenu\n1. Enfileirar\n");
		printf("2. Desenfileirar\n3. Imprimir\n4. Redistribuir\n5. Imprimir redistribuicao \n6. Sair");
		printf("\nEscolha uma opcao (0-4): ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				n = entrada_dados();
				enqueue(n);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				imprimir();
				break;
			case 4:
				redistribuir();
				break;
			case 5:
				imprimirRedistribuicao();
				break;
		}
	} while (opcao != 6);
	system("pause");
	return 0;
}

void enqueue(int item){
	printf("\nENFILEIRANDO...\n");
	no *novo = malloc(sizeof(no));
	//verificar disponibilidade de memória
	if(novo){
		novo->dado = item;
		novo->proximo = NULL;
		if(fim == NULL){
			frente = novo;
			fim = novo;
		} else {
			fim->proximo = novo;
			fim = novo;
		}
	}
	printf("\nValor %d enfileirado\n", novo->dado);
	system("pause");
}

void dequeue(){
	printf("\nDESENFILEIRANDO...\n");
	if(frente == NULL){
		printf("A fila está vazia\n");
	} else {
		no *temp = frente;
		frente = frente->proximo;
		if(frente == NULL){
			fim = NULL;
		}
		printf("\n%d desenfileirado!\n", temp->dado);
		free(temp);
	}
	system("pause");
}

void imprimir(){
	no *temp = frente;
	printf("\nIMPRIMINDO FILA...\n");
	while(temp != NULL){
		printf("%d \n", temp->dado);
		temp = temp->proximo;
	}
	system("pause");
}

int entrada_dados(){
	int valor;
	printf("\nEntre com o valor a enfileirar: ");
	scanf("%d",&valor);
	return valor;
}

void redistribuir(){
	int i = 1;
	
	no *novo = malloc(sizeof(no));
	no *temp = frente;
	
	if(novo){
		while(temp != NULL){
			if(i%2 == 0){
				
				if(fim2 == NULL){
					frente2 = temp;
					fim2 = temp;
				} else {
					fim2->proximo = temp;
					fim2 = temp;
				}
				i++;
			} else {
				
				if(fim3 == NULL){
					frente3 = temp;
					fim3 = temp;
				} else {
					fim3->proximo = temp;
					fim3 = temp;
				}
				i++;
			}
		temp = temp->proximo;
		}	
	}
	system("pause");
}

void imprimirRedistribuicao(){
	no *temp2 = frente2;
	printf("\nIMPRIMINDO FILA 2...\n");
	while(temp2 != NULL){
		printf("%d \n", temp2->dado);
		temp2 = temp2->proximo;
	}
	
	no *temp3 = frente3;
	printf("\nIMPRIMINDO FILA 3...\n");
	while(temp3 != NULL){
		printf("%d \n", temp3->dado);
		temp3 = temp3->proximo;
	}
	
	system("pause");
}
