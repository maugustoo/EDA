#ifndef STRUCTSMODELO_H
#define STRUCTSMODELO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLIENTE 0
#define OS 1
#define ATIVIDADE 2
#define EMPRESA 3
#define DESCRICAO 50
#define DATA 10

typedef struct no No;

struct no{
	int tipoInformacao;
	void* informacao;
	No *prox;
	No *filho;
};

#endif
