#include "../inc/OrdemDeServico.h"

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

No* consultarCliente(No* head, int codigo){

	if(head==NULL){
		printf("Não existe cliente cadastrado com esse codigo\n");
		return NULL;
	}
	else if(head->tipoInformacao == CLIENTE && comparaCodigo(codigo,
		(Cliente*)head->informacao)){
		return head;
	}

	return consultarCliente(head->prox, codigo);
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

	printf("Digite o codigo do Cliente\n");
	scanf("%d",&codigo);

	clienteEncontrado = consultarCliente(head, codigo);

	if(clienteEncontrado == NULL){
		printf("Nao existe cliente com este codigo!\n");
		return NULL;
	}

	ordemServico->codigoCliente = codigo;
	printf("Digite o código da Ordem de Servico\n");
	scanf("%d",&ordemServico->codigoOrdemServico);
	printf("Digite a descricao da Solicitacao\n");
	lerString(ordemServico->descricaoSolicitacao,49);
	printf("Digite a prioridade\n");
	lerString(ordemServico->prioridade,5);
	printf("Digite a o dia da solicitacao\n");
	scanf("%d",&ordemServico->dataSolicitacao.dia);
	printf("Digite o mes da solicitacao\n");
	scanf("%d",&ordemServico->dataSolicitacao.mes);
	printf("Digite o ano da solicitacao\n");
	scanf("%d",&ordemServico->dataSolicitacao.ano);
	getchar();
	printf("Digite o status da OS:\nA=Aberta\nF=Fechada\n");
	scanf("%c", &ordemServico->status);

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
		printf("Nao existe OS cadastrada com esse codigo\n");
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
	} else {
			consultarOs(headListaOs->prox, codigoOs);
	}
	return NULL;
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
	printf("Digite a nova prioridade\n");
	lerString(ordemServico->prioridade,5);

	printf("Dia de abertura da ordem de servico registrado: %d\n", ordemServico->dataSolicitacao.dia);
	printf("Digite o dia da solicitacao\n");
	scanf("%d",&ordemServico->dataSolicitacao.dia);


	printf("Mes de abertura da ordem de servico registrado: %d\n", ordemServico->dataSolicitacao.mes);
	printf("Digite o mes da solicitacao\n");
	scanf("%d",&ordemServico->dataSolicitacao.mes);

	printf("Ano de abertura da ordem de servico registrado: %d\n", ordemServico->dataSolicitacao.ano);
	printf("Digite o ano da solicitacao\n");
	scanf("%d",&ordemServico->dataSolicitacao.ano);

	getchar();
	printf("Status registrado da Ordem de Servico: %s\n", (ordemServico->status == 'A') ? "Aberta" : "Fechada");
	printf("Digite o novo status da OS:\nA=Aberta\nF=Fechada\n");
	scanf("%c", &ordemServico->status);

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
		printf("mes OS %d\n", mesOs(head->informacao));
		mes[0] = mesOs(head->informacao);
	}
	pesquisaMesOs(head->filho, codigoOs, mes);
	pesquisaMesOs(head->prox, codigoOs, mes);
}

void imprimirOS(OrdemServico* ordemServico){
	printf("Codigo cliente: %d\n", ordemServico->codigoCliente);
	printf("Codigo OS: %d\n", ordemServico->codigoOrdemServico);
	printf("Descricao: %s\n", ordemServico->descricaoSolicitacao);
	printf("Prioridade: %s\n", ordemServico->prioridade);
	printf("Data: %d/%d/%d\n", ordemServico->dataSolicitacao.dia, ordemServico->dataSolicitacao.mes, ordemServico->dataSolicitacao.ano);
	printf("Status: %c\n", ordemServico->status);
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
		}else{
			printf("Nao foi possivel excluir o cliente do codigo %d. Pois o mesmo tem atividades ligadas a ele.\n", codigoOs);
		}

	}else if(comparaCodigoOs(codigoOs, auxiliar->informacao)){
		if(auxiliar->filho == NULL){
			auxiliarAnt->prox = auxiliar->prox;
			free(auxiliar);
		}else{
			printf("Nao foi possivel excluir o cliente do codigo %d. Pois o mesmo tem atividades ligadas a ele.\n", codigoOs);
		}
	}
	return headOs;
}