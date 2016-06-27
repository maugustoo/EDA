#ifndef CLIENTE_H
#define CLIENTE_H

#include "structsModelo.h"
#include "Empresa.h"
#include "OrdemDeServico.h"
#include "Atividade.h"


void alocaMemoriaCliente(Cliente *);
void lerString(char *, int);
int comparaCodigo(int, Cliente*);
void imprimirCliente(Cliente*);
int codigoERepetido(No*, int);
void consultarClientePorCodigo(No*, int);
int leituraCliente(Cliente*, No*);
int comparaNome(char*, Cliente*);
No* insercaoCliente(No*, Cliente*);
void imprimirEmpresa(Empresa*);
void consultarClientePorNome(No*, char*);
No* excluirCliente(No*, int);
int comparaNomeOrdenacao(Cliente*, Cliente*);
void ordenaPorNome(No*);
int comparaMaiorCodigo(Cliente*, Cliente*);
void ordenaPorCodigo(No*);
void impressao(No*);
void imprimirOS(OrdemServico*);
void imprimirAtividade(Atividade*);

#endif
