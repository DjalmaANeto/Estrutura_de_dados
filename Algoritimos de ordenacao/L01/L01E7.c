//erro
#include <stdio.h>
#include <string.h>

#define n 2

typedef struct{
	int cfuncional;
	char nome[40];
	int salario;
	char data[40];
}funcionario;
funcionario f[n];

//quick sort
void troca(funcionario f[], int i, int j);
int particao(funcionario f[], int p, int r);
void quicksort(funcionario f[], int p, int r);

void main(){
	int i;
	
	//alimentando o vetor 
	for(i = 0; i <= n; i++){
		printf("\nEscreva o codigo funcional do funcionario %i: ", i);
		scanf("%i",&f[i].cfuncional);
		printf("Escreva o nome do funcionario %i: ", i);
		scanf("%s",&f[i].nome);
		printf("Escreva o salario do funcionario %i: ", i);
		scanf("%i",&f[i].salario);
		printf("Escreva a data de admissao do funcionario %i: ", i);
		scanf("%s",&f[i].data);
	}
	
	//imprimindo forma desordenada
	printf("\nForma desordenada: ");
	for(i = 0; i <= n; i++){
		printf("\nCodigo funcional do funcionario %i: %i", i, f[i].cfuncional);
		printf("\nNome do funcionario %i: %s", i, f[i].nome);
		printf("\nSalario do funcionario %i: %i", i, f[i].salario);
		printf("\nData de adimissao do funcionario %i: %s\n", i, f[i].data);
	}
	
	//ordenando de forma crescente pelo codigo funcional
	quicksort(f, 0, n);
	
	//imprimindo forma ordenada
	printf("\nForma ordenada: ");
	for(i = 0; i <= n; i++){
		printf("\nCodigo funcional do funcionario %i: %i", i, f[i].cfuncional);
		printf("\nNome do funcionario %i: %s", i, f[i].nome);
		printf("\nSalario do funcionario %i: %i", i, f[i].salario);
		printf("\nData de adimissao do funcionario %i: %s\n", i, f[i].data);
	}
	
}

//quick sort
void troca(funcionario f[], int i, int j)
{
	funcionario aux;
	
	aux = f[i];
	f[i] = f[j];
	f[j] = aux;
}

int particao(funcionario f[], int p, int r)
{
	int pivo, i, j;
	pivo = f[(p+r)/2].cfuncional;
	i = p-1;
	j = r+1;
	
	while(i < j){
		do{
			j = j - 1;
		}while(f[j].cfuncional > pivo);
		do{
			i = i + 1;
		}
		while(f[i].cfuncional<pivo);
		if(i < j) troca(f, i, j);
	}
	return j;
}

void quicksort(funcionario f[], int p, int r)
{
	int q;
	if(p < r){
		q = particao(f, p, r);
		quicksort(f, p, q);
		quicksort(f, q+1, r);
	}
}


