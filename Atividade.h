#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include "structsModelo.h"
#include "OrdemDeServico.h"
#include "Cliente.h"

void alocaMemoriaDescricaoAtividade(DescricaoAtividade*);
Atividade* lerAtividade(Atividade*, No*);
int comparaCodigoAtividade(Atividade*, int);
void cadastraAtividade(No*);
No* excluirAtividade (No*, int);
int mesOs(OrdemServico*);
void pesquisaMesOs(No*, int, int*);
float calculaValor(No*, Atividade*, DescricaoAtividade*, int, int);
void calculaValorArrecadado(No* , float*, int, int, DescricaoAtividade*, No*);
void valorArrecadadoPorAtividade(No*, DescricaoAtividade*);

#endif
