//WORKING

#include <stdio.h>

#define N 9

void main(){
	int x[N], np, i, inicio, fim, meio, achou;
	
	//carregando os números no vetor odenados
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i", &x[i]);
	}
	
	//digitando o número para ser buscado no vetor 
	printf("Digite o número a ser buscado: ");
	scanf("%i",&np);
	
	//buscando o número digitado no vetor
	achou = 0;
	inicio = 0;
	fim = N;
	meio = (inicio + fim)/2;
	
	while(inicio <= fim && achou == 0){
		if(x[meio] == np)
			achou = 1;
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
		printf("Numero encontrado na posicao %i", meio);
}
