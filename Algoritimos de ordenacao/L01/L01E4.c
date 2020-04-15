#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//merge sort
void intercala (int vet[], int inicio, int fim, int meio);
void merge(int vet[], int inicio, int fim);

void main(){
	int vet1[20], vet2[20], vet3[40];
	int i;
	
	srand(time(NULL));
	
	//preenchendo os vetores com numeros aleatórios
	for(i = 0; i < 20; i++){
		vet1[i] = rand() % 20;
	}
	for(i = 0; i < 20; i++){
		vet2[i] = 21 + rand() % 20;
	}
	
	//imprimindo vetores aleatorios
	printf("Vet1: ");
	for(i = 0; i < 20; i++){
		printf("%i, ", vet1[i]);
	}
	printf("\n");
	printf("Vet2: ");
	for(i = 0; i < 20; i++){
		printf("%i, ", vet2[i]);
	}
	
	//somando os vetores vet1 e vet2 ao vet3
	for(i = 0; i < 20; i++){
		vet3[i] = vet1[i];
	}
	for(i = 0; i < 20; i++){
		vet3[i + 20] = vet2[i];
	}
	
	//imprime o vetor vet3
	printf("\n\nVet3: ");
	for(i = 0; i < 40; i++){
		printf("%i, ", vet3[i]);
	}
	
	//merge sort
	merge(vet3, 0, 40);
	
	//imprime o vetor vet3 de forma ordenadas
	printf("\n\nVet3: ");
	for(i = 0; i < 40; i++){
		printf("%i, ", vet3[i]);
	}
}

void intercala (int vet[], int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[40];
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
	}	
	
	//se ainda existirem numeros do primeiro vetor não intercalados
	for(i = inicio_vetor1; i <= meio; i++){
		aux[poslivre] = vet[i];
		poslivre = poslivre + 1;
	}
	
	//se ainda existirem numeros do segundo vetor não intercalados
	for(i = inicio_vetor2; i <= fim; i++){
		aux[poslivre] = vet[i];
		poslivre = poslivre + 1;
	}
	
	//retorna os numeros do vetor aux para vet 
	for(i = inicio; i<=fim; i++){
		vet[i] = aux[i];
	}
}

void merge(int vet[], int inicio, int fim)
{
	int meio;
	if(inicio < fim){
		meio = (inicio + fim)/2;
		//vetor 1 para intercalar
		merge(vet, inicio, meio);
		//vetor 2 para intercalar
		merge(vet, meio+1, fim);
		intercala(vet, inicio, fim, meio);
	}
	
}
