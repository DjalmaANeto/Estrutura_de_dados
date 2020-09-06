//buble sort 1 (de tras pra frente)
//WORKING
#include <stdio.h>
#define n 4
void main(){
	int vet[n], aux, i, j;
	//preenchendo o vetor 
	for(i=0;i<=n;i++){
		printf("Escreva a posicao [%d]: ", i);
		scanf("%d", &vet[i]);
	}
	
	//imprimindo forma atual
	printf("\nVet:");
	for(i=0;i<n;i++){
		printf("%i,",vet[i]);
	}
	printf("%i.",vet[n]);
	
	//cada elemento i sera comparado com a posi��o i-1
	//quando a ordena��o desejada(crescente) � encontrada a troca � feita 
	//quantidade de elementos - 1
	for(j=1; j<=n-1; j++){
		for(i=n-1; i>=j; i--){
			if(vet[i] < vet[i-1]){
				aux = vet[i];
				vet[i] = vet[i-1];
				vet[i-1] = aux;
			}
		}
	}
	
	//imprimindo forma ordenada
	printf("\nForma crescente Vet:");
	for(i=0;i<n;i++){
		printf("%i,",vet[i]);
	}
	printf("%i.",vet[n]);
}

