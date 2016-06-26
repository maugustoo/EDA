#ifndef CLIENTE_H
#define CLIENTE_H

#include "structsModelo.h"
#include "Empresa.h"
#include "OrdemDeServico.h"
#include "Atividade.h"

typedef struct cliente Cliente;

struct cliente {
	int codigo;
	char* nome;
	char* endereco;
	char* bairro;
	char* cep;
	char* cidade;
	char* estado;
	char* telefone;
};

void alocaMemoriaCliente(Cliente *);
void lerString(char *, int);
int comparaCodigo(int, Cliente*);
void imprimirCliente(Cliente*);
int codigoERepetido(No*, int);
void consultarClientePorCodigo(No*, int);
int leituraCliente(Cliente*, No*);
int comparaNome(char*, Cliente*);
No* insercaoCliente(No*, Cliente*);
//void imprimirEmpresa(Empresa* empresa);
void consultarClientePorNome(No*, char*);
No* excluirCliente(No*, int);
int comparaNomeOrdenacao(Cliente*, Cliente*);
void ordenaPorNome(No*);
int comparaMaiorCodigo(Cliente*, Cliente*);
void ordenaPorCodigo(No*);
void impressao(No*);
//void imprimirOS(OrdemServico* ordemServico);
//void imprimirAtividade(Atividade* atividade);
void impressaoGeral(No*);
#endif
