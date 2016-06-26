#ifndef ORDEMDESERVICO_H
#define ORDEMDESERVICO_H

#include "structsModelo.h"
#include "Cliente.h"

typedef struct servicos Servicos;
typedef struct ordemServico OrdemServico;
typedef struct data Data;
// typedef struct listaOS ListaOS;
// typedef struct cabecalho Cabecalho;

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

struct servicos{
	int codigo;
	char* descricao;
	float valorPorHora;
};
//
// struct listaOS {
//   ListaOS *prox;
//   ListaOS *ant;
//   struct ordemServico;
// };

// typedef struct Cabecalho {
//   ListaOS *head;
//   ListaOS *tail;
//   int qntd;
// }cabecalho;

struct ordemServico{
	int codigoCliente;
	int codigoOrdemServico;
	char* descricaoSolicitacao;
	char* prioridade;
	Data dataSolicitacao;
	char status;
};

OrdemServico* alocaMemoriaOrdemServico(OrdemServico*);
No* consultarCliente(No*, int);
No* lerOrdemServico(OrdemServico*, No*);
void cadastraOs(No*);
int comparaCodigoOs(int, OrdemServico*);
No* encontraOs(No*, int);
No* consultarOs(No*, int);
OrdemServico* lerAlteracaoOrdemServico(OrdemServico*);
void alterarOs(No*, int);
void imprimirOS(OrdemServico*);
No* excluirOs(No*, int);

#endif
