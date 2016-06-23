#include <stdio.h>
#include <stdlib.h>

typedef struct servicos Servicos;
typedef struct cliente Cliente;
typedef struct ordemServico OrdemServico;
typedef struct data Data;
typedef struct no No;
typedef struct cabec Cabec;
typedef struct empresa Empresa;
typedef struct atividade Atividade;
typedef struct descricaoAtividade DescricaoAtividade;

/*
	Responsavel: Augusto Moreno
*/

struct atividade{
	int codigoCliente;
	int codigoOs;
	int codigoAtividade;
};

/*
	Responsavel: Augusto Moreno
*/

struct descricaoAtividade{
	char* descricao;
	float valorHora;
};

/*
	Responsavel: Augusto Moreno
*/

void alocaMemoriaDescricaoAtividade(DescricaoAtividade* descricaoAtividade){
	
	descricaoAtividade->descricao = (char*) malloc(sizeof(char)*30);

}

struct empresa{
	char* nome;
};
/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para alocar memória para as strings da Empresa
	Parâmetro: Empresa
	Retorno: 
*/

void alocaMemoriaEmpresa(Empresa* empresa){
	empresa->nome = (char*) malloc(sizeof(char)*30);
}

struct servicos{
	int codigo;
	char* descricao;
	float valorPorHora;
};

struct cliente{
	int codigo;
	char* nome;
	char* endereco;
	char* bairro;
	char* cep;
	char* cidade;
	char* estado;
	char* telefone;
};

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para alocar memória para as strings da Cliente
	Parâmetro: Cliente
	Retorno: 
*/

void alocaMemoriaCliente(Cliente* cliente){

	cliente->nome = (char*)malloc(sizeof(char)*30);
	cliente->endereco = (char*)malloc(sizeof(char)*30);
	cliente->bairro = (char*)malloc(sizeof(char)*15);
	cliente->cep = (char*)malloc(sizeof(char)*10);
	cliente->cidade = (char*)malloc(sizeof(char)*20);
	cliente->estado = (char*)malloc(sizeof(char)*2);
	cliente->telefone = (char*)malloc(sizeof(char)*10);

}

struct data{
	int dia;
	int mes;
	int ano;
};

struct ordemServico{
	int codigoCliente;
	int codigoOrdemServico;
	char* descricaoSolicitacao;
	char* prioridade;
	Data dataSolicitacao;
	char status;
};

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para alocar memória para as strings da Ordem de Serviço
	Parâmetro: Ordem de serviço
	Retorno: 
*/

OrdemServico* alocaMemoriaOrdemServico(OrdemServico* ordemServico){
	ordemServico->descricaoSolicitacao = (char*)malloc(sizeof(char)*50);
	ordemServico->prioridade = (char*)malloc(sizeof(char)*6);
}

struct no{
	int tipoInformacao;
	void* informacao;
	No *prox;
	No *filho;
};
