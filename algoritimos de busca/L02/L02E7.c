#include <stdio.h>

#define N 9

int pesquisaBinariaRecursiva(int np, int x[], int esq, int dir);

void main(){
	int x[N], np, i, inicio, fim, meio, achou;
	
	//carregando os números no vetor odenados
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i", &x[i]);
	}
	
	//digitando o número para ser buscado no vetor 
	printf("Digite o numero a ser buscado: ");
	scanf("%i",&np);
	
	//buscando o número digitado no vetor
	achou = 0;
	inicio = 0;
	fim = N;
	meio = (inicio + fim)/2;

	int k = pesquisaBinariaRecursiva(np, x, -1, N);
	if(k == -1){
		printf("\nValor nao encontrado");
	}else{
		printf("\nPosicao encontrada %i", k);
	}
}

int pesquisaBinariaRecursiva(int np, int x[], int esq, int dir){
	int meio;
	
	if(esq == dir - 1){
		return -1;
	}else{
		meio = (esq + dir)/2;
		if(x[meio] < np){
			return pesquisaBinariaRecursiva(np, x, meio, dir);
		}else{
			return pesquisaBinariaRecursiva(np, x, esq, meio);
		}
	}
}
