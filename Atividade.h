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
    	
    	printf("Digite o codigo do Cliente\n");
	scanf("%d",&codigo);
	
	clienteEncontrado = encontraCliente(head->filho, codigo);
	
	if(clienteEncontrado == NULL){
		return NULL;
	}
	
	printf("Digite o codigo da Ordem de servico\n");
	scanf("%d",&codigoOS);

	ordemServico = encontraOs(clienteEncontrado->filho,codigoOS);
	
	if(ordemServico == NULL){
		return NULL;
	}
	
	printf("Digite o codigo da Atividade\n");
	scanf("%d",&codigoAtividade);
	
	printf("Digite a quantidade de horas gastas na atividade\n");
	scanf("%d", &quantidadeDeHorasGastas);

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
	
	
	if(ordemServico->filho == NULL){
		ordemServico->filho = novaAtividade;
		novaAtividade->prox = NULL;
	}else{
		novaAtividade->prox = ordemServico->filho;
		ordemServico->filho = novaAtividade;
	}

}

/*
	Responsavel:Augusto Morneo
	Objetivo: Função para excluir uma atividade na lista de atividades.
	Parâmetro: Cabeça da árvore, Codigo da atividade
	Retorno: Nova cabeça da ávore de atividades
*/


No* excluirAtividade (No* headAtividades, int codigoAtividade){

	No* auxHeadAtividades = headAtividades;
	No* auxAnterior = NULL;
	
	while(auxHeadAtividades != NULL && !comparaCodigoAtividade((Atividade*)auxHeadAtividades->informacao,codigoAtividade)){
		auxAnterior = auxHeadAtividades;
		auxHeadAtividades = auxHeadAtividades->prox;
	}

	if(auxHeadAtividades == NULL){
		printf("Não existe atividades cadastradas com o codigo %d.\n",codigoAtividade);			
	}
	else if(auxAnterior == NULL){
		headAtividades = auxHeadAtividades->prox;
		free(auxHeadAtividades);
	}
	else{
		auxAnterior->prox = auxHeadAtividades->prox;
		free(auxHeadAtividades);
	}

	return headAtividades;
}


int mesOs(OrdemServico* ordemServico){
	return ordemServico->dataSolicitacao.mes;
}

int codigo(OrdemServico* ordemServico){
	return ordemServico->codigoOrdemServico;
}

int pesquisaMesOs(No* head, int codigoOs){

	if(head==NULL)
		return;

	printf("codigos pesquisados %d %d\n", codigoOs, codigo((OrdemServico*)head->informacao));
	printf("head tipo info %d %d\n", head->tipoInformacao, OS);

	if(head->tipoInformacao == OS && comparaCodigoOs(codigoOs, (OrdemServico*)head->informacao)){
		printf("mes OS %d\n", mesOs(head->informacao));
		return mesOs(head->informacao);
	}

	return pesquisaMesOs(head->filho, codigoOs);
	return pesquisaMesOs(head->prox, codigoOs);
}

float calculaValor(No* head, Atividade* atividade, DescricaoAtividade* descricaoAtividade, int atividadePesquisada, int mesPesquisado){

	printf("%d %d %d\n", pesquisaMesOs(head, atividade->codigoOs), atividade->codigoOs, mesPesquisado);

	if(atividade->codigoAtividade == atividadePesquisada && pesquisaMesOs(head, atividade->codigoOs) == mesPesquisado){
		printf("entrou\n");
		return atividade->qtdHorasGastas * descricaoAtividade[atividade->codigoAtividade].valorHora;
	}

}

float calculaValorArrecadado(No* head, float valorArrecadado, int atividadePesquisada, int mesPesquisado, DescricaoAtividade* descricaoAtividade, No* headAux){


	if(head==NULL)
		return;

	if(head->tipoInformacao == ATIVIDADE)
		return calculaValor(headAux, head->informacao, descricaoAtividade, atividadePesquisada, mesPesquisado);

	valorArrecadado+=calculaValorArrecadado(head->filho, valorArrecadado, atividadePesquisada, mesPesquisado, descricaoAtividade, headAux);
	valorArrecadado+=calculaValorArrecadado(head->prox, valorArrecadado, atividadePesquisada, mesPesquisado, descricaoAtividade, headAux);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Mostrar o valor arrecadado em um determinado mes com uma atividade.
	Parâmetro: Cabeça da árvore
	Retorno: 
*/

void valorArrecadadoPorAtividade(No* head, DescricaoAtividade* descricaoAtividade){


	int mesPesquisado, atividadePesquisada;


	printf("Digite a atividade que se deseja calcular o valor arrecadado\n");
	scanf("%d", &atividadePesquisada);

	printf("Digite o mes ao qual se deseja calcular o valor arrecadado pela atividade %d.\n", atividadePesquisada);
	scanf("%d", &mesPesquisado);

	printf("O valor arrecadado pela Atividade %d no mes %d foi: %.2fR$\n",  atividadePesquisada, mesPesquisado, calculaValorArrecadado(head, 0, atividadePesquisada, mesPesquisado, descricaoAtividade, head));

}
