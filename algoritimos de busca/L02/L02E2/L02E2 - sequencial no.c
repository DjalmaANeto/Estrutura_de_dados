#include <stdio.h>

#define N 4

void buscaSequencialNO(int x[], int n);

void main(){
	int x[N], n, i, achou;
	
	//carregando os n�meros o vetor
	//vetor com n�nmero n�o ordenados 
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i", &x[i]);
	}
	
	//digitando o n�mero a ser buscado no vetor
	printf("Digite o numero a ser buscado: ");
	scanf("%i", &n);
	
	buscaSequencialNO(x, n);
}

//busca sequencial n�o ordenada
void buscaSequencialNO(int x[], int n){
	int achou = 0;
	int i = 0;
	//busca
	while(i <= N && achou == 0){
		if(x[i] == n)
			achou = 1;
		else
			i++;
	}
	if(achou == 0)
		printf("Numero n�o encotrado no vetor");
	else
		printf("Numero encontrado na posicao %i", i);
	
}
