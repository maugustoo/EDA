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
	int qtdHorasGastas;
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
float calculaValor(No*, Atividade*, DescricaoAtividade*, int, int);
void calculaValorArrecadado(No* , float*, int, int, DescricaoAtividade*, No*);
void valorArrecadadoPorAtividade(No*, DescricaoAtividade*);
void imprimirAtividade(Atividade*);

#endif
