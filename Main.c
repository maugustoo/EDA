#include "structsModelo.h"
#include "Cliente.h"

int main(){

	Cliente *cliente;
	No* head = (No*)malloc(sizeof(No));

	Empresa *empresa = (Empresa*)malloc(sizeof(Empresa));
	alocaMemoriaEmpresa(empresa);
	empresa->CNPJ = 1234566;
	empresa->nome = "Jurisval";

	head->informacao = empresa;
	head->tipoInformacao = EMPRESA;
	head->filho = NULL;
	head->prox = NULL;

	int x = 5;
	while(x--){
		cliente = (Cliente*)malloc(sizeof(Cliente));

		leituraCliente(cliente);
		head = insercaoCliente(head, cliente);
	}
	impressao(head);
}
