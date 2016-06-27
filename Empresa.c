#include "Empresa.h"

/*
	Responsavel: Marcelo Augusto
	Objetivo: Função para alocar memória para as strings da Empresa
	Parâmetro: Empresa
	Retorno: 
*/

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
