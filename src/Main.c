#include "../inc/structsModelo.h"
#include "../inc/Empresa.h"
#include "../inc/OrdemDeServico.h"
#include "../inc/Atividade.h"
#include "../inc/Cliente.h"

int menu();
int menuConsultar();
int menuMostrarRelacao();

DescricaoAtividade* defineAtividades(DescricaoAtividade* descricaoAtividade);

// void impressaoGeral(No* head){
//
// 	if(head==NULL)
// 		return;
//
// 	if(head->tipoInformacao == CLIENTE)
// 		imprimirCliente(head->informacao);
// 	else if(head->tipoInformacao == EMPRESA)
// 		imprimirEmpresa(head->informacao);
// 	else if(head->tipoInformacao == OS)
// 		imprimirOS(head->informacao);
// 	else if(head->tipoInformacao == ATIVIDADE)
// 		imprimirAtividade(head->informacao);
//
// 	impressaoGeral(head->filho);
// 	impressaoGeral(head->prox);
// }

int main(){

	int opcao, opcaoMenuConsultar, codigo, ordenadoPorNome = 1, opcaoMostrarRelacao,codigoAtividade, codigoCliente, codigoOs;
	Cliente *cliente = NULL;
	Empresa *empresa = NULL;
	No* head = (No*)malloc(sizeof(No));
	No* clienteEncontrado = NULL;
	No *ordemServicoEncontrada = NULL;
	char *nome;

	DescricaoAtividade* descricaoAtividade = NULL;
	descricaoAtividade = defineAtividades(descricaoAtividade);

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
						consultarCliente(head->filho, codigo);
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
				clienteEncontrado = consultarCliente(head->filho, codigoCliente);

				if(clienteEncontrado != NULL){
					consultarOs(clienteEncontrado->filho, codigoOs);
				}
				break;
			case 9:
				printf("Digita o codigo do cliente ai\n");
				scanf("%d", &codigoCliente);
				printf("Digita o codigo da Ordem de servico ai\n");
				scanf("%d", &codigoOs);
				clienteEncontrado = consultarCliente(head->filho, codigoCliente);

				if(clienteEncontrado != NULL){
					alterarOs(clienteEncontrado->filho, codigoOs);
				}
				break;
			case 10:
				cadastraAtividade(head);
				break;
			case 11:
			printf("Digita o codigo do cliente ai\n");
			scanf("%d", &codigoCliente);
			printf("Digita o codigo da Ordem de servico ai\n");
			scanf("%d", &codigoOs);
			clienteEncontrado = consultarCliente(head->filho, codigoCliente);
			ordemServicoEncontrada = encontraOs(head->filho, codigoOs);
			if(clienteEncontrado != NULL && ordemServicoEncontrada != NULL){
				No *headOs = excluirOs(clienteEncontrado->filho, codigoOs);
				clienteEncontrado->filho = headOs;
			}
				break;
			case 12:
			printf("Digita o codigo do cliente ai\n");
			scanf("%d", &codigoCliente);
			printf("Digita o codigo da Ordem de servico ai\n");
			scanf("%d", &codigoOs);
			printf("Digita o codigo da Atividade ai\n");
			scanf("%d", &codigoAtividade);
			clienteEncontrado = consultarCliente(head->filho, codigoCliente);
			if(clienteEncontrado != NULL){
				ordemServicoEncontrada = encontraOs(clienteEncontrado->filho, codigoOs);
				if(ordemServicoEncontrada != NULL && ordemServicoAberta(ordemServicoEncontrada->informacao)){
					ordemServicoEncontrada->filho = excluirAtividade(ordemServicoEncontrada->filho,codigoAtividade);
				}
				else if(ordemServicoEncontrada == NULL || !ordemServicoAberta(ordemServicoEncontrada->informacao)){
					printf("Nao e possivel excluir uma atividade em uma ordem de servico fechada.\n");
				}
			}
				break;
			case 13:
				valorArrecadadoPorAtividade(head->filho, descricaoAtividade);

		}

	}while(opcao!=0);
return 0;
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
	printf("10) Cadastrar Atividade\n");
	printf("11) Excluir Ordem de Servico\n");
	printf("12) Excluir Atividade\n");
	printf("13) Valor arrecadado por atividade\n");
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

DescricaoAtividade* defineAtividades(DescricaoAtividade* descricaoAtividade){
	descricaoAtividade = (DescricaoAtividade*)malloc (sizeof(DescricaoAtividade)*8);
	descricaoAtividade[0].descricao = "Desmontagem";
	descricaoAtividade[0].valorHora = 30.00;
	descricaoAtividade[1].descricao = "Serviços de funilaria";
	descricaoAtividade[1].valorHora = 120.00;
	descricaoAtividade[2].descricao = "Serviços de pintura";
	descricaoAtividade[2].valorHora = 180.00;
	descricaoAtividade[3].descricao = "Serviços de eletricidade";
	descricaoAtividade[3].valorHora = 90.00;
	descricaoAtividade[4].descricao = "Serviços de mecânica";
	descricaoAtividade[4].valorHora = 110.00;
	descricaoAtividade[5].descricao =  "Alinhamento/balanceamento";
	descricaoAtividade[5].valorHora = 40.00;
	descricaoAtividade[6].descricao = "Lavagem";
	descricaoAtividade[6].valorHora = 25.00;
	descricaoAtividade[7].descricao = "Polimento";
	descricaoAtividade[7].valorHora = 35.00;

	return descricaoAtividade;
}
