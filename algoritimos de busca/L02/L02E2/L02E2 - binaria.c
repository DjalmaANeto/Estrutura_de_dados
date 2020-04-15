#include <stdio.h>

#define N 4

void buscaBinaria(int x[], int np, int posicoes[], int busca);

void main(){
	int x[N], np, i, inicio, fim, meio, achou, posicoes[N], busca;
	
	
	//carregando os números no vetor odenados
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i", &x[i]);
	}
	
	//digitando o número para ser buscado no vetor 
	printf("Digite o número a ser buscado: ");
	scanf("%i",&np);
	
	buscaBinaria(x, np, posicoes, busca);
		
}

//busca binaria
void buscaBinaria(int x[], int np, int posicoes[], int busca){
	int achou = 0;
	int inicio = 0;
	int fim = N;
	int meio = (inicio + fim)/2;
	int i = 0;
	
	while(inicio <= fim && achou == 0){
		if(x[meio] == np){
			achou = 1;
			posicoes[i] = meio;
			busca++;
			i++; 
		}
		else{
			if(np < x[meio]){
				fim = meio-1;
			}
			else{
				inicio = meio + 1;
			}
			meio = (inicio + fim)/2;
		}
	}

	if(achou == 0)
		printf("Numero nao encontrado no vetor");
	else
		printf("Numero encontrado nas posicoes ");
		for(i = 0; i < busca; i++){
			printf(" %i,", posicoes[i]);
		}
		printf(" %i vezes",busca);

}
