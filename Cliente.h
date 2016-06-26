#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTE 0
#define OS 1
#define ATIVIDADE 2
#define EMPRESA 3

/*
	Responsável: Marcelo Augusto
	Objetivo: Ler string do tamanho TAMANHOAUX até a quebra de linha
	Parâmetro: String e tamanho maximo da string
	Retorno: 
*/
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

/*
	Responsável: Marcelo Augusto
	Objetivo: Comparar se um código é igual a um código de um cliente
	Parâmetro: codigo, Cliente
	Retorno: 1 para código igual, 0 para código diferente
*/

int comparaCodigo(int codigo, Cliente *cliente){
	return codigo == cliente->codigo;
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Imprimir informações de um Cliente
	Parâmetro: Cliente
	Retorno: 
*/

void imprimirCliente(Cliente* cliente){
	printf("Nome Cliente: %s\n", cliente->nome);
	printf("Codigo: %d\n", cliente->codigo);
	printf("Endereco: %s\n", cliente->endereco);
	printf("Bairro: %s\n", cliente->bairro);
	printf("CEP: %s\n", cliente->cep);
	printf("Cidade: %s\n", cliente->cidade);
	printf("Estado: %s\n", cliente->estado);
	printf("Telefone: %s\n", cliente->telefone);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Verificar se um codigo é repetido
	Parâmetro: Cabeca da arvore, Codigo
	Retorno: 1 para codigo repetido 0 para nao repetido
*/

int codigoERepetido(No* head, int codigo){
	if(head==NULL)
		return 0;
	if(head->tipoInformacao == CLIENTE && comparaCodigo(codigo, (Cliente*)head->informacao)){
		return 1;
	}
	codigoERepetido(head->prox, codigo);
}


/*
	Responsavel: Marcelo Augusto
	Objetivo: Verifica se um cliente tem um codigo, se tiver imprime os dados do cliente
	Parâmetro: Cabeca da arvore, Codigo
	Retorno: 
*/

void consultarClientePorCodigo(No* head, int codigo){

	if(head==NULL)
		return;
	if(head->tipoInformacao == CLIENTE && comparaCodigo(codigo, (Cliente*)head->informacao)){
		imprimirCliente(head->informacao);
	}

	consultarClientePorCodigo(head->prox, codigo);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Ler os dados de um Cliente
	Parâmetro: Cabeca da arvore, Cliente
	Retorno: 1 para leitura bem sucedida, 0 para leitura mal sucedida
*/

int leituraCliente(Cliente* cliente, No* head){

	alocaMemoriaCliente(cliente);

	printf("Digita o do codigo ai\n");
	scanf("%d", &cliente->codigo);

	if(codigoERepetido(head,cliente->codigo)){
		printf("Ja existe um cliente com este codigo!\nNao e possivel continuar este cadastro\n");
		return 0;
	}
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

	return 1;
}


/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para comparar os nomes dos Clientes, para ordenar por nome na hora da inserção
	Parâmetro: String nome, Cliente
	Retorno: Retorno comparacao entre as duas strings, 0 caso o nome dos dois clientes sejam iguais, < 0 caso o primeiro nome venha antes na ordem lexicográfica, > 0 caso contrário.
*/

int comparaNome(char* nome, Cliente* clienteAux){
	return strcmp(nome, clienteAux->nome);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para inserir um Cliente ordenado por nome na lista do nível de clientes.
	Parâmetro: Cabeça da árvore, Cliente a se inserir
	Retorno: Nova cabeça da árvore
*/

No* insercaoCliente(No* head, Cliente* cliente){

	No* novoCliente = (No*)malloc(sizeof(No));
	No *auxiliar = head->filho, *auxiliar2 = NULL;

	novoCliente->tipoInformacao = CLIENTE;
	novoCliente->informacao = cliente;
	novoCliente->filho = NULL;

	if(auxiliar==NULL){
		novoCliente->prox = NULL;
		head->filho = novoCliente;
	}else{

		while(auxiliar!=NULL && comparaNome(cliente->nome, (Cliente*)auxiliar->informacao)>0){
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

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para imprimir as informações da empresa.
	Parâmetro: Empresa
	Retorno: 
*/

void imprimirEmpresa(Empresa* empresa){
	printf("Nome Empresa: %s\n", empresa->nome);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Verifica se um cliente tem um nome, se tiver imprime os dados do cliente
	Parâmetro: Cabeca da arvore, Nome
	Retorno: 
*/

void consultarClientePorNome(No* head, char* nome){

	if(head==NULL)
		return;
	if(head->tipoInformacao == CLIENTE && comparaNome(nome, (Cliente*)head->informacao)==0){
		imprimirCliente(head->informacao);
	}

	consultarClientePorNome(head->prox, nome);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Verifica se um cliente tem um codigo, se tiver exclui o cliente
	Parâmetro: Cabeca da arvore, Codigo
	Retorno: Nova cabeça da árvore
*/

No* excluirCliente(No* head, int codigo){

	No *auxiliar = head, *auxiliarAnt = NULL;

	while(auxiliar!=NULL && !comparaCodigo(codigo, (Cliente*)auxiliar->informacao)){
		auxiliarAnt = auxiliar;
		auxiliar = auxiliar->prox;
	}
	if(auxiliar==NULL){
		printf("O codigo %d nao e referente a nenhum cliente!\n", codigo);

	}else if(auxiliarAnt == NULL){
		if(auxiliar->filho == NULL){
			head = auxiliar->prox;
			free(auxiliar);
		}else{
			printf("Nao foi possivel excluir o cliente do codigo %d. Pois o mesmo tem ordens de servicos ligadas a ele.\n", codigo);
		}

	}else if(comparaCodigo(codigo, (Cliente*)auxiliar->informacao)){
		if(auxiliar->filho == NULL){
			auxiliarAnt->prox = auxiliar->prox;
			free(auxiliar);
		}else{
			printf("Nao foi possivel excluir o cliente do codigo %d. Pois o mesmo tem ordens de servicos ligadas a ele.\n", codigo);	
		}
	}
	return head;
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para comparar o nome de dois clientes.
	Parâmetro: Dois Clientes.
	Retorno: 0 caso o nome dos dois clientes sejam iguais, < 0 caso o primeiro nome venha antes na ordem lexicográfica, > 0 caso contrário.
*/

int comparaNomeOrdenacao(Cliente* cliente1, Cliente* cliente2){
	return strcmp(cliente1->nome, cliente2->nome);
}


/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para ordenar a lista de Clientes por nome.
	Parâmetro: Cabeça da lista
	Retorno: 
*/

void ordenaPorNome(No* head){
	Cliente* clienteAux;
	No* aux = head;
	No* aux2;

	while(aux!=NULL){
		aux2 = aux;
		while(aux2!=NULL){
			if(comparaNomeOrdenacao(aux->informacao, aux2->informacao) > 0){
				clienteAux = aux->informacao;
				aux->informacao = aux2->informacao;
				aux2->informacao = clienteAux;
			}
			aux2 = aux2->prox;
		}
		aux = aux->prox;
	}

}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para comparar o codigo de dois clientes.
	Parâmetro: Dois Clientes.
	Retorno: 1 Caso o codigo do cliente1 for maior que o do cliente2, 0 caso contrario
*/

int comparaMaiorCodigo(Cliente *cliente1, Cliente *cliente2){
	return cliente1->codigo > cliente2->codigo;
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para ordenar a lista de Clientes por codigo.
	Parâmetro: Cabeça da lista
	Retorno: 
*/

void ordenaPorCodigo(No* head){

	Cliente* clienteAux;
	No* aux = head;
	No* aux2;

	while(aux!=NULL){
		aux2 = aux;
		while(aux2!=NULL){
			if(comparaMaiorCodigo(aux->informacao, aux2->informacao)){
				clienteAux = aux->informacao;
				aux->informacao = aux2->informacao;
				aux2->informacao = clienteAux;
			}
			aux2 = aux2->prox;
		}
		aux = aux->prox;
	}
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para imprimir todos os clientes
	Parâmetro: Cabeça da lista
	Retorno: 
*/

void impressao(No* head){

	if(head==NULL)
		return;

	if(head->tipoInformacao == CLIENTE)
		imprimirCliente(head->informacao);

	impressao(head->prox);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para imprimir uma Ordem de Serviço
	Parâmetro: Ordem de serviço
	Retorno: 
*/

void imprimirOS(OrdemServico* ordemServico){
	printf("Codigo cliente: %d\n", ordemServico->codigoCliente);
	printf("Codigo OS: %d\n", ordemServico->codigoOrdemServico);
	printf("Descricao: %s\n", ordemServico->descricaoSolicitacao);
	printf("Prioridade: %s\n", ordemServico->prioridade);
	printf("Data: %d/%d/%d\n", ordemServico->dataSolicitacao.dia, ordemServico->dataSolicitacao.mes, ordemServico->dataSolicitacao.ano);
	printf("Status: %c\n", ordemServico->status);
}

/*
	Responsavel: Augusto moreno
	Objetivo: Função para imprimir uma Atividade
	Parâmetro: Atividade
	Retorno: 
*/

void imprimirAtividade(Atividade* atividade){

	printf("Codigo Cliente: %d\n",atividade->codigoCliente);
	printf("Codigo da Ordem de Servico: %d\n", atividade->codigoOs);
	printf("Codigo Atividade: %d\n",atividade->codigoAtividade);
	printf("Quantidade de horas gastas: %d\n", atividade->qtdHorasGastas);

}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para imprimir todos os dados da árvore.
	Parâmetro: Cabeça da árvore
	Retorno: 
*/

void impressaoGeral(No* head){

	if(head==NULL)
		return;

	if(head->tipoInformacao == CLIENTE)
		imprimirCliente(head->informacao);
	else if(head->tipoInformacao == EMPRESA)
		imprimirEmpresa(head->informacao);
	else if(head->tipoInformacao == OS)
		imprimirOS(head->informacao);
	else if(head->tipoInformacao == ATIVIDADE)
		imprimirAtividade(head->informacao);

	impressaoGeral(head->filho);
	impressaoGeral(head->prox);
}
