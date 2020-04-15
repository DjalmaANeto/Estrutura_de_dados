//Buble sort 0
//WORKING
#include <stdio.h>
#define n 4
void main(){
	int vet[n], aux;
	//cada elemento da posição i sera comparada com a posição i+1
	//se o elemento i for maior que i+1, troca-se os elementos
	int i, N;
	//carregando o vetor 
	for(i=0;i<=n;i++){
		printf("Escreva a posicao [%d]: ", i);
		scanf("%d",&vet[i]);
	}
	
	//imprimindo forma atual
	printf("\nVet:");
	for(i=0;i<n;i++){
		printf("%d,",vet[i]);
	}
	printf("%d.",vet[n]);
	
	//ordenando o vetor de forma crescente
	//laço com a quantidade de elemtos do vetor
	for(N=1;N<=n;N++){
		//laço da 1ª a penultima posição 
		for(i=0;i<n-1;i++){
			if(vet[i] > vet[i+1]){
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
		}
	}
	
	//imprimindo forma ordenada crescente
	printf("\nVet:");
	for(i=0;i<n;i++){
		printf("%i,",vet[i]);
	}
	printf("%i.",vet[n]);
}
