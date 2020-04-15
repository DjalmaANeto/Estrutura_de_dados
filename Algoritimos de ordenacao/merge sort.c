//merge sort 
//WORKING 
#include <stdio.h>

void intercala (int vet[], int inicio, int fim, int meio);
void merge(int vet[], int inicio, int fim);

void main()
{
	int vet[10];
	int i;
	//clrscr();
	
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
	merge(vet, 0, 9);
	
	//imprimindo forma ordenada
	for(i = 0; i < 9; i++){
		printf("%i, ", vet[i]);
	}
	printf("%i.\n",vet[9]);
}

void intercala (int vet[], int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[10];
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
