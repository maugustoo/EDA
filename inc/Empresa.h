#ifndef EMPRESA_H
#define EMPRESA_H

#include "structsModelo.h"

typedef struct empresa Empresa;

struct empresa{
	char* nome;
};

void alocaMemoriaEmpresa(Empresa*);
void criaEmpresa(No*, Empresa*);
void imprimirEmpresa(Empresa*);

#endif
