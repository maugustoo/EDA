#include "structsModelo.h"
#include "Empresa.h"

int menu();

int main(){

	int opcao;
	Cliente *cliente;
	Empresa *empresa;
	No* head = (No*)malloc(sizeof(No));

	criaEmpresa(head, empresa);

	do{
		opcao = menu();
		switch(opcao){
			case 1:
				cliente = (Cliente*)malloc(sizeof(Cliente));
				leituraCliente(cliente);
				head = insercaoCliente(head, cliente);
			break;
			case 4:
				impressao(head);
			break;
		}

	}while(opcao!=6);
}

int menu(){

	int opcao;

	printf("----------------------------------------------------------\n");
	printf("1) Cadastrar Novo Cliente\n");
	printf("2) Consultar Dados de Um Cliente\n");
	printf("3) Excluir Cliente\n");
	printf("4) Mostrar Relacao de Clientes\n");
	printf("5) Salvar Dados no Arquivo\n");
	printf("6) Sair\n");
	printf("----------------------------------------------------------\n");

	scanf("%d", &opcao);

	return opcao;
}
