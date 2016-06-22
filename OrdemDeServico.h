#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função para percorrer a arvore e achar o cliente específico

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

//Função para ler os dados da Ordem de Serviço

No* lerOrdemServico(OrdemServico* ordemServico, No* head){
    int codigo;
    No* clienteEncontrado = (No*)malloc(sizeof(No));
    
    ordemServico = alocaMemoriaOrdemServico(ordemServico);

    do{  
        printf("Digite o codigo do Cliente\n");
        scanf("%d",&codigo);
        
        clienteEncontrado = encontraCliente(head, codigo);
        
    }while(clienteEncontrado == NULL);
    
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

//Função para cadastrar Ordem de Serviço
void cadastraOs(No* head){
    
    OrdemServico *ordemServico = (OrdemServico*)malloc(sizeof(OrdemServico));

    No* clienteDasOrdi = lerOrdemServico(ordemServico, head);
    No* novaOrdemServico = (No*)malloc(sizeof(No));
    
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