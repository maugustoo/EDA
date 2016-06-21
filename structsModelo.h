#include <stdio.h>
#include <stdlib.h>

typedef struct servicos Servicos;
typedef struct cliente Cliente;
typedef struct ordemServico OrdemServico;
typedef struct data Data;
typedef struct no No;
typedef struct cabec Cabec;


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

Cliente alocaMemoriaCliente(Cliente cliente){
	cliente.nome = (char*)malloc(sizeof(char)*30);
	cliente.endereco = (char*)malloc(sizeof(char)*30);
	cliente.bairro = (char*)malloc(sizeof(char)*15);
	cliente.cep = (char*)malloc(sizeof(char)*10);
	cliente.cidade = (char*)malloc(sizeof(char)*20);
	cliente.estado = (char*)malloc(sizeof(char)*2);
	cliente.telefone = (char*)malloc(sizeof(char)*10);

	return cliente;
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

OrdemServico alocaMemoriaOrdemServico(OrdemServico ordemServico){
	ordemServico.descricaoSolicitacao = (char*)malloc(sizeof(char)*50);
	ordemServico.prioridade = (char*)malloc(sizeof(char)*6);
}

struct no{
	int tipoInformacao;
	void *informacao;
	No *prox, *ant;
	No *filho;
};
