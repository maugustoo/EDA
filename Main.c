#include "structsModelo.h"
#include "Empresa.h"

int menu();

int main(){

	int opcao, opcaoMenuConsultar, codigo;
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
				leituraCliente(cliente);
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
						consultaNome(head->filho, nome);
						break;
					case 2:
						printf("Digita o codigo ai\n");
						scanf("%d", &codigo);
						consultaCodigo(head->filho, codigo);
						break;
				}

			break;
			case 4:
				impressao(head);
			break;
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
