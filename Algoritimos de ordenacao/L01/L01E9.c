#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10000

void bubbleSort(int vet[]);
void insertionSort(int vet[]);
void troca(int vet[], int i, int j);
int particao(int vet[], int p, int r);
void quicksort(int vet[], int p, int r);

void main(){
	int vet[n], i;
	clock_t t;
	
	//preenchendo o vetor 
	for(i = 0; i <= n; i++){
		vet[i] = rand();
	}
		
	//imprimindo tempos de execução
	printf("Tempo para ordenar 10000 numeros: ");
	
	//buble sort
	t = clock();//armazena tempo de inicio
	bubbleSort(vet);
	t = clock() - t;//tempo final
	printf("\nTempo bubble sort: %f milissegundos.", ((double)t)/(CLOCKS_PER_SEC/1000));
	
	//preenchendo o vetor 
	for(i = 0; i <= n; i++){
		vet[i] = 0;
	}
	for(i = 0; i <= n; i++){
		vet[i] = rand();
	}
	
	//insertion sort
	t = clock();//armazena tempo de inicio
	insertionSort(vet);
	t = clock() - t;//tempo final
	printf("\nTempo insertion sort: %f milissegundos.", ((double)t)/(CLOCKS_PER_SEC/1000));
	
	//preenchendo o vetor 
	for(i = 0; i <= n; i++){
		vet[i] = 0;
	}
	for(i = 0; i <= n; i++){
		vet[i] = rand();
	}
	
	//quick sort
	t = clock();//armazena tempo de inicio
	quicksort(vet, 0, n);
	t = clock() - t;//tempo final
	printf("\nTempo quick sort: %f milissegundos.", ((double)t)/(CLOCKS_PER_SEC/1000));

}

void bubbleSort(int vet[]){
	int i, j, aux;	
	for(j=1; j<=n-1; j++){
		for(i=n-1; i>=j; i--){
			if(vet[i] < vet[i-1]){
				aux = vet[i];
				vet[i] = vet[i-1];
				vet[i-1] = aux;
			}
		}
	}
}

void insertionSort(int vet[]){
	int i, j, eleito;
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


