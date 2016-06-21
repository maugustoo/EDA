#include <stdio.h>
#include <stdlib.h>

#include "Cliente.h"

#define EMPRESA 3

void criaEmpresa(No* head, Empresa* empresa){

	empresa = (Empresa*)malloc(sizeof(Empresa));

	alocaMemoriaEmpresa(empresa);

	empresa->nome = "Oficina Santa Genoveva";

	head->informacao = empresa;
	head->tipoInformacao = EMPRESA;
	head->filho = NULL;
	head->prox = NULL;

}
