#ifndef ORDEMDESERVICO_H
#define ORDEMDESERVICO_H

#include "structsModelo.h"
#include "Cliente.h"

OrdemServico* alocaMemoriaOrdemServico(OrdemServico*);
No* encontraCliente(No*, int);
No* lerOrdemServico(OrdemServico*, No*);
void cadastraOs(No*);
int comparaCodigoOs(int, OrdemServico*);
No* encontraOs(No*, int);
int ordemServicoAberta(OrdemServico* ordemServico);
No* consultarOs(No*, int);
OrdemServico* lerAlteracaoOrdemServico(OrdemServico*);
void alterarOs(No*, int);
void pesquisaMesOs(No*, int, int*);
No* excluirOs(No*, int);

#endif
