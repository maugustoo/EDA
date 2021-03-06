#include "OrdemDeServico.h"

OrdemServico* alocaMemoriaOrdemServico(OrdemServico* ordemServico){
	ordemServico->descricaoSolicitacao = (char*)malloc(sizeof(char)*50);
	ordemServico->prioridade = (char*)malloc(sizeof(char)*6);

	return ordemServico;
}

/*
 Nome: Augusto Moreno
 O que faz: Percorre a árvore até encontrar um cliente específico;
 Parametro de Entrada: No* head, int codigo;
 Parametro de saida: Cliente encontrado;
*/

No* encontraCliente(No* head, int codigo){

	if(head==NULL){
		printf("Não existe cliente cadastrado com esse codigo\n");
		return NULL;
	}
	else if(head->tipoInformacao == CLIENTE && comparaCodigo(codigo, (Cliente*)head->informacao)){
		return head;
	}
	
	return encontraCliente(head->prox, codigo);
}

/*
 Nome: Augusto Moreno
 O que faz: Lê os dados de uma Ordem de Serviço;
 Parametro de Entrada: OrdemServico* ordemServico, No* head;
 Parametro de saida: Cliente encontrado, ordem de serviço;
*/

No* lerOrdemServico(OrdemServico* ordemServico, No* head){
	int codigo;
	No* clienteEncontrado = (No*)malloc(sizeof(No));
    
	ordemServico = alocaMemoriaOrdemServico(ordemServico);

	printf("Digite o codigo do Cliente: \n");
	scanf("%d",&codigo);
	
	clienteEncontrado = encontraCliente(head, codigo);

	if(clienteEncontrado == NULL){
		printf("Nao existe cliente com este codigo!\n");
		return NULL;
	}

	ordemServico->codigoCliente = codigo;

	printf("Digite o código da Ordem de Servico: \n");
	scanf("%d",&ordemServico->codigoOrdemServico);

	printf("Digite a descricao da Solicitacao: \n");
	lerString(ordemServico->descricaoSolicitacao,49);

	do{
		printf("Digite a prioridade: (ALTA, MEDIA ou BAIXA)\n");
		lerString(ordemServico->prioridade,50);

		if(!validaPrioridade(ordemServico->prioridade))
			printf("\n\n*****PRIORIDADE INVALIDA! Digite novamente!*****\n");

	}while(!validaPrioridade(ordemServico->prioridade));

	do{
		printf("Digite a o dia da solicitacao: \n");
		scanf("%d",&ordemServico->dataSolicitacao.dia);

		if(!validaDia(ordemServico->dataSolicitacao.dia))
			printf("\n\n*****DIA INVALIDO! Digite novamente!*****\n");
	}while(!validaDia(ordemServico->dataSolicitacao.dia));

	do{
		printf("Digite o mes da solicitacao: \n");
		scanf("%d",&ordemServico->dataSolicitacao.mes);

		if(!validaMes(ordemServico->dataSolicitacao.mes))
			printf("\n\n*****MES INVALIDO! Digite novamente!*****\n");
	}while(!validaMes(ordemServico->dataSolicitacao.mes));

	do{
		printf("Digite o ano da solicitacao: \n");
		scanf("%d",&ordemServico->dataSolicitacao.ano);

		if(!validaAno(ordemServico->dataSolicitacao.ano))
			printf("\n\n*****ANO INVALIDO! Digite novamente!*****\n");
	}while(!validaAno(ordemServico->dataSolicitacao.ano));
	
	getchar();

	do{
		printf("Digite o status da OS:\nA=Aberta\nF=Fechada\n");
		scanf("%c", &ordemServico->status);

		if(!validaStatus(ordemServico->status)){
			printf("\n\n*****STATUS INVALIDO! Digite novamente!*****\n");
			getchar();
		}

	}while(!validaStatus(ordemServico->status));

	return clienteEncontrado;
}

/*
 Nome: Augusto Moreno
 O que faz: Insere uma ordem de serviço na árvore;
 Parametro de Entrada: No* head;
 Parametro de saida: Ordem de serviço inserida na árvore;
*/

