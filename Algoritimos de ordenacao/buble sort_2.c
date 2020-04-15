//buble sort 2
//WORKING 
#include <stdio.h>
#define n 3
void main()
{
	int vet[n], aux, i, N, troca;
	
	//carregando o vetor 
	for(i=0;i<=n;i++){
		printf("Escreva a posicao [%d]: ", i);
		scanf("%d",&vet[i]);
	}
	
	//imprimindo forma atual
	printf("\nVet:");
	for(i=0;i<n;i++){
		printf("%i,",vet[i]);
	}
	printf("%i.",vet[n]);
	
	//ordenando de forma decrescente
	//laço com a quantidade de elementos do vetor
	//e enqunato houver troca
	N = 1;
	troca = 1;
	while(N<=5 && troca == 1){
		troca = 0;
		for(i=0;i<=n;i++){
			if(vet[i]<vet[i+1]){
				troca = 1;
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
		}
		N = N + 1;
	}
	
	//imprimindo forma ordenada
	printf("\nVet:");
	for(i=0;i<n;i++){
		printf("%i,",vet[i]);
	}
	printf("%i.",vet[n]); 
}
