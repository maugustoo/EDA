#include "structsModelo.h"
#include "Cliente.h"

int main(){

	Cliente cliente;
	No* head;

	int x = 3;
	while(x--){
		leituraCliente(cliente);
		insercaoCliente(head, &cliente);
	}
}
