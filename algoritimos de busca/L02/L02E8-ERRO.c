#include <stdio.h>

#define L 500
#define C 50

void main(){
	int x[L][C], j, i, np;
	
	//preechendo o vetor
	for(i = 0; i <= L; i++){
		for(j = 0; j <= C; j++){
			x[i][j] = 1 + rand() % 10000;
		}
	}
	
	//sorteando um número
	np = 1 + rand() % 10000;
	
//	//convertendo matriz em vetor
//	int aux[L*C], k = 0;
//	for(i = 0; i <= L; i++){
//		for(j = 0; j <= C; j++){
//			aux[k] = x[i][j];
//			k++;
//		}
//	}
	
	int achou = 0;
	int linicio = 0;
	int cinicio = 0;
	int lfim = L;
	int cfim = C;
	int lmeio = (linicio + lfim)/2;
	int cmeio = (cinicio + cfim)/2;
		
	while(linicio <= lfim && cinicio <= cfim && achou == 0){
		if(x[lmeio][cmeio] == np){
			achou = +1;
		}else{
			if(np < x[lmeio][cmeio]){
				cfim = cmeio-1;
				lfim = lmeio-1;
			}
			else{
				linicio = lmeio + 1;
				cinicio = cmeio + 1;
			}
			lmeio = (linicio + lfim)/2;
			cmeio = (cinicio + lfim)/2;
		}
	}
	
	if(achou == 0)
		printf("Numero nao encontrado no vetor");
	else{
		printf("Numero encontrado %i vezes nas posicoes %i ", achou);
		
	}
}
