#include <stdio.h>

#define N 9

int pesquisaLinearRecursiva(int n, int x[], int p);

void main(){
	int x[N], n, i, achou;
	
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i",&x[i]);
	}
	
	printf("Digite o numero a ser buscado: ");
	scanf("%i",&n);
	
	if(pesquisaLinearRecursiva(n, x, N) == -1){
		printf("\nNumero nao encontrado");
	}else{
		printf("\nPosicao encontrada: %i", pesquisaLinearRecursiva(n, x, N));
	}
}

int pesquisaLinearRecursiva(int n, int x[], int p){
	if(p == 0){
		return -1;
	}else{
		if(n == x[p]){
			return p;
		}else{
			pesquisaLinearRecursiva(n, x, p-1);
		}
	}
	
}
