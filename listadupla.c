#include <stdio.h>
#include <stdlib.h>
#define MALLOC(x) ((x) malloc (sizeof(x)))

typedef struct lista Lista;

struct lista{

	int valor;
	Lista* ant;
	Lista* prox;

};

Lista* cria_lista(void){
	return NULL;
}

int lista_vazia(Lista* head){
	return head==NULL;
}

Lista* insere_inicio(Lista* head, int valor){

	Lista* novo;
	novo = MALLOC(Lista*);

	if(lista_vazia(head)){
		novo->ant = NULL;
		novo->prox = NULL;
		novo->valor = valor;
		head = novo;	
	}else{
		novo->ant = NULL;
		novo->valor = valor;
		novo->prox = head;

		head->ant = novo;
		head = novo;
	}

	return novo;
}

Lista* insere_final(Lista* head, int valor){

	Lista* novo;
	novo = MALLOC(Lista*);
	if(lista_vazia(head)){		//adiciona no inicio
		novo->ant = NULL;
		novo->prox = NULL;
		novo->valor = valor;
		head = novo;
	}else{				//adiciona no fim
		Lista* aux = head;	
		novo->prox = NULL;	
		novo->valor = valor;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		novo->ant = aux;
		aux->prox = novo;		
	}
	return head;
}

Lista* insere_ordenado(Lista* head, int valor){

	Lista* novo;
	novo = MALLOC(Lista*);

	if(lista_vazia(head)){  	//Se vazia, insiro no inicio
		novo->ant=NULL;
		novo->prox=NULL;
		novo->valor=valor;
		head = novo;
	}else{				//Se não vazia, percorro a lista até ver qual elemento é maior para achar o local de inserção
		Lista* aux = head;
		Lista* ant = NULL;
		while(aux!=NULL && valor>=aux->valor){
			ant = aux;
			aux = aux->prox;
		}
		if(aux==NULL){ 	//Insere no final
			novo->prox = NULL;	
			novo->valor = valor;
			novo->ant = ant;
			ant->prox = novo;
		}else{
			if(ant == NULL){ 	//Insere no começo
				novo->ant = NULL;
				novo->prox = aux;
				novo->valor = valor;
				head = novo;
			}else{			//Insere no meio
				novo->ant = ant;
				novo->prox = aux;
				ant->prox = novo;
				aux->ant = novo;
				novo->valor = valor;
			}
		}
		return head;
	}

}

void imprime_lista(Lista* head){
	
	if(head!=NULL){
		printf("Valor = %d\n", head->valor);
		imprime_lista(head->prox);
	}

}

void libera_lista(Lista* head){

	Lista* aux = head;
	while(aux!=NULL){
		Lista* aux2 = aux->prox;
		free(aux);
		aux = aux2;
	}
}

int busca_lista(Lista* head, int valor){

	Lista* aux = head;
	if(lista_vazia(head))
		return 0;
	while(aux!=NULL){
		if(aux->valor == valor) return 1;
		aux = aux->prox;
	}
	return 0;
}

Lista* retira_lista(Lista* head, int valor){

	Lista* ant = NULL;
	Lista* prox = head;
	if(lista_vazia(head))
		return head;
	else{
		while(prox->prox!=NULL && prox->valor != valor){
			ant = prox;
			prox = prox->prox;
		}
		if(prox->valor != valor){
			return head;
		}else{
			if(prox->prox == NULL && prox->ant != NULL){ //caso o numero seja o ultimo termo
				ant->prox = NULL;
				free(prox);
			}else if(prox->ant == NULL && prox->prox != NULL){ //caso o numero seja o primeiro termo
				Lista* aux = prox->prox;
				head = prox->prox;
				aux->ant = NULL;
				free(prox);
			}else if(prox->ant == NULL && prox->prox == NULL){ //caso o numero seja o único termo
				head = NULL;
				free(prox);
			}else{						//caso esteja no meio da lista
				Lista* aux = prox;
				ant->prox = prox->prox;
				prox = prox->prox;
				prox->ant = ant;
				free(aux);
			}
			
		}
	}
	return head;
}

int main(){

	Lista* list;
	list = cria_lista();
	if(lista_vazia(list))
		printf("lista vazia\n");
	list = insere_ordenado(list, 1);
	list = insere_ordenado(list, 3);
	list = insere_ordenado(list, 7);
	list = insere_ordenado(list, 2);
	list = insere_ordenado(list, 5);
	list = insere_ordenado(list, 4);

/*	list = insere_final(list, 1);
	list = insere_final(list, 2);
	list = insere_final(list, 3);
	list = insere_final(list, 4);
	list = insere_inicio(list, 1);
	list = insere_inicio(list, 2);
	list = insere_inicio(list, 3);
	list = insere_inicio(list, 4);
	imprime_lista(list);
	printf("\n");
	list = retira_lista(list, 1);
	list = retira_lista(list, 4);
*/
	imprime_lista(list);
	if(busca_lista(list, 4))
		printf("O numero 4 está na lista\n");
	libera_lista(list);
return 0;
}
