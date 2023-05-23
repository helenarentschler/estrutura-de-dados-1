#include <stdio.h>
#include <stdlib.h>

typedef struct Cabeca Cabeca;
typedef struct No No; 

struct Cabeca {

	No* inicio;
	int qnt;
};

struct No {

	int chave;
	No* prox;
};

int vazia(Cabeca* cabeca);
Cabeca* criaCabeca();
void empilha(Cabeca* cabeca, int k);
void desempilha(Cabeca* cabeca);
void imprime(No* aux);
int topo(Cabeca* cabeca);
void desempilhaTodos(Cabeca* cabeca);

int main() {

	Cabeca* pilha = criaCabeca();

	empilha(pilha, 1);
	empilha(pilha, 2);
	empilha(pilha, 3);

	printf("Topo: %d\n", topo(pilha));

	imprime(pilha->inicio);

	desempilha(pilha);

	imprime(pilha->inicio);

	desempilhaTodos(pilha);

	imprime(pilha->inicio);

	return 0;
}

int vazia(Cabeca* cabeca) {

	if(!cabeca->inicio) {

		return 1;

	} else {

		return 0;
	}
}

Cabeca* criaCabeca() {

	Cabeca* cabeca = (Cabeca*) malloc(sizeof(Cabeca));

	if(cabeca) {

		cabeca->inicio = NULL;
		cabeca->qnt = 0;

	} else {printf("Não foi possível alocar memória.\n");}

	return cabeca;
}

void empilha(Cabeca* cabeca, int k) {

	No* novo = (No*) malloc(sizeof(No));

	if(novo) {

		novo->chave = k;
		novo->prox = cabeca->inicio;
		cabeca->inicio = novo;
		(cabeca->qnt)++;

	} else {printf("Não foi possível alocar memória.\n");}
}

void desempilha(Cabeca* cabeca) {

	if(vazia(cabeca) == 0) {

		No* aux = cabeca->inicio;
		cabeca->inicio = cabeca->inicio->prox;
		free(aux);
		(cabeca->qnt)--;

	} else {printf("Pilha vazia\n");}
}

int topo(Cabeca* cabeca) {

	if (vazia(cabeca) == 1) {
		
		return -1;
	
	} else {
	
		return cabeca->inicio->chave;
	}
}

void imprime(No* aux) {

	if(aux) {

		while(aux != NULL) {

			printf("%d\n", aux->chave);
			aux = aux->prox;
		}

	} else {printf("Pilha vazia\n");}
}

void desempilhaTodos(Cabeca* cabeca) {

	if(vazia(cabeca) == 0) {

		while(vazia(cabeca) != 1) {

			desempilha(cabeca);
		}

	} else {printf("Pilha vazia\n");}
}