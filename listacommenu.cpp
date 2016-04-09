#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>

#define MALLOC(x) ((x) malloc (sizeof(x)))

typedef struct no No;

struct no{

	char* nome;
	int info;
	No* prox;
	No* ant;	

};

No* cria_lista(){
	return NULL;
}

int lista_vazia(No* head){
	return head==NULL;
}

No* inserir_ordenado(No* head, int info, char* nome){

	No* novo, *aux, *ant;
	novo = MALLOC(No*);
	novo->nome = (char*) malloc (sizeof(char*)*10);
	novo->info = info;
	novo->nome = nome;
	if(lista_vazia(head)){
		novo->prox = NULL;
		novo->ant = NULL;
		head = novo;
	}else{
		aux = head;
		ant = NULL;
		while(aux!=NULL && aux->info <= info){
			ant = aux;
			aux = aux->prox;
		}
		if(aux==NULL){
			novo->prox = NULL;
			novo->ant = ant;
			ant->prox = novo;			
		}else{
			if(ant == NULL){
				novo->ant = NULL;
				novo->prox = aux;
				aux->ant = novo;
				head = novo;
			}else{
				novo->ant = ant;
				novo->prox = aux;
				ant->prox = novo;
				aux->ant = novo;
			}
		}
	}
	return head;
}

void imprimir_crescente(No* head){
	if(head != NULL){
		printf("Matricula: %d Aluno: %s\n", head->info, head->nome);
		imprimir_crescente(head->prox);
	}		
}

void imprimir_decrescente(No* head){

	No* aux = head;
	while(aux->prox!=NULL)
		aux = aux->prox;
	while(aux!=NULL){
		printf("Matricula: %d Aluno: %s\n", aux->info, aux->nome);
		aux = aux->ant;
	}
}

int main(){

	No* lista;
	lista =  cria_lista();	
	int opcao, matricula;
	char *nome;
	do{
		printf("\n\n\n\n\nMENU\n");
		printf("1 - Inserir dados\n");
		printf("2 - Imprimir em ordem crescente\n");
		printf("3 - Imprimir em ordem decrescente\n");
		printf("4 - Sair\n");
		scanf("%d", &opcao);
		if(opcao == 1){
			printf("\nDigite sua matricula e seu nome: \n");
			nome = (char*) malloc (sizeof(char*)*10);
			scanf("%d", &matricula);
			fgets(nome, 100, stdin);
			lista = inserir_ordenado(lista, matricula, nome);
		}
		if(opcao == 2)
			imprimir_crescente(lista);
		if(opcao == 3)
			imprimir_decrescente(lista);
		if(opcao > 4 || opcao < 1)
			printf("\nOpção inválida!\n");
	}while(opcao!=4);	
return 0;
}
