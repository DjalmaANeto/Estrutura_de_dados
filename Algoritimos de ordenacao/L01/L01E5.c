#include <stdio.h>
#include <stdlib.h>

#define n 16

void main(){
	int vet[n];
	int op;
	int i, j, eleito, menor, pos;
	
	//inserindo elementos no vetor vet
	if( n == 16){
		for(i = 0; i <= n; i++){
			vet[i] = rand() % 16;
		}
	}else{	
		for(i = 0; i <= n; i++){
			printf("Escreva vet[%i]: ", i);
			scanf("%i",&vet[i]);
		}	
	}
	
	//imprimindo vetor atual
	for(i = 0; i <= n; i++){
		printf("  %i", vet[i]);
	}
	
	do{
		printf("\n\n1 -- Insertion sort crescente.\n");
		printf("2 -- Selection sort decrescente.\n");
		printf("0 -- para sair\n");
		scanf("%i", &op);
		
		switch(op){
			case 0:
				printf("\nEncerrendo.");
			break;
			
			case 1:
				//insertion sort ordenando de forma crescente 
				//la�o com a quantidade de elementos -1
				for(i = 1; i <= n; i++){
					eleito = vet[i];
					j = i - 1;
					//la�o percorre os elementos a esquerda de eleito
					//ou at� encontrar a posi��o para recoloca��o do
					//numero eleito respeitando a ordena��o procurada
					while(j >= 0 && vet[j] > eleito){
						vet[j+1] = vet[j];
						j = j - 1;
					}
					vet[j+1] = eleito;
				}
				
				//imprimindo vetor ordenado
				printf("\nInsertion sort crescente:");
				for(i = 0; i <= n; i++){
					printf("  %i", vet[i]);
				}
			break;
			
			case 2:
				//selection sort decrescente ordenando 
				//la�o da 1� a penultima posi��o elegendo um n�mero para comparar 
				for(i=0; i<=n-1; i++){
					eleito = vet[i];
					menor = vet[i+1];
					pos = i + 1;
				
					//la�o com os numeros a direita do eleito, 
					//retornando o menor n�mero a direita e sua posi��o	
					for(j=i+1; j<=n; j++){
						if(vet[j] > menor){
							menor = vet[j];
							pos = j;
						}
					}
					
					//troca
					if(menor > eleito){
						vet[i] = vet[pos];
						vet[pos] = eleito;
					}
				}
				
				//imprimindo vetor ordenado
				printf("\nSelection sort decrescente:");
				for(i = 0; i <= n; i++){
					printf("  %i", vet[i]);
				}
			break;
			
			default:
				printf("\nValor invalido.");
		}
	}while(op != 0);
}
