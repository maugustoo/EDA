#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTE 0
#define OS 1
#define ATIVIDADE 2

void lerString(char *string, int TAMANHOMAX){
	int count = 0;
	char letraAux;

	for(count = 0 ; count < (TAMANHOMAX-1); ++count){
		letraAux = fgetc(stdin);
		if(letraAux == '\n' && count == 0){
			count--;
			continue;
		}
		if(letraAux == '\n')
			break;

		string[count] = letraAux;
	}
	string[count] = 0;
}


Cliente leituraCliente(Cliente cliente){
	
	cliente = alocaMemoriaCliente(cliente);

	printf("Digita a porra do codigo ai\n");
	scanf("%d", &cliente.codigo);
	printf("Digita a porra do nome ai\n");
	lerString(cliente.nome, 31);
	printf("Digita a porra do end ai\n");
	lerString(cliente.endereco, 31);
	printf("Digita a porra do bairro ai\n");
	lerString(cliente.bairro, 16);
	printf("Digita a porra do CEP ai\n");
	lerString(cliente.cep, 11);
	printf("Digita a porra da cidade ai\n");
	lerString(cliente.cidade, 21);
	printf("Digita a porra do estado ai\n");
	lerString(cliente.estado, 3);
	printf("Digita a porra do telefone ai\n");
	lerString(cliente.telefone, 11);

	return cliente;
}

int comparaString(Cliente* cliente, Cliente* clienteAux){
	return strcmp(cliente->nome, clienteAux->nome);
}

void insercaoCliente(No* head, Cliente* cliente){

	No* novoCliente =  (No*)malloc(sizeof(No));
	No *auxiliar = head->filho, *auxiliar2 = NULL;
	
	novoCliente->tipoInformacao  = CLIENTE;
	novoCliente->informacao = cliente;

	while(auxiliar!=NULL && comparaString(cliente, (Cliente*)auxiliar->informacao) > 0 ){
		auxiliar = auxiliar->prox;
	}

	if(auxiliar==NULL){
		auxiliar2->prox = novoCliente;
		novoCliente->prox = NULL;
	}else if(auxiliar2 == NULL){
		novoCliente->prox = auxiliar;
		head = novoCliente;
	}else{
		novoCliente->prox = auxiliar;
		auxiliar2->prox = novoCliente;
	}
}
