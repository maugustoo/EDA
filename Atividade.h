#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Nome: Augusto Moreno
 O que faz: Lê os dados de uma Atividade;
 Parametro de Entrada: OrdemServico* ordemServico, No* head;
 Parametro de saida: Cliente encontrado, ordem de serviço;
*/

Atividade* lerAtividade(Atividade* atividade, No* head){
	int codigo,codigoOS,codigoAtividade, quantidadeDeHorasGastas;
	No* clienteEncontrado;
    	No* ordemServico;
    	
    	printf("Digite o codigo do Cliente: \n");
	scanf("%d",&codigo);
	
	clienteEncontrado = encontraCliente(head->filho, codigo);
	
	if(clienteEncontrado == NULL){
		return NULL;
	}
	
	printf("Digite o codigo da Ordem de servico: \n");
	scanf("%d",&codigoOS);

	ordemServico = encontraOs(clienteEncontrado->filho,codigoOS);
	
	if(ordemServico == NULL){
		return NULL;
	}
	
	do{
		printf("Digite o codigo da Atividade: \n");
		scanf("%d",&codigoAtividade);

		if(!validaCodigoAtividade(codigoAtividade))
			printf("\n\n*****Codigo da atividade incorreto! Digite novamente!*****\n");

	}while(!validaCodigoAtividade(codigoAtividade));
	do{
		printf("Digite a quantidade de horas gastas na atividade: \n");
		scanf("%d", &quantidadeDeHorasGastas);
		if(!validaInt(quantidadeDeHorasGastas))
			printf("\n\n*****Quantidade invalida! Digite novamente!*****\n");
	}while(!validaInt(quantidadeDeHorasGastas));

	atividade->codigoAtividade = codigoAtividade;
	atividade->codigoCliente = codigo;
	atividade->codigoOs = codigoOS;
	atividade->qtdHorasGastas = quantidadeDeHorasGastas;
	
	return atividade;
	
}

/*
	Responsavel:Augusto Morneo
	Objetivo: Função para comparar um código com o código de uma atividade.
	Parâmetro: Código da atividade, Atividade
	Retorno: 1 caso sejam iguais, 0 caso contrário
*/


int comparaCodigoAtividade(Atividade* atividade, int codigoAtividade){
	return atividade->codigoAtividade == codigoAtividade;
}

/*
	Responsavel:Augusto Morneo
	Objetivo: Função para inserir uma atividade na lista de atividades.
	Parâmetro: Cabeça da árvore
	Retorno: 
*/

void cadastraAtividade(No* head){

	No* clienteEncontrado;
    	No* ordemServico;
	No* novaAtividade;
	
	novaAtividade = (No*)malloc(sizeof(No));
	Atividade* atividade = (Atividade*)malloc(sizeof(Atividade));
	
	atividade = lerAtividade(atividade,head);
	novaAtividade->informacao = atividade;
	novaAtividade->tipoInformacao = ATIVIDADE;
	novaAtividade->filho = NULL;
	
	if(atividade == NULL)
		return;
    
	clienteEncontrado = encontraCliente(head->filho, atividade->codigoCliente);
	
	ordemServico = encontraOs(clienteEncontrado->filho,atividade->codigoOs);
	
	if(ordemServicoAberta(ordemServico->informacao)){
		if(ordemServico->filho == NULL){
			ordemServico->filho = novaAtividade;
			novaAtividade->prox = NULL;
		}else{
			novaAtividade->prox = ordemServico->filho;
			ordemServico->filho = novaAtividade;
		}
	}else{
		printf("\33[H\33[2J");
		printf("Nao e possivel cadastrar uma atividade para uma Ordem de servico fechada!\n");
	}
}

/*
	Responsavel:Augusto Morneo
	Objetivo: Função para excluir uma atividade na lista de atividades.
	Parâmetro: Cabeça da árvore, Codigo da atividade
	Retorno: Nova cabeça da ávore de atividades
*/


