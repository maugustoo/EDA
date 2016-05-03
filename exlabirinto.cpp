#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define MAX 100
#define N 7
#define LIVRE 0
#define PAREDE 32767
#define X -1

typedef int titem;

using namespace std;

typedef struct _triplet triplet;

struct _triplet{

	int i;
	int j;
	int distance;

};

void cria(int L[N][N]){
	int i, j;
	for(i=0; i<N; ++i){
		L[i][0] = PAREDE;
		L[i][N-1] = PAREDE;
	}
	for(j=0; j<N; ++j){
		L[0][j] = PAREDE;
		L[N-1][j] = PAREDE;
	}
	for(i=1; i<N-1; ++i){
		for(j=1; j<N-1; ++j){
			if(rand()%3==0) 
				L[i][j] = PAREDE;
			else
				L[i][j] = LIVRE;
		}
	}
	L[1][1] = LIVRE;
	L[N-2][N-2] = LIVRE;
}

void exibe(int L[N][N]){
	int i, j;
	for(i=0; i<N; ++i){
		for(j=0; j<N; ++j){
			switch(L[i][j]){
				case LIVRE:
					putchar(' ');
					break;
				case PAREDE:
					putchar('#');
					break;
				case X:
					putchar('x');
					break;
				default:
					printf(" ");
			}
		}
		printf("\n");
	}
}

void anota(int matriz[N][N]){
	int j, i, di, auxi, auxj;
	int ini, fim;
	triplet fila[N*N];

	matriz[1][1] = 1;
	ini=0; fim=0;
	fila[fim].i = 1; fila[fim].j = 1; fila[fim++].distance = 1;
	
	while(ini!=fim){

		auxi = fila[ini].i;
		auxj = fila[ini].j;
		di = fila[ini++].distance;
		
		if(matriz[auxi][auxj+1]==LIVRE){
			matriz[auxi][auxj+1]=di+1;
			fila[fim].i = auxi; fila[fim].j = auxj+1; fila[fim++].distance = matriz[auxi][auxj+1];
		}
		if(matriz[auxi][auxj-1]==LIVRE){
			matriz[auxi][auxj-1]=di+1;
			fila[fim].i = auxi; fila[fim].j = auxj-1; fila[fim++].distance = matriz[auxi][auxj-1];
		}
		if(matriz[auxi+1][auxj]==LIVRE){
			matriz[auxi+1][auxj]=di+1;
			fila[fim].i = auxi+1; fila[fim].j = auxj; fila[fim++].distance = matriz[auxi+1][auxj];
		}
		if(matriz[auxi-1][auxj]==LIVRE){
			matriz[auxi-1][auxj]=di+1;
			fila[fim].i = auxi-1; fila[fim].j = auxj; fila[fim++].distance = matriz[auxi-1][auxj];
		}
	}
}

void extrai(int matriz[N][N]){
	
	triplet pilha[N*N];

	int topo = 0;

	if(matriz[N-2][N-2] == LIVRE)
		printf("O labirinto não tem saida\n\n\n\n");

	else{
		pilha[topo].i = N-2; pilha[topo++].j = N-2;

		while(pilha[topo-1].i != 1 || pilha[topo-1].j!=1){
			int auxi = pilha[topo-1].i, auxj = pilha[topo-1].j;

			if(matriz[auxi][auxj+1] == matriz[auxi][auxj]-1){
				pilha[topo].i = auxi; pilha[topo++].j = auxj+1;
			}
			else if(matriz[auxi][auxj-1] == matriz[auxi][auxj]-1){
				pilha[topo].i = auxi; pilha[topo++].j = auxj-1;
			}
			else if(matriz[auxi+1][auxj] == matriz[auxi][auxj]-1){
				pilha[topo].i = auxi+1; pilha[topo++].j = auxj;
			}
			else if(matriz[auxi-1][auxj] == matriz[auxi][auxj]-1){
				pilha[topo].i = auxi-1; pilha[topo++].j = auxj;
			}
		}
		while(topo!=0){
			matriz[pilha[--topo].i][pilha[topo].j] = X;
		}
	}
	exibe(matriz);
}

int main(){
	int L[N][N];
	char r;
	srand(time(NULL));
	do{
		cria(L);
		anota(L);
		extrai(L);
		printf("\n\n\nContinuar? (s/n)");
		scanf("%c%*c", &r);
	}while(toupper(r)!='N');
	return 0;
}
