#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "structsModelo.h"
#include "Cliente.h"

void salvarCliente(Cliente*, int);
void salvarOs(OrdemServico*, int);
void salvarAtividade(Atividade*, int);
void salvarDadosArquivo(No* head);
void cadastraOsArquivo(No*, OrdemServico*);
void cadastraAtividadeArquivo(No*, Atividade*);
void lerDados(No* );

#endif
