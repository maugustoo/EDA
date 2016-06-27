#include "Validacao.h"
#include "structsModelo.h"
#include "Empresa.h"
#include "OrdemDeServico.h"
#include "Atividade.h"
#include "Cliente.h"
#include "Arquivo.h"

DescricaoAtividade* defineAtividades(DescricaoAtividade* descricaoAtividade);
void criaBanco();

int main(){

	int opcao, opcaoMenuConsultar, codigo, ordenadoPorNome = 1, opcaoMostrarRelacao, codigoCliente, codigoOs,codigoAtividade;
	Cliente *cliente;
	Empresa *empresa;
	No* clienteEncontrado = (No*)malloc(sizeof(No));
	No* headOs = (No*)malloc(sizeof(No));
	No* ordemServicoEncontrada = (No*)malloc(sizeof(No));
	No* head = (No*)malloc(sizeof(No));
	char *nome;
	
	DescricaoAtividade* descricaoAtividade = defineAtividades(descricaoAtividade);
	
	criaEmpresa(head, empresa);

	lerDados(head);

	do{
		opcao = menu();
		switch(opcao){
			case 0:
			break;
			case 1:
				printf("\33[H\33[2J");
				cliente = (Cliente*)malloc(sizeof(Cliente));
				if(leituraCliente(cliente, head->filho))
					head = insercaoCliente(head, cliente);
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 2:
				printf("\33[H\33[2J");
				opcaoMenuConsultar = menuConsultar();
				switch(opcaoMenuConsultar){
					case 0:
						break;
					case 1:
						nome = (char*)malloc(sizeof(char)*30);
						printf("Digite o nome do cliente: \n");
						lerString(nome, 31);
						printf("\33[H\33[2J");
						printf("Lista de clientes com o nome %s: \n", nome);
						consultarClientePorNome(head->filho, nome);
						printf("\n\nPressione ENTER para continuar!\n");
						getchar();
						break;
					case 2:
						printf("Digite o codigo do cliente: \n");
						scanf("%d", &codigo);
						printf("\33[H\33[2J");
						printf("Lista de clientes com o codigo %d: \n", codigo);
						consultarClientePorCodigo(head->filho, codigo);
						printf("\n\nPressione ENTER para continuar!\n");
						getchar();
						getchar();
						break;
					default:
						printf("\33[H\33[2J");
						printf("OPCAO DO MENU INVALIDA!\n");
						getchar();
						getchar();
				}
			break;
			case 3:
				printf("\33[H\33[2J");
				opcaoMostrarRelacao = menuMostrarRelacao();
				switch(opcaoMostrarRelacao){
					case 0:
						break;
					case 1:
						printf("\33[H\33[2J");
						if(ordenadoPorNome)
							impressao(head->filho);
						else{
							ordenadoPorNome = 1;
							ordenaPorNome(head->filho);
							impressao(head->filho);
						}
						printf("\n\nPressione ENTER para continuar!\n");
						getchar();
						getchar();
						break;
					case 2:
						printf("\33[H\33[2J");
						if(!ordenadoPorNome){
							impressao(head->filho);
						}else{
							ordenadoPorNome = 0;
							ordenaPorCodigo(head->filho);
							impressao(head->filho);
						}
						printf("\n\nPressione ENTER para continuar!\n");
						getchar();
						getchar();
						break;
					default:
						printf("\33[H\33[2J");
						printf("OPCAO DO MENU INVALIDA!\n");
						getchar();
						getchar();
				}
			break;
			case 4:
				printf("\33[H\33[2J");
				printf("Digite o codigo do cliente\n");
				scanf("%d", &codigo);
				head->filho = excluirCliente(head->filho, codigo);
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 5:
				printf("\33[H\33[2J");
			  	cadastraOs(head->filho);
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 6:
				printf("\33[H\33[2J");
				printf("Digite o codigo do cliente: \n");
				scanf("%d", &codigoCliente);
				printf("Digite o codigo da Ordem de servico: \n");
				scanf("%d", &codigoOs);
				clienteEncontrado = encontraCliente(head->filho, codigoCliente);
				if(clienteEncontrado != NULL){
					printf("\33[H\33[2J");
					encontraOs(clienteEncontrado->filho, codigoOs);
					consultarOs(clienteEncontrado->filho, codigoOs);
				}
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 7:
				printf("\33[H\33[2J");
				printf("Digite o codigo do cliente: \n");
				scanf("%d", &codigoCliente);
				printf("Digite o codigo da Ordem de servico: \n");
				scanf("%d", &codigoOs);
				printf("\33[H\33[2J");
				clienteEncontrado = encontraCliente(head->filho, codigoCliente);
				if(clienteEncontrado != NULL)
					ordemServicoEncontrada = encontraOs(clienteEncontrado->filho, codigoOs);
				if(clienteEncontrado != NULL && ordemServicoEncontrada != NULL)
					alterarOs(clienteEncontrado->filho, codigoOs);

				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 8:
				printf("\33[H\33[2J");
				printf("Digite o codigo do cliente: \n");
				scanf("%d", &codigoCliente);
				printf("Digite o codigo da Ordem de servico: \n");
				scanf("%d", &codigoOs);
				clienteEncontrado = encontraCliente(head->filho, codigoCliente);
				if(clienteEncontrado != NULL){
					headOs = excluirOs(clienteEncontrado->filho, codigoOs);
					clienteEncontrado->filho = headOs;
				}
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 9:
				printf("\33[H\33[2J");
				cadastraAtividade(head);
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 10:
				printf("\33[H\33[2J");
				printf("Digite o codigo do cliente: \n");
				scanf("%d", &codigoCliente);
				printf("Digite o codigo da Ordem de servico: \n");
				scanf("%d", &codigoOs);
				printf("Digite o codigo da Atividade: \n");
				scanf("%d", &codigoAtividade);
				clienteEncontrado = encontraCliente(head->filho, codigoCliente);
				if(clienteEncontrado != NULL){
					ordemServicoEncontrada = encontraOs(clienteEncontrado->filho, codigoOs);
					if(ordemServicoEncontrada != NULL && ordemServicoAberta(ordemServicoEncontrada->informacao)){
						ordemServicoEncontrada->filho = excluirAtividade(ordemServicoEncontrada,codigoAtividade);
					}
					else if(ordemServicoEncontrada == NULL || !ordemServicoAberta(ordemServicoEncontrada->informacao)){
						printf("\n\nNao e possivel excluir uma atividade em uma ordem de servico fechada.\n");
					}
				}
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 11:
				printf("\33[H\33[2J");
				valorArrecadadoPorAtividade(head->filho, descricaoAtividade);
				printf("\n\nPressione ENTER para continuar!\n");
				getchar();
				getchar();
			break;
			case 12:
				criaBanco();
				salvarDadosArquivo(head->filho);
				printf("\33[H\33[2J");
				printf("Dados salvos com sucesso!");
				getchar();
				getchar();
			break;
			default:
				printf("\33[H\33[2J");
				printf("OPCAO DO MENU INVALIDA!\n");
				getchar();
				getchar();
		}

	}while(opcao!=0);
}

