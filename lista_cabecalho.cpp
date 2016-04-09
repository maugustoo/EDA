#include <bits/stdc++.h>
#define MALLOC(X) ((X)malloc(sizeof (X)))

using namespace std;

typedef struct no No;
typedef struct cab Cab;

Cab* cabec = MALLOC(Cab*);

struct no{
	int info;
	No* ant;
	No* prox;	
};

struct cab{
	No* com;
	No* fim;
	int qtd;	
};

No* cria_lista(){
	return NULL;
}

int lista_vazia(No* head){
	return head==NULL;
}

No* insere_ordenado(int info, No* head){
	No* novo = MALLOC(No*);
	novo->info = info;
	cabec->qtd++;
	if(lista_vazia(head)){
		cabec->com = novo;
		cabec->fim = novo;
		novo->prox = NULL;
		novo->ant = NULL;
		head = novo;
	}else{
		No* aux = head;
		No* ant = NULL;
		while(aux!=NULL && aux->info < info){
			ant = aux;
			aux = aux->prox;
		}if(ant == NULL){
			cabec->com = novo;
			novo->ant = NULL;
			novo->prox = aux;
			aux->ant = novo;
			head = novo;
		}else{
			if(aux == NULL){
				cabec->fim = novo;
				novo->prox = NULL;
				novo->ant = ant;
				ant->prox = novo;
			}else{
				ant->prox = novo;
				novo->ant = ant;
				aux->ant = novo;
				novo->prox = aux;
			}
		}
	}
	return head;
}

void imprime_lista(No* head){

	No* aux = cabec->fim;

	while(aux!=NULL){
		printf("info: %d\n", aux->info);
		aux = aux->ant;
	}
}

int main(){

	No* lista = cria_lista();
	if(lista_vazia(lista))
		printf("Ta vazia\n");
	lista = insere_ordenado(2, lista);
	lista = insere_ordenado(4, lista);
	lista = insere_ordenado(3, lista);
	lista = insere_ordenado(6, lista);
	lista = insere_ordenado(1, lista);
	lista = insere_ordenado(-11, lista);
	imprime_lista(lista);
	cout<<cabec->qtd<<" com:"<<cabec->com->info<<" fim: "<<cabec->fim->info<<endl;

return 0;
}
