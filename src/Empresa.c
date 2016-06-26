#include "../inc/Empresa.h"

void alocaMemoriaEmpresa(Empresa* empresa){
	empresa->nome = (char*) malloc(sizeof(char)*30);
}

void criaEmpresa(No* head, Empresa* empresa){

	empresa = (Empresa*)malloc(sizeof(Empresa));

	alocaMemoriaEmpresa(empresa);

	empresa->nome = "Oficina Santa Genoveva";

	head->informacao = empresa;
	head->tipoInformacao = EMPRESA;
	head->filho = NULL;
	head->prox = NULL;
}

void imprimirEmpresa(Empresa* empresa){
	printf("Nome Empresa: %s\n", empresa->nome);
}
