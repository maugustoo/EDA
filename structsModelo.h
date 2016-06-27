#ifndef STRUCTSMODELO_H
#define STRUCTSMODELO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CLIENTE 0
#define OS 1
#define ATIVIDADE 2
#define EMPRESA 3

typedef struct servicos Servicos;
typedef struct cliente Cliente;
typedef struct ordemServico OrdemServico;
typedef struct data Data;
typedef struct no No;
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
	int qtdHorasGastas;
};

/*
	Responsavel: Augusto Moreno
*/

struct descricaoAtividade{
	char* descricao;
	float valorHora;
};

/*
	Responsavel: Marcelo Augusto
*/

/*
	Responsavel: Marcelo Augusto
*/

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
*/


struct empresa{
	char* nome;
};


/*
	Responsavel: Marcelo Augusto
*/

struct data{
	int dia;
	int mes;
	int ano;
};

/*
	Responsavel: Marcelo Augusto
*/

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
*/

struct no{
	int tipoInformacao;
	void* informacao;
	No *prox;
	No *filho;
};

#endif
