//insertion sort
//	WORKING
#include <stdio.h>
#define n 3
void main(){
	int vet[n];
	int i, j, eleito;
	
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
	//laço com a quantidade de elementos -1
	for(i=1;i<=n;i++){
		eleito = vet[i];
		j = i - 1;
		//laço percorre os elementos a esquerda de eleito
		//ou até encontrar a posição para recolocação do
		//numero eleito respeitando a ordenação procurada
		while(j >= 0 && vet[j] > eleito){
			vet[j+1] = vet[j];
			j = j - 1;
		}
		vet[j+1] = eleito;
	}
	
	//imprimindo forma ordenada
	printf("\nForma atual: ");
	for(i=0;i<n;i++){
		printf("%d, ",vet[i]);
	} 
	printf("%d.",vet[n]);
	
} 