void criaBanco(){
	FILE *arquivoOriginal, *arquivoAposExclusao;

	arquivoOriginal = fopen("BancoDados.txt", "r");
	arquivoAposExclusao = fopen("BancoDadosAuxiliar.txt", "w");

	if(!arquivoOriginal || !arquivoAposExclusao){
		printf("\n\t\t*** Houve um erro ao abrir o arquivo, o programa sera fechado! ***");
		getchar();
		exit(0);
	}
	unlink("BancoDados.txt");
	rename("BancoDadosAuxiliar.txt", "BancoDados.txt");	
}

int menu(){

	int opcao;

	printf("\33[H\33[2J");
	printf("----------------------------------------------------------\n");
	printf("                        MENU GERAL\n");
	printf("----------------------------------------------------------\n");
	printf("1) Cadastrar Novo Cliente\n");
	printf("2) Consultar Dados de Um Cliente\n");
	printf("3) Mostrar Relacao de Clientes\n");
	printf("4) Excluir Cliente\n");
	printf("----------------------------------------------------------\n");
	printf("5) Cadastrar OS\n");
	printf("6) Consultar OS\n");
	printf("7) Alterar OS\n");
	printf("8) Excluir OS\n");
	printf("----------------------------------------------------------\n");
	printf("9) Cadastrar Atividade\n");
	printf("10) Excluir Atividade\n");
	printf("11) Valor arrecadado por atividade\n");
	printf("----------------------------------------------------------\n");
	printf("12) Salvar Dados no Arquivo\n");
	printf("0) Sair\n");
	printf("----------------------------------------------------------\n");

	scanf("%d", &opcao);

	return opcao;
}

int menuConsultar(){
	int opcao;
	printf("\33[H\33[2J");
	printf("----------------------------------------------------------\n");
	printf("                      CONSULTAR CLIENTE\n");
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
	printf("\33[H\33[2J");
	printf("----------------------------------------------------------\n");
	printf("                      LISTAR CLIENTES\n");
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
