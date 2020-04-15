//Selection sort
//WORKING 
#include <stdio.h>
#define n 4

void main(){
	int vet[n];
	int i, j, eleito, menor, pos;
	
	//preenchendo o vetor
	for(i=0;i<=n;i++){
		printf("Insira vet[%d]: ",i);
		scanf("%d",&vet[i]);
	} 
	
	//imprimindo forma atual
	printf("\nForma atual: ");
	for(i=0;i<n;i++){
		printf("%d, ",vet[i]);
	} 
	printf("%d.",vet[n]);
	
	//ordenando de forma crescente 
	//laço da 1ª a penultima posição elegendo um número para comparar 
	for(i=0; i<=n-1; i++){
		eleito = vet[i];
		menor = vet[i+1];
		pos = i + 1;
	
		//laço com os numeros a direita do eleito, 
		//retornando o menor número a direita e sua posição	
		for(j=i+1; j<=n; j++){
			if(vet[j] < menor){
				menor = vet[j];
				pos = j;
			}
		}
		
		//troca
		if(menor < eleito){
			vet[i] = vet[pos];
			vet[pos] = eleito;
		}
	}
	
	//imprimindo forma ordenada
	printf("\nForma ordenada: ");
	for(i=0;i<n;i++){
		printf("%d, ",vet[i]);
	} 
	printf("%d.",vet[n]);
}

