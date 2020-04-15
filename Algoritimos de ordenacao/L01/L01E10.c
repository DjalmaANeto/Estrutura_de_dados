#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 8000

//selection sort
void selectionSort(int vet[], int *trocas);

//merge sort
void intercala (int vet[], int inicio, int fim, int meio, int *trocas);
void merge(int vet[], int inicio, int fim, int *trocas);

//quick sort
void troca(int vet[], int i, int j, int *trocas);
int particao(int vet[], int p, int r, int *trocas);
void quicksort(int vet[], int p, int r, int *trocas);

void main(){
	int vet[n], i, trocas, *strtrocas;
	clock_t t;
	
	*strtrocas = &trocas;
	
	//preenchendo o vetor 
	for(i = 0; i <= n; i++){
		vet[i] = 0;
	}
	for(i = 0; i <= n; i++){
		vet[i] = rand();
	}
	
	//selection sort
	t = clock();//armazena tempo de inicio
	selectionSort(vet, strtrocas);
	t = clock() - t;//tempo final
	printf("\nTempo selection sort: %f milissegundos\ttrocas: %i", ((double)t)/(CLOCKS_PER_SEC/1000), trocas);
	trocas = 0;
	
	//merge sort
	t = clock();//armazena tempo de inicio
	merge(vet, 0, n, strtrocas);
	t = clock() - t;//tempo final
	printf("\nTempo merge sort: %f milissegundos\ttrocas: %i", ((double)t)/(CLOCKS_PER_SEC/1000), trocas);
	trocas = 0;
	
	//merge sort
	t = clock();//armazena tempo de inicio
	quicksort(vet, 0, n, strtrocas);
	t = clock() - t;//tempo final
	printf("\nTempo quick sort: %f milissegundos\ttrocas: %i", ((double)t)/(CLOCKS_PER_SEC/1000), trocas);
	trocas = 0;	
	
}

void selectionSort(int vet[], int *trocas){
	int i, j, eleito, pos, menor;
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
				trocas ++;
			}
		}
		
		//troca
		if(menor < eleito){
			vet[i] = vet[pos];
			vet[pos] = eleito;
			trocas++;
		}
	}
}

void intercala (int vet[], int inicio, int fim, int meio, int *trocas)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[n];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1; 
	poslivre = inicio;
	
	//"quebra" o vetor
	while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){
		if(vet[inicio_vetor1] <= vet[inicio_vetor2]){
			aux[poslivre] = vet[inicio_vetor1];
			inicio_vetor1 = inicio_vetor1 + 1;
		}else{
			aux[poslivre] = vet[inicio_vetor2];
			inicio_vetor2 = inicio_vetor2 + 1;
		}
		poslivre = poslivre + 1;
		trocas ++;
	}	
	
	//se ainda existirem numeros do primeiro vetor não intercalados
	for(i = inicio_vetor1; i <= meio; i++){
		aux[poslivre] = vet[i];
		poslivre = poslivre + 1;
		trocas ++;
	}
	
	//se ainda existirem numeros do segundo vetor não intercalados
	for(i = inicio_vetor2; i <= fim; i++){
		aux[poslivre] = vet[i];
		poslivre = poslivre + 1;
		trocas ++;
	}
	
	//retorna os numeros do vetor aux para vet 
	for(i = inicio; i<=fim; i++){
		vet[i] = aux[i];
	}
}

void merge(int vet[], int inicio, int fim, int *trocas)
{
	int meio;
	if(inicio < fim){
		meio = (inicio + fim)/2;
		//vetor 1 para intercalar
		merge(vet, inicio, meio, trocas);
		//vetor 2 para intercalar
		merge(vet, meio+1, fim, trocas);
		intercala(vet, inicio, fim, meio, trocas);
	}
	
}

void troca(int vet[], int i, int j, int *trocas)
{
	int aux;
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
	trocas ++;
}

int particao(int vet[], int p, int r, int *trocas)
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
		if(i < j) troca(vet, i, j, trocas);
	}
	return j;
}

void quicksort(int vet[], int p, int r, int *trocas)
{
	int q;
	if(p < r){
		q = particao(vet, p, r, trocas);
		quicksort(vet, p, q, trocas);
		quicksort(vet, q+1, r, trocas);
	}
}


