#include <stdio.h>
#define n 10

void main(){
	int vet[n], aux;
	int maior;
	int menor;
	int cont;
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
	
	//verificando o menor valor 
	menor = vet[0];
	for(i = 1; i < n; i++){
		if(vet[i] < menor)
			menor = vet[i];
	}
	//quantas vezes o menor valor aparece
	cont = 0;
	for(i = 0; i < n; i++){
		if(vet[i] == menor)
			cont++;
	}
	//imprimindo maior valor e sua recorrencia
	printf("\nO menor valor e %i, aparecendo %i vezes.", menor, cont);
	
	//verificando o maior valor
	maior = vet[0];
	for(i = 1; i < n; i++){
		if(vet[i] > maior)
			maior = vet[i];
	}
	//quantas vezes o maior valor aparece
	cont = 0;
	for(i = 0; i < n; i++){
		if(vet[i] == maior)
			cont++;
	}
	//imprimindo maior valor e sua recorrencia
	printf("\nO maior valor e %i, aparecendo %i vezes.", maior, cont);
}