void cadastraOs(No* head){
    
	OrdemServico *ordemServico = (OrdemServico*)malloc(sizeof(OrdemServico));

	No* clienteDasOrdi = lerOrdemServico(ordemServico, head);
	No* novaOrdemServico = (No*)malloc(sizeof(No));

	if(clienteDasOrdi == NULL)
		return;

	novaOrdemServico->tipoInformacao = OS;
	novaOrdemServico->informacao = ordemServico;
	novaOrdemServico->filho = NULL;

	printf("\33[H\33[2J");
	printf("Ordem de servico cadastrada com sucesso!\n");

	if(clienteDasOrdi->filho == NULL){
		clienteDasOrdi->filho = novaOrdemServico;
		novaOrdemServico->prox = NULL;
	}else{
		novaOrdemServico->prox = clienteDasOrdi->filho;
		clienteDasOrdi->filho = novaOrdemServico;
	}
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Comparar o codigo passado com o codigo de uma Ordem de serviço
	Parâmetro: Codigo, Ordem de serviço
	Retorno: 1 se o codigo for igual ao codigo da ordem de serviço, 0 caso caso contrário
*/

int comparaCodigoOs(int codigo, OrdemServico *ordemServico){
	return codigo == ordemServico->codigoOrdemServico;
}

/*
	Responsavel: Augusto Moreno
	Objetivo: Consultar se um codigo pertece a alguma Ordem de serviço
	Parâmetro: Codigo, Cabeça da lista de Ordens de serviço
	Retorno: A ordem de serviço referente ao código
*/

No* encontraOs(No* headListaOs, int codigoOs){

	if(headListaOs==NULL){
		printf("Nao existe Ordem de Servico cadastrada com esse codigo.\n");
		return NULL;
	}
	else if(headListaOs->tipoInformacao == OS && comparaCodigoOs(codigoOs, (OrdemServico*)headListaOs->informacao)){
		return headListaOs;
	}
	
	return encontraOs(headListaOs->prox, codigoOs);
}

/*
	Responsavel:Augusto Morneo
	Objetivo: Função para verificar se uma ordem de serviço está aberta
	Parâmetro: Ordem de serviço
	Retorno: 1 caso a ordem de serviço esteja aberta, 0 caso contrário
*/


int ordemServicoAberta(OrdemServico* ordemServico){
		return ordemServico->status == 'A';
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Consultar se um codigo pertece a alguma Ordem de serviço
	Parâmetro: Codigo, Cabeça da lista de Ordens de serviço
	Retorno: A ordem de serviço referente ao código
*/

No* consultarOs(No* headListaOs, int codigoOs){

	if(headListaOs==NULL)
		return NULL;
	else if(headListaOs->tipoInformacao == OS && comparaCodigoOs(codigoOs, (OrdemServico*)headListaOs->informacao)){
		imprimirOS(headListaOs->informacao);
		return headListaOs;
	}
	consultarOs(headListaOs->prox, codigoOs);
}

/*
 Nome: Augusto Moreno
 O que faz: Lê os dados de uma Ordem de Serviço;
 Parametro de Entrada: OrdemServico* ordemServico, No* head;
 Parametro de saida: Cliente encontrado, ordem de serviço;
*/

OrdemServico* lerAlteracaoOrdemServico(OrdemServico* ordemServico){


	printf("Descricao antiga: %s\n", ordemServico->descricaoSolicitacao);
	printf("Digite a nova descricao da Solicitacao\n");
	lerString(ordemServico->descricaoSolicitacao,49);

	printf("Prioridade registrada: %s\n", ordemServico->prioridade);

	do{
		printf("\nDigite a nova prioridade: (ALTA, MEDIA ou BAIXA)\n");
		lerString(ordemServico->prioridade,50);

		if(!validaPrioridade(ordemServico->prioridade))
			printf("\n\n*****PRIORIDADE INVALIDA! Digite novamente!*****\n");

	}while(!validaPrioridade(ordemServico->prioridade));

	printf("Dia de abertura da ordem de servico registrado: %d\n", ordemServico->dataSolicitacao.dia);

	do{
		printf("\nDigite a o dia da solicitacao: \n");
		scanf("%d",&ordemServico->dataSolicitacao.dia);

		if(!validaDia(ordemServico->dataSolicitacao.dia))
			printf("\n\n*****DIA INVALIDO! Digite novamente!*****\n");
	}while(!validaDia(ordemServico->dataSolicitacao.dia));

	printf("Mes de abertura da ordem de servico registrado: %d\n", ordemServico->dataSolicitacao.mes);

	do{
		printf("\nDigite o mes da solicitacao: \n");
		scanf("%d",&ordemServico->dataSolicitacao.mes);

		if(!validaMes(ordemServico->dataSolicitacao.mes))
			printf("\n\n*****MES INVALIDO! Digite novamente!*****\n");
	}while(!validaMes(ordemServico->dataSolicitacao.mes));

	printf("Ano de abertura da ordem de servico registrado: %d\n", ordemServico->dataSolicitacao.ano);

	do{
		printf("\nDigite o ano da solicitacao: \n");
		scanf("%d",&ordemServico->dataSolicitacao.ano);

		if(!validaAno(ordemServico->dataSolicitacao.ano))
			printf("\n\n*****ANO INVALIDO! Digite novamente!*****\n");
	}while(!validaAno(ordemServico->dataSolicitacao.ano));
	
	getchar();
	printf("Status registrado da Ordem de Servico: %s\n", (ordemServico->status == 'A') ? "Aberta" : "Fechada");
	do{
		printf("\nDigite o status da OS:\nA=Aberta\nF=Fechada\n");
		scanf("%c", &ordemServico->status);

		if(!validaStatus(ordemServico->status)){
			printf("\n\n*****STATUS INVALIDO! Digite novamente!*****\n");
			getchar();
		}

	}while(!validaStatus(ordemServico->status));

	return ordemServico;
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Alteração de uma ordem de serviço
	Parâmetro: Codigo, Cabeça da lista de Ordens de serviço
	Retorno: 
*/

void alterarOs(No* headListaOs, int codigoOs){

	No* ordemServico = consultarOs(headListaOs, codigoOs);	
	ordemServico->informacao = lerAlteracaoOrdemServico(ordemServico->informacao);
}

/*
	Responsavel: Marcelo Augusto
	Objetivo: Exclusão de uma ordem de serviço
	Parâmetro: Codigo da ordem de serviço, cabeça da lista de ordem de serviço
	Retorno: Nova cabeça da lista de ordem de serviços
*/


No* excluirOs(No* headOs, int codigoOs){

	No *auxiliar = headOs, *auxiliarAnt = NULL;

	while(auxiliar!=NULL && !comparaCodigoOs(codigoOs, auxiliar->informacao)){
		auxiliarAnt = auxiliar;
		auxiliar = auxiliar->prox;
	}
	if(auxiliar==NULL){
		printf("O codigo %d nao e referente a nenhuma Ordem de Servico!\n", codigoOs);

	}else if(auxiliarAnt == NULL){
		if(auxiliar->filho == NULL){
			headOs = auxiliar->prox;
			free(auxiliar);
			printf("\33[H\33[2J");
			printf("Ordem de servico excluida com sucesso\n");
		}else{
			printf("Nao foi possivel excluir a Ordem de servico do codigo %d. Pois o mesmo tem atividades ligadas a ele.\n", codigoOs);
		}

	}else if(comparaCodigoOs(codigoOs, auxiliar->informacao)){
		if(auxiliar->filho == NULL){
			auxiliarAnt->prox = auxiliar->prox;
			free(auxiliar);
			printf("\33[H\33[2J");
			printf("Ordem de servico excluida com sucesso\n");
		}else{
			printf("Nao foi possivel excluir o cliente do codigo %d. Pois o mesmo tem atividades ligadas a ele.\n", codigoOs);	
		}
	}
	return headOs;
}
