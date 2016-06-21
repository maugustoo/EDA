#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTE 0
#define OS 1
#define ATIVIDADE 2

//Função para ler string do tamanho TAMANHOAUX até a quebra de linha
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

//Função para ler os dados do Cliente
void leituraCliente(Cliente* cliente){

	alocaMemoriaCliente(cliente);

	printf("Digita o do codigo ai\n");
	scanf("%d", &cliente->codigo);
	printf("Digita o nome ai\n");
	lerString(cliente->nome, 31);
	printf("Digita o end ai\n");
	lerString(cliente->endereco, 31);
	printf("Digita o bairro ai\n");
	lerString(cliente->bairro, 16);
	printf("Digita o CEP ai\n");
	lerString(cliente->cep, 11);
	printf("Digita a cidade ai\n");
	lerString(cliente->cidade, 21);
	printf("Digita o estado ai\n");
	lerString(cliente->estado, 3);
	printf("Digita o telefone ai\n");
	lerString(cliente->telefone, 11);

}

//Função para comparar os nomes dos Clientes, para ordenar por nome na hora da inserção
int comparaNome(Cliente* cliente, Cliente* clienteAux){
	return strcmp(cliente->nome, clienteAux->nome);
}

//Função para inserir um cliente na lista
No* insercaoCliente(No* head, Cliente* cliente){

	No* novoCliente = (No*)malloc(sizeof(No));
	No *auxiliar = head->filho, *auxiliar2 = NULL;

	novoCliente->tipoInformacao = CLIENTE;
	novoCliente->informacao = cliente;
	novoCliente->filho = NULL;

	if(auxiliar==NULL){
		printf("aqui\n");
		novoCliente->prox = NULL;
		head->filho = novoCliente;
	}else{

		while(auxiliar!=NULL && comparaNome(cliente, (Cliente*)auxiliar->informacao)>0){
			auxiliar2 = auxiliar;
			auxiliar = auxiliar->prox;
		}

		if(auxiliar==NULL){
			auxiliar2->prox = novoCliente;
			novoCliente->prox = NULL;
		}else if(auxiliar2 == NULL){
			novoCliente->prox = auxiliar;
			head->filho = novoCliente;
		}else{
			novoCliente->prox = auxiliar;
			auxiliar2->prox = novoCliente;
		}
	}
	return head;
}

void imprimirCliente(Cliente* cliente){
	printf("Nome Cliente: %s\n", cliente->nome);
}

void imprimirEmpresa(Empresa* empresa){
	printf("Nome Empresa: %s\n", empresa->nome);
}

void impressao(No* head){


	if(head==NULL)
		return;

	if(head->tipoInformacao == CLIENTE)
		imprimirCliente(head->informacao);
	else
		imprimirEmpresa(head->informacao);

	impressao(head->prox);
	impressao(head->filho);
}
