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
	//la�o da 1� a penultima posi��o elegendo um n�mero para comparar 
	for(i=0; i<=n-1; i++){
		eleito = vet[i];
		menor = vet[i+1];
		pos = i + 1;
	
		//la�o com os numeros a direita do eleito, 
		//retornando o menor n�mero a direita e sua posi��o	
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

