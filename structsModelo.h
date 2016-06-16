#include <stdio.h>

typedef struct servicos Servicos;
typedef struct cliente Cliente;
typedef struct ordemServico OrdemServico;
typedef struct data Data;


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
