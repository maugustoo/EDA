#include <stdio.h>

void salvarCliente(Cliente* cliente, int tipoInformacao){

	FILE* arquivo;

	arquivo = fopen("BancoDados.txt", "a+");

	if(!arquivo){
		printf("\n\t\t*** Houve um erro ao abrir o arquivo, o programa sera fechado! ***");
		getchar();
		exit(0);
	}else{
		fprintf(arquivo, "%d\n", tipoInformacao);
		fprintf(arquivo, "%s\n", cliente->nome);
		fprintf(arquivo, "%d\n", cliente->codigo);
		fprintf(arquivo, "%s\n", cliente->endereco);
		fprintf(arquivo, "%s\n", cliente->bairro);
		fprintf(arquivo, "%s\n", cliente->cep);
		fprintf(arquivo, "%s\n", cliente->cidade);
		fprintf(arquivo, "%s\n", cliente->estado);
		fprintf(arquivo, "%s\n", cliente->telefone);
	}
	fclose(arquivo);
}

void salvarOs(OrdemServico* ordemServico, int tipoInformacao){

	FILE* arquivo;

	arquivo = fopen("BancoDados.txt", "a+");

	if(!arquivo){
		printf("\n\t\t*** Houve um erro ao abrir o arquivo, o programa sera fechado! ***");
		getchar();
		exit(0);
	}else{
		fprintf(arquivo, "%d\n", tipoInformacao);
		fprintf(arquivo, "%d\n", ordemServico->codigoCliente);
		fprintf(arquivo, "%d\n", ordemServico->codigoOrdemServico);
		fprintf(arquivo, "%s\n", ordemServico->descricaoSolicitacao);
		fprintf(arquivo, "%s\n", ordemServico->prioridade);
		fprintf(arquivo, "%d\n", ordemServico->dataSolicitacao.dia);
		fprintf(arquivo, "%d\n", ordemServico->dataSolicitacao.mes);
		fprintf(arquivo, "%d\n", ordemServico->dataSolicitacao.ano);
		fprintf(arquivo, "%c\n", ordemServico->status);
	}
	fclose(arquivo);
}

void salvarAtividade(Atividade* atividade, int tipoInformacao){

	FILE* arquivo;

	arquivo = fopen("BancoDados.txt", "a+");

	if(!arquivo){
		printf("\n\t\t*** Houve um erro ao abrir o arquivo, o programa sera fechado! ***");
		getchar();
		exit(0);
	}else{
		fprintf(arquivo, "%d\n", tipoInformacao);
		fprintf(arquivo, "%d\n", atividade->codigoCliente);
		fprintf(arquivo, "%d\n", atividade->codigoOs);
		fprintf(arquivo, "%d\n", atividade->codigoAtividade);
		fprintf(arquivo, "%d\n", atividade->qtdHorasGastas);
	}
	fclose(arquivo);
}

void salvarDadosArquivo(No* head){

	if(head == NULL)
		return;
	
	if(head->tipoInformacao == CLIENTE)
		salvarCliente(head->informacao, head->tipoInformacao);
	if(head->tipoInformacao == OS)
		salvarOs(head->informacao, head->tipoInformacao);
	if(head->tipoInformacao == ATIVIDADE)
		salvarAtividade(head->informacao, head->tipoInformacao);
	
	salvarDadosArquivo(head->filho);
	salvarDadosArquivo(head->prox);
}

void cadastraOsArquivo(No* head, OrdemServico* ordemServico){

	No* clienteEncontrado = (No*)malloc(sizeof(No));

	clienteEncontrado = encontraCliente(head, ordemServico->codigoCliente);

	No* novaOrdemServico = (No*)malloc(sizeof(No));

	if(clienteEncontrado == NULL)
		return;

	novaOrdemServico->tipoInformacao = OS;
	novaOrdemServico->informacao = ordemServico;
	novaOrdemServico->filho = NULL;

	if(clienteEncontrado->filho == NULL){
		clienteEncontrado->filho = novaOrdemServico;
		novaOrdemServico->prox = NULL;
	}else{
		novaOrdemServico->prox = clienteEncontrado->filho;
		clienteEncontrado->filho = novaOrdemServico;
	}
}

void cadastraAtividadeArquivo(No* head, Atividade* atividade){

	No* clienteEncontrado;
    	No* ordemServico;
	No* novaAtividade;
	
	novaAtividade = (No*)malloc(sizeof(No));

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

void lerDados(No* head){
	
	FILE* arquivo;
	Cliente* cliente;
	OrdemServico* ordemServico;
	Atividade* atividade;

	char linhaArquivo[50];
	if((arquivo = fopen("BancoDados.txt", "r")) == NULL){
		printf("\n\t\t*** Houve um erro ao abrir o arquivo, o programa sera fechado! ***");
		getchar();
		return;
	}
					
	while(fgets(linhaArquivo, sizeof linhaArquivo, arquivo)){
		switch(atoi(linhaArquivo)){
			case 0:
				cliente = (Cliente*)malloc(sizeof(Cliente));
				alocaMemoriaCliente(cliente);

				fgets(cliente->nome, sizeof linhaArquivo, arquivo);
				cliente->nome[strlen(cliente->nome)-1] = 0;
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				cliente->codigo = atoi(linhaArquivo);
				fgets(cliente->endereco, sizeof linhaArquivo, arquivo);
				cliente->endereco[strlen(cliente->endereco)-1] = 0;
				fgets(cliente->bairro, sizeof linhaArquivo, arquivo);
				cliente->bairro[strlen(cliente->bairro)-1] = 0;
				fgets(cliente->cep, sizeof linhaArquivo, arquivo);
				cliente->cep[strlen(cliente->cep)-1] = 0;
				fgets(cliente->cidade, sizeof linhaArquivo, arquivo);
				cliente->cidade[strlen(cliente->cidade)-1] = 0;
				fgets(cliente->estado, sizeof linhaArquivo, arquivo);
				cliente->estado[strlen(cliente->estado)-1] = 0;
				fgets(cliente->telefone, sizeof linhaArquivo, arquivo);
				cliente->telefone[strlen(cliente->telefone)-1] = 0;

				head = insercaoCliente(head, cliente);
				break;
			case 1:
				ordemServico = (OrdemServico*)malloc(sizeof(OrdemServico));
				alocaMemoriaOrdemServico(ordemServico);

				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				ordemServico->codigoCliente = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				ordemServico->codigoOrdemServico = atoi(linhaArquivo);
				fgets(ordemServico->descricaoSolicitacao, sizeof linhaArquivo, arquivo);
				ordemServico->descricaoSolicitacao[strlen(ordemServico->descricaoSolicitacao)-1] = 0;
				fgets(ordemServico->prioridade, sizeof linhaArquivo, arquivo);
				ordemServico->prioridade[strlen(ordemServico->prioridade)-1] = 0;
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				ordemServico->dataSolicitacao.dia = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				ordemServico->dataSolicitacao.mes = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				ordemServico->dataSolicitacao.ano = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				ordemServico->status = linhaArquivo[0];

				cadastraOsArquivo(head->filho, ordemServico);
				break;
			case 2:
				atividade = (Atividade*)malloc(sizeof(Atividade));

				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				atividade->codigoCliente = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				atividade->codigoOs = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				atividade->codigoAtividade = atoi(linhaArquivo);
				fgets(linhaArquivo, sizeof linhaArquivo, arquivo);
				atividade->qtdHorasGastas = atoi(linhaArquivo);

				cadastraAtividadeArquivo(head, atividade);
		}
	}
}
