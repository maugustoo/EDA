#include "Validacao.h"

/*
	Responsavel: Augusto Moreno
*/


int validaCodigoAtividade(int codigoAtividade){
	if(codigoAtividade>=0 && codigoAtividade < 7){
		return 1;
	}else{
		return 0;	
	}
}

/*
	Responsavel: Augusto Moreno
*/


int validaInt(int numero){
	if(numero > 0){
		return 1;	
	}else{
		return 0;
	}
}

int validaStatus(char status){
	if(status == 'A' || status == 'F'){
		return 1;
	}else{
		return 0;
	}
}

/*
	Responsavel: Augusto Moreno
*/


int validaPrioridade(char* prioridade){
	if(strcmp(prioridade, "ALTA") == 0 || strcmp(prioridade, "MEDIA") == 0 || strcmp(prioridade, "BAIXA") == 0){
		return 1;
	}else{
		return 0;
	}
}

/*
	Responsavel: Augusto Moreno
*/


int validaDia(int dia){
	if(dia >0 && dia<32){
		return 1;
	}else{
		return 0;	
	}
}

/*
	Responsavel: Augusto Moreno
*/


int validaMes(int mes){
	if(mes>0 && mes < 13){
		return 1;
	}else{
		return 0;
	}
}

/*
	Responsavel: Augusto Moreno
*/


int validaAno(int ano){
	if(ano>2000 && ano<2017){
		return 1;
	}else{
		return 0;
	}
}

/*
	Responsavel: Marcelo Augusto
*/

int validaEstado(char* estado){
	if(strcmp(estado, "AC") == 0 || strcmp(estado, "AL") == 0 || strcmp(estado, "AP") == 0 || strcmp(estado, "AM") == 0 || strcmp(estado, "BA") == 0
	|| strcmp(estado, "CE") == 0 || strcmp(estado, "DF") == 0 || strcmp(estado, "ES") == 0 || strcmp(estado, "GO") == 0 || strcmp(estado, "MA") == 0
	|| strcmp(estado, "MT") == 0 || strcmp(estado, "MS") == 0 || strcmp(estado, "MG") == 0 || strcmp(estado, "PA") == 0 || strcmp(estado, "PB") == 0
	|| strcmp(estado, "PR") == 0 || strcmp(estado, "PE") == 0  || strcmp(estado, "PI") == 0 || strcmp(estado, "RJ") == 0 || strcmp(estado, "RN") == 0
	|| strcmp(estado, "RS") == 0 || strcmp(estado, "RO") == 0 || strcmp(estado, "RR") == 0 || strcmp(estado, "SC") == 0 || strcmp(estado, "SP") == 0
	|| strcmp(estado, "SE") == 0 || strcmp(estado, "TO") == 0){
		return 1;
	}else{
		return 0;
	}
}

/*
	Responsavel: Augusto Moreno
*/

int validaTelefone(char* telefone){
	int i;

	if(strlen(telefone)!=8)
		return 0;
	for(i = 0; i<strlen(telefone); ++i){
		if(!isdigit(telefone[i]))
			return 0;
	}

	return 1;
}
