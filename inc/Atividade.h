#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "structsModelo.h"
#include "OrdemDeServico.h"
#include "Cliente.h"

typedef struct atividade Atividade;
typedef struct descricaoAtividade DescricaoAtividade;

struct atividade {
	int codigoCliente;
	int codigoOs;
	int codigoAtividade;
};

struct descricaoAtividade {
	char* descricao;
	float valorHora;
};

void alocaMemoriaDescricaoAtividade(DescricaoAtividade*);
Atividade* lerAtividade(Atividade*, No*);
int comparaCodigoAtividade(Atividade*, int);
void cadastraAtividade(No*);
No* excluirAtividade (No*, int);
void imprimirAtividade(Atividade*);

#endif