No* excluirAtividade (No* headAtividades, int codigoAtividade){

	No* auxHeadAtividades = headAtividades->filho;
	No* auxAnterior = NULL;
	
	if(ordemServicoAberta(headAtividades->informacao)){
		while(auxHeadAtividades != NULL && !comparaCodigoAtividade((Atividade*)auxHeadAtividades->informacao,codigoAtividade)){
			auxAnterior = auxHeadAtividades;
			auxHeadAtividades = auxHeadAtividades->prox;
		}

		if(auxHeadAtividades == NULL){
			printf("\nNão existe atividades cadastradas com o codigo %d.\n",codigoAtividade);			
		}
		else if(auxAnterior == NULL){
			headAtividades = auxHeadAtividades->prox;
			free(auxHeadAtividades);
			printf("\33[H\33[2J");
			printf("Atividade excluida com sucesso!\n");
		}
		else{
			auxAnterior->prox = auxHeadAtividades->prox;
			free(auxHeadAtividades);
			printf("\33[H\33[2J");
			printf("Atividade excluida com sucesso!\n");
		}
	}else{
		printf("\33[H\33[2J");
		printf("Nao e possivel excluir uma atividade para uma Ordem de servico fechada!\n");
	}

	return headAtividades;
}


/*
	Responsavel: Marcelo Augusto
	Objetivo: Resgatar o mes de uma ordem de serviço
	Parâmetro: Ordem de serviço
	Retorno: Mes da Ordem de serviço
*/

int mesOs(OrdemServico* ordemServico){
	return ordemServico->dataSolicitacao.mes;
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Pesquisar o mes de uma ordem de serviço
	Parâmetro: Cabeça do nivel da árvore referente aos clientes, codigo da Os pesquisada
	Retorno: 
*/

void pesquisaMesOs(No* head, int codigoOs, int* mes){

	if(head==NULL)
		return;

	if(head->tipoInformacao == OS && comparaCodigoOs(codigoOs, (OrdemServico*)head->informacao)){
		mes[0] = mesOs(head->informacao);
	}

	pesquisaMesOs(head->filho, codigoOs, mes);
	pesquisaMesOs(head->prox, codigoOs, mes);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Calcula o valor arrecadado por uma atividade que segue os critérios
	Parâmetro: Cabeça do nivel da árvore referente aos clientes, Atividade, Descrição das atividades, Atividade pesquisada, Mes pesquisado
	Retorno: Valor calculado para a atividade
*/

float calculaValor(No* head, Atividade* atividade, DescricaoAtividade* descricaoAtividade, int atividadePesquisada, int mesPesquisado){

	int *mes = (int*)malloc(sizeof(int));

	pesquisaMesOs(head, atividade->codigoOs, mes);

	if(atividade->codigoAtividade == atividadePesquisada &&  mes[0] == mesPesquisado){
		return atividade->qtdHorasGastas * descricaoAtividade[atividade->codigoAtividade].valorHora;
	}
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Calcula o valor arrecadado de todas as atividades que seguirem os critérios
	Parâmetro: Cabeça do nivel da árvore referente aos clientes, Valor arrecadado, Atividade pesquisada, Mes pesquisado, Descrição das atividades, Cabeça do nivel da árvore referente aos clientes auxiliar
	Retorno: 
*/

void calculaValorArrecadado(No* head, float* valorArrecadado, int atividadePesquisada, int mesPesquisado, DescricaoAtividade* descricaoAtividade, No* headAux){

	if(head==NULL)
		return ;

	if(head->tipoInformacao == ATIVIDADE){
		valorArrecadado[0] += calculaValor(headAux, head->informacao, descricaoAtividade, atividadePesquisada, mesPesquisado);
	}

	calculaValorArrecadado(head->filho, valorArrecadado, atividadePesquisada, mesPesquisado, descricaoAtividade, headAux);
	calculaValorArrecadado(head->prox, valorArrecadado, atividadePesquisada, mesPesquisado, descricaoAtividade, headAux);

}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Mostrar o valor arrecadado em um determinado mes com uma atividade.
	Parâmetro: Cabeça da árvore
	Retorno: 
*/

void valorArrecadadoPorAtividade(No* head, DescricaoAtividade* descricaoAtividade){


	int mesPesquisado, atividadePesquisada;
	float *valorArrecadado = (float*)malloc(sizeof(float));
	valorArrecadado[0] = 0;


	printf("Digite a atividade que se deseja calcular o valor arrecadado: \n");
	scanf("%d", &atividadePesquisada);

	printf("Digite o mes ao qual se deseja calcular o valor arrecadado pela atividade %d.\n", atividadePesquisada);
	scanf("%d", &mesPesquisado);

	calculaValorArrecadado(head, valorArrecadado, atividadePesquisada, mesPesquisado, descricaoAtividade, head);

	printf("\33[H\33[2J");
	printf("O valor arrecadado pela Atividade %d no mes %d foi: R$%.2f\n",  atividadePesquisada, mesPesquisado, valorArrecadado[0]);
}
