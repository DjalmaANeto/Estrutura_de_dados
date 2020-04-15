//quick sort
//WORKING

#include <stdio.h>

void troca(int vet[], int i, int j);
int particao(int vet[], int p, int r);
void quicksort(int vet[], int p, int r);

void main()
{
	int vet[10];
	int i;
	
	//carregando números no vetor
	for(i = 0; i <= 9; i++){
		printf("Escreva vet[%i]: ", i);
		scanf("%i",&vet[i]);
	}
	//imprimindo forma atual
	for(i = 0; i < 9; i++){
		printf("%i, ", vet[i]);
	}
	printf("%i.\n",vet[9]);
	
	//ordenando de forma crescente
	quicksort(vet, 0, 9);
	
	//imprimindo forma ordenada
	for(i = 0; i < 9; i++){
		printf("%i, ", vet[i]);
	}
	printf("%i.\n",vet[9]);
}

void troca(int vet[], int i, int j)
{
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particao(int vet[], int p, int r)
{
	int pivo, i, j;
	pivo = vet[(p+r)/2];
	i = p-1;
	j = r+1;
	
	while(i < j){
		do{
			j = j - 1;
		}while(vet[j] > pivo);
		do{
			i = i + 1;
		}
		while(vet[i]<pivo);
		if(i < j) troca(vet, i, j);
	}
	return j;
}

void quicksort(int vet[], int p, int r)
	{
		int q;
		if(p < r){
			q = particao(vet, p, r);
			quicksort(vet, p, q);
			quicksort(vet, q+1, r);
		}
	}


