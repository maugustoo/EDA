#include "structsModelo.h"
#include "Empresa.h"
#include "OrdemDeServico.h"

int main(){

	int opcao, opcaoMenuConsultar, codigo, ordenadoPorNome = 1, opcaoMostrarRelacao, codigoCliente, codigoOs;
	Cliente *cliente;
	Empresa *empresa;
	No* head = (No*)malloc(sizeof(No));
	char *nome;

	criaEmpresa(head, empresa);

	do{
		opcao = menu();
		switch(opcao){
			case 1:
				cliente = (Cliente*)malloc(sizeof(Cliente));
				if(leituraCliente(cliente, head->filho))
					head = insercaoCliente(head, cliente);
			break;
			case 2:
				opcaoMenuConsultar = menuConsultar();
				switch(opcaoMenuConsultar){
					case 0:
						break;
					case 1:
						nome = (char*)malloc(sizeof(char)*30);
						printf("Digita o nome ai\n");
						lerString(nome, 31);				
						consultarClientePorNome(head->filho, nome);
						break;
					case 2:
						printf("Digita o codigo ai\n");
						scanf("%d", &codigo);
						consultarClientePorCodigo(head->filho, codigo);
						break;
				}

			break;
			case 3:
				printf("Digita o codigo ai\n");
				scanf("%d", &codigo);
				head->filho = excluirCliente(head->filho, codigo);
				break;

			case 4:
				opcaoMostrarRelacao = menuMostrarRelacao();
				switch(opcaoMostrarRelacao){
					case 0:
						break;
					case 1:
						if(ordenadoPorNome)
							impressao(head->filho);
						else{
							ordenadoPorNome = 1;
							ordenaPorNome(head->filho);
							impressao(head->filho);
						}
						break;
					case 2:
						if(!ordenadoPorNome){
							impressao(head->filho);
						}else{
							ordenadoPorNome = 0;
							ordenaPorCodigo(head->filho);
							impressao(head->filho);
						}
				}
			break;
			case 6:
			  	cadastraOs(head->filho);
				break;
			case 7:
				impressaoGeral(head);
				break;
			case 8:
				printf("Digita o codigo do cliente ai\n");
				scanf("%d", &codigoCliente);
				printf("Digita o codigo da Ordem de servico ai\n");
				scanf("%d", &codigoOs);
				consultarOs(encontraCliente(head->filho, codigoCliente)->filho, codigoOs);
				break;
			case 9:
				printf("Digita o codigo do cliente ai\n");
				scanf("%d", &codigoCliente);
				printf("Digita o codigo da Ordem de servico ai\n");
				scanf("%d", &codigoOs);
				alterarOs(encontraCliente(head->filho, codigoCliente)->filho, codigoOs);
				
		}

	}while(opcao!=0);
}

int menu(){

	int opcao;

	printf("----------------------------------------------------------\n");
	printf("1) Cadastrar Novo Cliente\n");
	printf("2) Consultar Dados de Um Cliente\n");
	printf("3) Excluir Cliente\n");
	printf("4) Mostrar Relacao de Clientes\n");
	printf("5) Salvar Dados no Arquivo\n");
	printf("6) Cadastrar OS\n");
	printf("7) Mostrar tudo\n");
	printf("8) Consultar OS\n");
	printf("9) Alterar OS\n");
	printf("0) Sair\n");
	printf("----------------------------------------------------------\n");

	scanf("%d", &opcao);

	return opcao;
}

int menuConsultar(){
	int opcao;

	printf("----------------------------------------------------------\n");
	printf("1) Consultar por nome\n");
	printf("2) Consultar por codigo\n");
	printf("0) Sair\n");	
	printf("----------------------------------------------------------\n");	

	scanf("%d", &opcao);

	return opcao;
}

int menuMostrarRelacao(){
	int opcao;

	printf("----------------------------------------------------------\n");
	printf("1) Relacao em ordem alfabetica de nome\n");
	printf("2) Relacao em ordem de codigo\n");
	printf("0) Sair\n");
	printf("----------------------------------------------------------\n");

	scanf("%d", &opcao);

	return opcao;
}
